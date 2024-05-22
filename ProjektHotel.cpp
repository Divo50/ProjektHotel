//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ProjektHotel.h"
#include "Unit2.h"
#include "XML.h"
#include "JSON.h"
#include "Database.h"
#include "CustomFormat.h"
#include "UnitTCPclient.h"
#include "UnitUDPclient.h"
#include "Zaposlenici.h"
#include <Registry.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	translation["LabelHotel"] =	{
		{
			{"EN", "Hotels"},
			{"HR", "Hoteli"}
		}
	};
	translation["LabelKorisnik"] =	{
		{
			{"EN", "Employee"},
			{"HR", "Zaposlenik"}
		}
	};
	translation["LabelLozinka"] =	{
		{
			{"EN", "Password"},
			{"HR", "Lozinka"}
		}
	};
	translation["ComboBox1"] =	{
		{
			{"EN", "Choose language"},
			{"HR", "Izaberite jezik"}
		}
	};

	translation["ButtonReg"] =	{
		{
			{"EN", "Register"},
			{"HR", "Registriraj se"}
		}
	};

	translation["CheckBoxPassword"] =	{
		{
			{"EN", "Show password"},
			{"HR", "Prikaži lozinku"}
		}
	};

	translation["CheckBoxZapamti"] =	{
		{
			{"EN", "Remember me"},
			{"HR", "Zapamti me"}
		}
	};

	translation["Button2"] =	{
		{
			{"EN", "Font size"},
			{"HR", "Veličina fonta"}
		}
	};

	translation["ButtonSetColorClick"] =	{
		{
			{"EN", "Background color"},
			{"HR", "Boja pozadine"}
		}
	};


};


//---------------------------------------------------------------------------

void translateForm(TForm* Form, String Language, const std::map<String, std::map<String, String>>& translation){
	for(int i = 0; i < Form->ComponentCount; i++) // iterate though all components on the form
		for(auto it_ComponentName = translation.begin(); it_ComponentName != translation.end(); it_ComponentName++)
			if(Form->Components[i]->Name == it_ComponentName->first) // find component by name
				for(auto it_Language = it_ComponentName->second.begin(); it_Language != it_ComponentName->second.end(); it_Language++)
					if(it_Language->first == Language) // find translation for the target language
						if(IsPublishedProp(Form->Components[i], "Caption"))
							SetPropValue(Form->Components[i], "Caption", it_Language->second);
}

//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
// Dobivanje odabranog jezika iz ComboBoxa
    String selectedLanguage = ComboBox1->Text;

    // Ažuriranje prikaza forme
    translateForm(this, selectedLanguage, translation);

    // Spremanje odabranog jezika u INI datoteku
    TIniFile* iniFile = new TIniFile("settings.ini");
    iniFile->WriteString("Language", "SelectedLanguage", selectedLanguage);
	delete iniFile;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonRegClick(TObject *Sender)
{
  // Postavljanje teksta dobrodošlice na Form2
    Form2->LabelDobrodosli->Caption = "Dobrodošao, " + EditKorisnik->Text + "!";

    // Provjera je li označen CheckBoxZapamti
    if (CheckBoxZapamti->Checked)
    {
        // Spremanje unesenih podataka u Windows registar
        TRegistry *Registry = new TRegistry;
        Registry->RootKey = HKEY_CURRENT_USER;
        UnicodeString KLJUC = "Software\\appHotel";
        if (Registry->OpenKey(KLJUC, true))
        {
            Registry->WriteString("Korisnik", EditKorisnik->Text);
            Registry->WriteString("Lozinka", EditLozinka->Text);
            Registry->CloseKey(); // Zatvori ključ
		}
        delete Registry; // Oslobađanje resursa
    }
    else
    {
        // Ako CheckBoxZapamti nije označen, očisti polja za unos
		EditKorisnik->Text = "";
        EditLozinka->Text = "";
    }

	// Prikazivanje Form2
	Form2->ShowModal();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	 HINSTANCE ResourceDll;
	 if((ResourceDll = LoadLibrary(L"mydll.dll"))==NULL) {
		 ShowMessage("Cannot load mydll.dll!");
		 return;
	 }
	 Image1->Picture->Bitmap->LoadFromResourceName((int)ResourceDll, "slika");
	 FreeLibrary(ResourceDll);


	 // Čitanje postavki iz INI datoteke za prozor
	TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
	Left = ini->ReadInteger("Main Window", "Left", 0);
	Top = ini->ReadInteger("Main Window", "Top", 0);
	Width = ini->ReadInteger("Main Window", "Width", 700);
	Height = ini->ReadInteger("Main Window", "Height", 500);

	// Čitanje postavki boje pozadine iz INI datoteke
	TColor backgroundColor = (TColor)ini->ReadInteger("Appearance", "BackgroundColor", clGreen);

	// Čitanje odabranog jezika iz INI datoteke
	String selectedLanguage = ini->ReadString("Language", "SelectedLanguage", "");

	delete ini; // Oslobađanje resursa

	// Postavljanje boje pozadine forme na temelju pročitane vrijednosti iz INI datoteke
	Color = backgroundColor;

	// Postavljanje odabranog jezika u ComboBox
	ComboBox1->ItemIndex = ComboBox1->Items->IndexOf(selectedLanguage);

	// Ako je odabrani jezik pronađen, ažuriramo prikaz forme
	if (selectedLanguage != "")
		translateForm(this, selectedLanguage, translation);

	// Čitanje unesenih podataka iz Windows registra
	TRegistry *Registry = new TRegistry;
	Registry->RootKey = HKEY_CURRENT_USER;
	UnicodeString KLJUC = "Software\\appHotel";
	if (Registry->OpenKey(KLJUC, false)) // Otvori ključ samo za čitanje
	{
		EditKorisnik->Text = Registry->ReadString("Korisnik");
		EditLozinka->Text = Registry->ReadString("Lozinka");
		Registry->CloseKey(); // Zatvori ključ
	}
	delete Registry; // Oslobađanje resursa


    // Čitanje veličine fonta iz INI datoteke
    TIniFile* fontIni = new TIniFile(GetCurrentDir() + "\\settings.ini");
    int fontSize = fontIni->ReadInteger("Font", "FontSize", Font->Size);
    delete fontIni;

    // Ažuriranje veličine fonta na cijeloj formi
    Font->Size = fontSize;

    // Odmah ažuriraj veličinu fonta na FormZaposlenici
    if (FormZaposlenici) {
        FormZaposlenici->RefreshSettings();
	}
}
 //------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	// Čuvanje postavki prozora u INI datoteku
	TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
	ini->WriteInteger("Main Window", "Left", Left);
	ini->WriteInteger("Main Window", "Top", Top);
	ini->WriteInteger("Main Window", "Width", Width);
	ini->WriteInteger("Main Window", "Height", Height);

	// Čuvanje postavki boje pozadine u INI datoteku
	ini->WriteInteger("Appearance", "BackgroundColor", Color);

	// Čuvanje postavki fonta u INI datoteku
	ini->WriteInteger("Font", "FontSize", Font->Size);
	ini->WriteInteger("Font", "FontColor", Font->Color);

	// Čuvanje odabranog jezika u INI datoteku
	String selectedLanguage = ComboBox1->Text;
	ini->WriteString("Language", "SelectedLanguage", selectedLanguage);

	delete ini; // Oslobađanje resursa

    // Čuvanje unesenih podataka u Windows registar
    TRegistry *Registry = new TRegistry;
    Registry->RootKey = HKEY_CURRENT_USER;
    UnicodeString KLJUC = "Software\\appHotel";
    if (Registry->OpenKey(KLJUC, true)) // Otvori ključ za pisanje
    {
        Registry->WriteString("Korisnik", EditKorisnik->Text);
        Registry->WriteString("Lozinka", EditLozinka->Text);
        Registry->CloseKey(); // Zatvori ključ
    }
    delete Registry; // Oslobađanje resursa
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBoxPasswordClick(TObject *Sender)
{
		EditLozinka->PasswordChar = CheckBoxPassword->Checked ? '\0' : '*';
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
		  EditLozinka->PasswordChar = CheckBoxPassword->Checked ? '\0' : '*';

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonSetColorClickClick(TObject *Sender)
{
// Prikaži dijalog za odabir boje
	if (ColorDialog1->Execute()) {
		// Prikaži odabranu boju u poruci
		ShowMessage("Boja je uspješno odabrana !");

		// Postavi odabranu boju kao boju pozadine forme
		Color = ColorDialog1->Color;

		// Spremi odabranu boju u INI datoteku
		TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
		ini->WriteInteger("Appearance", "BackgroundColor", ColorDialog1->Color);
		delete ini;

         // Odmah ažuriraj boju pozadine na FormZaposlenici
        if (FormZaposlenici) {
            FormZaposlenici->RefreshSettings();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	 FormZaposlenici->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	 // Čitanje unosa korisnika iz Edit polja
    int fontSize = StrToIntDef(EditFontSize->Text, 0);

    // Spremanje unosa u INI datoteku
    TIniFile* iniFile = new TIniFile("settings.ini");
    iniFile->WriteInteger("Font", "FontSize", fontSize);
    delete iniFile;

    // Ažuriranje veličine fonta na cijeloj formi
    Font->Size = fontSize;

    // Odmah ažuriraj veličinu fonta na FormZaposlenici
    if (FormZaposlenici) {
        FormZaposlenici->Font->Size = fontSize; // Ovdje postavljamo veličinu fonta na FormZaposlenici
	}
}
//---------------------------------------------------------------------------



