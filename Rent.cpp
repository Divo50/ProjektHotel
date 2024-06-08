//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <XMLDoc.hpp>
#include "Rent.h"
#include <System.IOUtils.hpp> // Dodano ukljuèivanje za TFile
#include <system.json.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDllForm1 *DllForm1;
//---------------------------------------------------------------------------
__fastcall TDllForm1::TDllForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
class KalkulatorCijene {
private:
	double cijenaOdrasli;
	double cijenaDjeca;
	double cijenaDan;
    double popust; // Novi atribut za popust

public:
	// Konstruktor za inicijalizaciju cijena po biciklu i cijene po danu
	KalkulatorCijene() {
		// Zadane cijene bicikala i cijene po danu
		cijenaOdrasli = 7.0;
		cijenaDjeca = 4.0;
		cijenaDan = 6.0; // Primjer cijene po danu
        popust = 0.0; // Poèetni popust je 0
	}

	// Metoda za postavljanje popusta
	void postaviPopust(double noviPopust) {
		popust = noviPopust;
	}

	// Metoda koja raèuna ukupnu cijenu iznajmljivanja bicikala
	double izracunajUkupnuCijenu(int brojOdraslih, int brojDjece, int brojDana) {
		double ukupnaCijenaOdraslih = brojOdraslih * cijenaOdrasli;
		double ukupnaCijenaDjece = brojDjece * cijenaDjeca;
		double ukupnaCijenaDana = (ukupnaCijenaOdraslih + ukupnaCijenaDjece) * brojDana;
		double ukupnaCijenaSaCijenomDana = ukupnaCijenaDana + (cijenaDan * brojDana);
		// Primjena popusta na ukupnu cijenu
		double ukupnaCijenaSPopustom = ukupnaCijenaSaCijenomDana - (ukupnaCijenaSaCijenomDana * (popust / 100.0));
		return ukupnaCijenaSPopustom;
	}
};

void __fastcall TDllForm1::ButtonRacunClick(TObject *Sender)
{
KalkulatorCijene kalkulator;

	int brojOdraslih = StrToInt(EditOdrasli->Text); // Broj odraslih iz edit polja
	int brojDjece = StrToInt(EditDjeca->Text); // Broj djece iz edit polja
	int brojDana = StrToInt(EditDani->Text); // Broj dana iz edit polja

	double popust = 0.0; // Poèetni popust je 0
	bool koristenPopust = false; // Inicijalno postavljamo da popust nije korišten

	// Provjera je li unesen popust
	if (!EditPopust->Text.IsEmpty()) {
		popust = StrToFloat(EditPopust->Text); // Uneseni popust
		koristenPopust = true; // Postavljamo da je popust korišten
	}

	// Postavljanje popusta
	kalkulator.postaviPopust(popust);

	double ukupnaCijena = kalkulator.izracunajUkupnuCijenu(brojOdraslih, brojDjece, brojDana);

 // Kreiranje poruke
	UnicodeString poruka = "Ukupna cijena iznajmljivanja bicikala: " + FloatToStr(ukupnaCijena) + " EUR";

	// Dodavanje informacije o popustu ako je bio korišten
	if (koristenPopust) {
		poruka += "\nPopust: " + FloatToStr(popust) + "%";
	}

	// Prikazivanje rezultata
	ShowMessage(poruka);
}
//---------------------------------------------------------------------------

  class Automobil {
private:
	String marka;
	String gorivo;
	String mjenjac;
	String model;
	double cijenaDan;

public:
	Automobil(String marka, String gorivo, String mjenjac, double cijenaDan, String model) {
		this->marka = marka;
		this->gorivo = gorivo;
		this->mjenjac = mjenjac;
		this->cijenaDan = cijenaDan;
		this->model = model;
	}

	String getMarka() {
		return marka;
	}

	String getGorivo() {
		return gorivo;
	}

	String getMjenjac() {
		return mjenjac;
	}

	double getCijenaDan() {
		return cijenaDan;
	}

	String getModel() {
		return model;
	}


};

class KalkulatorAuto {
private:
	double popust;

public:
	KalkulatorAuto() {
		popust = 0.0;
	}

	void postaviPopust(double noviPopust) {
		popust = noviPopust;
	}

	double izracunajUkupnuCijenu(double cijenaDan, int brojDana) {
		double ukupnaCijenaSaCijenomDana = cijenaDan * brojDana;
		double ukupnaCijenaSPopustom = ukupnaCijenaSaCijenomDana - (ukupnaCijenaSaCijenomDana * (popust / 100.0));
		return ukupnaCijenaSPopustom;
	}
};





Automobil* TDllForm1::pronadjiAutomobil(String marka, String gorivo, String mjenjac, String model)
{
    TStringList *jsonLines = new TStringList;
    jsonLines->LoadFromFile("auti.json");
    TJSONObject *jsonObject = static_cast<TJSONObject*>(TJSONObject::ParseJSONValue(jsonLines->Text));
    TJSONArray *jsonArray = static_cast<TJSONArray*>(jsonObject->GetValue("automobili"));

    if (!jsonArray)
    {
		ShowMessage("Greška: Nema dostupnih automobila.");
        return NULL;
    }

    for (int i = 0; i < jsonArray->Count; i++)
	{
        TJSONObject *jsonAutomobil = static_cast<TJSONObject*>(jsonArray->Items[i]);
        if (!jsonAutomobil)
        {
            ShowMessage("Greška: Neuspješno uèitavanje automobila iz JSON-a.");
            continue;
        }

        String jsonMarka = jsonAutomobil->GetValue("marka")->Value().Trim().LowerCase();
        String jsonGorivo = jsonAutomobil->GetValue("gorivo")->Value().Trim().LowerCase();
        String jsonMjenjac = jsonAutomobil->GetValue("mjenjac")->Value().Trim().LowerCase();
        String jsonModel = jsonAutomobil->GetValue("model")->Value().Trim().LowerCase();
        bool dostupnost = jsonAutomobil->GetValue("dostupnost")->Value().Trim().LowerCase() == "true";

        if (jsonMarka == marka.Trim().LowerCase() && jsonGorivo == gorivo.Trim().LowerCase() && jsonMjenjac == mjenjac.Trim().LowerCase() && jsonModel == model.Trim().LowerCase())
        {
            if (!dostupnost)
            {
                ShowMessage("Automobil je pronaðen, ali je trenutno rezerviran.");
                return NULL;
            }
            return new Automobil(jsonMarka, jsonGorivo, jsonMjenjac, jsonAutomobil->GetValue("cijena_dana")->Value().ToDouble(), jsonModel);
        }
    }

    // Nije pronaðen odgovarajuæi automobil
    ShowMessage("Nije pronaðen automobil s odabranim karakteristikama.");
    return NULL;
}


void __fastcall TDllForm1::ButtonProvjeraClick(TObject *Sender)
{



    // Dohvati odabrane vrijednosti iz ComboBox kontrola
    String marka = ComboBoxMarka->Text;
    String gorivo = ComboBoxGorivo->Text;
    String mjenjac = ComboBoxMjenjac->Text;
    String model = ComboBoxModel->Text;

    pronadeniAutomobil = pronadjiAutomobil(marka, gorivo, mjenjac, model);

    if (pronadeniAutomobil != NULL && pronadeniAutomobil->getMarka() != "")
    {
        // Postoji automobil
        String model = UpperCase(pronadeniAutomobil->getModel());

        // Prvo slovo marke postavljamo na veliko
        String prvoSlovoMarka = marka.SubString(1, 1).UpperCase();
        String ostatakMarke = marka.SubString(2, marka.Length());
        marka = prvoSlovoMarka + ostatakMarke;

        // Dohvati broj dana iz Edit kontrola
        int brojDana = StrToIntDef(EditBrojDana->Text, 0);

        // Dohvati cijenu dana iz objekta automobila
        double cijenaDan = pronadeniAutomobil->getCijenaDan();

        // Izraèunaj ukupnu cijenu bez popusta
        double ukupnaCijenaBezPopusta = cijenaDan * brojDana;

        // Dohvati popust iz Edit kontrola
        double popust = StrToFloatDef(PopustEdit->Text, 0.0);

        // Kreiraj poruku
        UnicodeString poruka = "Automobil je dostupan.\n\nVaš automobil je:\nMarka: " + marka + "\nModel: " + model + "\nMjenjaè: " + mjenjac + "\nGorivo: " + pronadeniAutomobil->getGorivo() + "\nCijena dana: " + FloatToStr(cijenaDan) + " EUR\n\nIzraèun vašeg najma je:\nBez popusta: " + FloatToStr(ukupnaCijenaBezPopusta) + " EUR";

        // Provjeri je li unesen popust
        if (popust > 0)
        {
            // Postavi popust u kalkulatoru
            KalkulatorAuto kalkulator;
            kalkulator.postaviPopust(popust);

            // Izraèunaj ukupnu cijenu s popustom
            double ukupnaCijenaSPopustom = kalkulator.izracunajUkupnuCijenu(cijenaDan, brojDana);

            // Dodaj informaciju o popustu u poruku
            poruka += "\nSa popustom (" + FloatToStr(popust) + "%): " + FloatToStr(ukupnaCijenaSPopustom) + " EUR";
        }

        // Prikaži poruku
        ShowMessage(poruka);
	}



}
void __fastcall TDllForm1::ButtonRezervirajClick(TObject *Sender)
{
  if (pronadeniAutomobil == NULL)
    {
        ShowMessage("Prvo provjerite dostupnost automobila.");
        return;
    }

    // Uèitavanje JSON datoteke
    TStringList *jsonLines = new TStringList;
    jsonLines->LoadFromFile("auti.json");
    TJSONObject *jsonObject = static_cast<TJSONObject*>(TJSONObject::ParseJSONValue(jsonLines->Text));
    TJSONArray *jsonArray = static_cast<TJSONArray*>(jsonObject->GetValue("automobili"));

    if (!jsonArray)
    {
        ShowMessage("Greška: Nema dostupnih automobila.");
        delete jsonLines;
        delete jsonObject;
        return;
    }

    bool automobilPronaðen = false;

    // Ažuriranje dostupnosti automobila u JSON datoteci
    for (int i = 0; i < jsonArray->Count; i++)
    {
        TJSONObject *jsonAutomobil = static_cast<TJSONObject*>(jsonArray->Items[i]);
        if (!jsonAutomobil)
        {
            ShowMessage("Greška: Neuspješno uèitavanje automobila iz JSON-a.");
            continue;
        }

        String jsonMarka = jsonAutomobil->GetValue("marka")->Value().Trim().LowerCase();
        String jsonGorivo = jsonAutomobil->GetValue("gorivo")->Value().Trim().LowerCase();
        String jsonMjenjac = jsonAutomobil->GetValue("mjenjac")->Value().Trim().LowerCase();
        String jsonModel = jsonAutomobil->GetValue("model")->Value().Trim().LowerCase();

        if (jsonMarka == pronadeniAutomobil->getMarka().Trim().LowerCase() &&
            jsonGorivo == pronadeniAutomobil->getGorivo().Trim().LowerCase() &&
            jsonMjenjac == pronadeniAutomobil->getMjenjac().Trim().LowerCase() &&
            jsonModel == pronadeniAutomobil->getModel().Trim().LowerCase())
        {
            // Automobil je pronaðen, ažuriramo dostupnost
            jsonAutomobil->Get("dostupnost")->JsonValue = new TJSONString("false");
            automobilPronaðen = true;
            break;
        }
    }

    if (automobilPronaðen)
    {
        // Spremanje ažurirane JSON datoteke
        jsonLines->Text = jsonObject->ToString();
        jsonLines->SaveToFile("auti.json");

        ShowMessage("Automobil je uspješno rezerviran.");
    }
    else
    {
        ShowMessage("Automobil nije pronaðen.");
    }

    // Oslobaðanje resursa
    delete jsonLines;
	delete jsonObject;
}
//---------------------------------------------------------------------------

void __fastcall TDllForm1::ComboBoxMarkaChange(TObject *Sender)
{
	  // Dohvati odabranu marku
	String odabranaMarka = ComboBoxMarka->Text.Trim().LowerCase();

	// Uèitavanje JSON datoteke
	TStringList *jsonLines = new TStringList;
	jsonLines->LoadFromFile("auti.json");
	TJSONObject *jsonObject = static_cast<TJSONObject*>(TJSONObject::ParseJSONValue(jsonLines->Text));
	TJSONArray *jsonArray = static_cast<TJSONArray*>(jsonObject->GetValue("automobili"));

    if (!jsonArray) {
        ShowMessage("Greška: Nema dostupnih automobila.");
        delete jsonLines;
        delete jsonObject;
        return;
    }

    // Oèisti ComboBoxModel
    ComboBoxModel->Clear();

    // Pronaði sve modele za odabranu marku i dodaj ih u ComboBoxModel
    for (int i = 0; i < jsonArray->Count; i++) {
        TJSONObject *jsonAutomobil = static_cast<TJSONObject*>(jsonArray->Items[i]);
        if (!jsonAutomobil) {
            continue;
        }

        String jsonMarka = jsonAutomobil->GetValue("marka")->Value().Trim().LowerCase();
        String jsonModel = jsonAutomobil->GetValue("model")->Value().Trim();

        if (jsonMarka == odabranaMarka) {
            ComboBoxModel->Items->Add(jsonModel);
        }
	}

    // Oslobaðanje resursa
    delete jsonLines;
	delete jsonObject;
}
//---------------------------------------------------------------------------

void __fastcall TDllForm1::ButtonVratiClick(TObject *Sender)
{
  // Dohvati odabrane vrijednosti iz ComboBox kontrola
    String marka = ComboBoxMarka->Text;
    String model = ComboBoxModel->Text;
    String gorivo = ComboBoxGorivo->Text;
    String mjenjac = ComboBoxMjenjac->Text;

    // Uèitavanje JSON datoteke
    TStringList *jsonLines = new TStringList;
    jsonLines->LoadFromFile("auti.json");
    TJSONObject *jsonObject = static_cast<TJSONObject*>(TJSONObject::ParseJSONValue(jsonLines->Text));
    TJSONArray *jsonArray = static_cast<TJSONArray*>(jsonObject->GetValue("automobili"));

    if (!jsonArray)
    {
        ShowMessage("Greška: Nema dostupnih automobila.");
        delete jsonLines;
        delete jsonObject;
        return;
    }

    bool automobilPronaðen = false;

    // Ažuriranje dostupnosti automobila u JSON datoteci
    for (int i = 0; i < jsonArray->Count; i++)
    {
        TJSONObject *jsonAutomobil = static_cast<TJSONObject*>(jsonArray->Items[i]);
        if (!jsonAutomobil)
        {
            ShowMessage("Greška: Neuspješno uèitavanje automobila iz JSON-a.");
            continue;
        }

        String jsonMarka = jsonAutomobil->GetValue("marka")->Value().Trim().LowerCase();
        String jsonGorivo = jsonAutomobil->GetValue("gorivo")->Value().Trim().LowerCase();
        String jsonMjenjac = jsonAutomobil->GetValue("mjenjac")->Value().Trim().LowerCase();
        String jsonModel = jsonAutomobil->GetValue("model")->Value().Trim().LowerCase();

        if (jsonMarka == marka.Trim().LowerCase() && jsonGorivo == gorivo.Trim().LowerCase() && jsonMjenjac == mjenjac.Trim().LowerCase() && jsonModel == model.Trim().LowerCase())
        {
            // Automobil je pronaðen, ažuriramo dostupnost
            jsonAutomobil->Get("dostupnost")->JsonValue = new TJSONString("true");
            automobilPronaðen = true;
            break;
        }
    }

    if (automobilPronaðen)
    {
        // Spremanje ažurirane JSON datoteke
        jsonLines->Text = jsonObject->ToString();
        jsonLines->SaveToFile("auti.json");

        ShowMessage("Automobil je uspješno vraæen.");
    }
    else
    {
        ShowMessage("Automobil nije pronaðen.");
    }

    // Oslobaðanje resursa
    delete jsonLines;
	delete jsonObject;
}
//---------------------------------------------------------------------------

