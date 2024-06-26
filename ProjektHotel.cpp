//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <vector>
#include "ProjektHotel.h"
#include "Unit2.h"
#include "XML.h"
#include "JSON.h"
#include "Database.h"
#include "CustomFormat.h"
#include "UnitTCPclient.h"
#include "UnitUDPclient.h"
#include "Zaposlenici.h"
#include "Download.h"
#include <Registry.hpp>
#include "Temperatura.h"
#include "Database.h"
#include <map>
#include <memory>
#include <system.hash.hpp>
#include <System.StrUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
 class MyFileFormat {
public:
	wchar_t name[15];
	float version;
	MyFileFormat() {
		wcsncpy(name, L"MyFileFormat", 15);
		version = 1.0;
	}
};
//---------------------------------------------------------------------------
class Userdata {
public:
wchar_t korisnik[15], lozinka[100];
	Userdata() {
		wcsncpy(korisnik, L"", 15);
		wcsncpy(lozinka, L"", 100);
	}
	Userdata(const wchar_t* _korisnik, const wchar_t* _lozinka) {
		wcsncpy(korisnik, _korisnik, 15);
		wcsncpy(lozinka, _lozinka, 100);
	}
};
//---------------------------------------------------------------------------
// generiranje soli
UnicodeString generirajSol(UnicodeString username) {
	std::unique_ptr<THashSHA2> sha2(new THashSHA2);
	return sha2->GetHashString(username, THashSHA2::SHA256);
}



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
	translation["Button7"] =	{
		{
			{"EN", "Temp. convert"},
			{"HR", "Pretvorba temp."}
		}
	};
	translation["GroupBox1"] =	{
		{
			{"EN", "Rooms i drinks"},
			{"HR", "Sobe i pića"}
		}
	};
	translation["GroupBox2"] =	{
		{
			{"EN", "Employees"},
			{"HR", "Zaposlenici"}
		}
	};

	translation["Button10"] =	{
		{
			{"EN", "Renting"},
			{"HR", "Iznajmljivanje"}
		}
	};

	translation["ButtonUDP"] =	{
		{
			{"EN", "Days off"},
			{"HR", "Godisnji odmor"}
		}
	};
	translation["ButtonTCP"] =	{
		{
			{"EN", "Water bill"},
			{"HR", "Račun za vodu"}
		}
	};

	translation["ButtonFont"] =	{
		{
			{"EN", "Font size"},
			{"HR", "Velicina fonta"}
		}
	};
	translation["ButtonCjenik"] =	{
		{
			{"EN", "Download menu"},
			{"HR", "Preuzmi cjenik"}
		}
	};
	translation["LabelZaposlenik"] =	{
		{
			{"EN", "User: "},
			{"HR", "Korisnik: "}
		}
	};
	translation["ButtonZ"] =	{
		{
			{"EN", "Hotel employees"},
			{"HR", "Zaposlenici hotela"}
		}
	};
	translation["Button2Pica"] =	{
		{
			{"EN", "Drinks"},
			{"HR", "Pića"}
		}
	};
	translation["Button1Sobe"] =	{
		{
			{"EN", "Rooms"},
			{"HR", "Sobe"}
		}
	};

	translation["Label1Temp"] =	{
		{
			{"EN", "Input the temperature in C°"},
			{"HR", "Unesi temperaturu u C°"}
		}
	};
	translation["Label2Temp"] =	{
		{
			{"EN", "Temperature in F°: "},
			{"HR", "Temperatura u F°: "}
		}
	};
	translation["Label3Temp"] =	{
		{
			{"EN", "Input the temperature in F°"},
			{"HR", "Unesi temperaturu u F°"}
		}
	};
	translation["Label4Temp"] =	{
		{
			{"EN", "Temperature in C°: "},
			{"HR", "Temperatura u C°: "}
		}
	};
	translation["Label5Temp"] =	{
		{
			{"EN", "Pool temperatures"},
			{"HR", "Temperature bazena"}
		}
	};
	translation["Button1Temp"] =	{
		{
			{"EN", "Calculate"},
			{"HR", "Izračunaj"}
		}
	};
	translation["Button2Temp"] =	{
		{
			{"EN", "Calculate"},
			{"HR", "Izračunaj"}
		}
	};


	translation["ButtonPreuzmi"] =	{
		{
			{"EN", "Download menu"},
			{"HR", "Preuzmi cjenik"}
		}
	};
	translation["ButtonPonisti"] =	{
		{
			{"EN", "Cancel"},
			{"HR", "Poništi"}
		}
	};
	translation["GroupBoxCjenik"] =	{
		{
			{"EN", "Download speed"},
			{"HR", "Brzina preuzimanja"}
		}
	};

	translation["GroupBoxTCP"] =	{
		{
			{"EN", "Water consumption"},
			{"HR", "Potrošnja vode"}
		}
	};

	translation["ButtonTCPRacun"] =	{
		{
			{"EN", "Calculate"},
			{"HR", "Izračunaj"}
		}
	};

	translation["Label1TCP"] =	{
		{
			{"EN", "Consumption for rooms(L)"},
			{"HR", "Potrošnja za sobe(L)"}
		}
	};
	translation["Label2TCP"] =	{
		{
			{"EN", "Consumption - kitchen(L)"},
			{"HR", "Potrošnja za kuhinju(L)"}
		}
	};
	translation["Label3TCP"] =	{
		{
			{"EN", "Consumption - restaurant(L)"},
			{"HR", "Potrošnja za restoran(L)"}
		}
	};
	translation["Label4TCP"] =	{
		{
			{"EN", "Consumption - Laundry room(L)"},
			{"HR", "Potrošnja za praonu(L)"}
		}
	};

	translation["MessageUkupniRacun"] =	{
		{
			{"EN", "Total water bill: "},
			{"HR", "Ukupni račun za vodu: "}
		}
	};

	translation["ButtonCurrency"] =	{
		{
			{"EN", "Currency"},
			{"HR", "Valute"}
		}
	};








};

//---------------------------------------------------------------------------
 std::map<String, std::map<String, String>> translation;
String getTranslation(const std::map<String, std::map<String, String>>& translation, const String& key, const String& language) {
	auto itKey = translation.find(key);
	if (itKey != translation.end()) {
		auto itLang = itKey->second.find(language);
		if (itLang != itKey->second.end()) {
			return itLang->second;
		}
	}
	return "";
}
void translateForm(TForm* Form, const String& Language, const std::map<String, std::map<String, String>>& translation) {
	for (int i = 0; i < Form->ComponentCount; i++) {
		TComponent* component = Form->Components[i];
		String componentName = component->Name;
		String translatedText = getTranslation(translation, componentName, Language);
		if (!translatedText.IsEmpty() && IsPublishedProp(component, "Caption")) {
			SetPropValue(component, "Caption", translatedText);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonRegClick(TObject *Sender)
{
    UnicodeString username = EditKorisnik->Text;
	UnicodeString password = EditLozinka->Text;
	// generiraj sol pomoću usernamea
	UnicodeString sol = generirajSol(username);
	// posoli lozinku sa soli
	password += sol;
	// inicijaliziraj objekt za heshanje
    std::unique_ptr<THashSHA2> sha2(new THashSHA2);
	UnicodeString hashedPassword = sha2->GetHashString(password, THashSHA2::SHA256);
    std::vector<Userdata> users;
    std::unique_ptr<TMemoryStream> userStream(new TMemoryStream);  // memorija
	try {
        userStream->LoadFromFile("userdata.mff");
    } catch (...) {
        MyFileFormat header;  // ako je greška, stvori novu datoteku
		userStream->Clear();
        userStream->Write(&header, sizeof(MyFileFormat));
		userStream->Position = 0;
    }
    MyFileFormat header;  // zaglavlje datoteke
    userStream->Position = 0;
	userStream->Read(&header, sizeof(MyFileFormat));
    if (String(header.name) != "MyFileFormat" || header.version != 1.0) {  // krivo zaglavlje stavi greška da je
		ShowMessage("Pogrešan format datoteke!");
		return;
	}
	users.clear();
	Userdata tmp;  // privr obj
	while (userStream->Position < userStream->Size) {
		userStream->Read(&tmp, sizeof(Userdata));
        users.push_back(tmp);
    }
    bool userFound = false;  // provjera postoji li vec korisnik za taj username
	for (int i = 0; i < users.size(); i++) {
        if (EditKorisnik->Text == users[i].korisnik) {
			userFound = true;
			UnicodeString storedHash = users[i].lozinka;  // provjeri lozinku ako je korisnik naden
            UnicodeString enteredPw = EditLozinka->Text + sol;  // heshanje
            UnicodeString enteredHash = sha2->GetHashString(enteredPw, THashSHA2::SHA256);
            if (enteredHash == storedHash) {  // provjera heshane lozinke sa spremljenom
                FormZaposlenici->ShowModal();
				return;
            } else {
                MessageDlg("Pogrešna šifra!", mtWarning, TMsgDlgButtons() << mbOK, 0);
				return;
			}
        }
    }
    if (!userFound) {  // nema korisnika, registriraj ga onda
        const wchar_t* korisnik = EditKorisnik->Text.c_str();
		const wchar_t* lozinka = hashedPassword.c_str();
        users.push_back(Userdata(korisnik, lozinka));
		userStream->Clear();
		userStream->Position = 0;
		userStream->Write(&header, sizeof(MyFileFormat));
		for (int i = 0; i < users.size(); i++) {
			userStream->Write(&users[i], sizeof(Userdata));
		}
		userStream->SaveToFile("userdata.mff");
		ShowMessage("Uspješna registracija!");
    }
	userStream->Clear();
	//spremi te podatke u registar
    TRegistry *Registry = new TRegistry;
	Registry->RootKey = HKEY_CURRENT_USER;
	UnicodeString KLJUC = "Software\\appHotel";
	if (Registry->OpenKey(KLJUC, true)) {
		try {
            if (CheckBoxZapamti->Checked) {
                Registry->WriteString("Korisnik", EditKorisnik->Text);
				Registry->WriteString("Lozinka", EditLozinka->Text);
				Registry->WriteBool("ZapamtiMe", true);
            } else {
				if (Registry->ValueExists("Korisnik")) {
                    Registry->DeleteValue("Korisnik");
				}
                if (Registry->ValueExists("Lozinka")) {
                    Registry->DeleteValue("Lozinka");
				}
				Registry->WriteBool("ZapamtiMe", false);
			}
        } catch (...) {
            ShowMessage("Greška pri spremanju podataka u registar!");
		}
		Registry->CloseKey();
	}
	delete Registry;
	FormZaposlenici->ShowModal();

}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 HINSTANCE ResourceDll;
    if ((ResourceDll = LoadLibrary(L"mydll.dll")) == NULL) {
        ShowMessage("Cannot load mydll.dll!");
        return;
    }
    Image1->Picture->Bitmap->LoadFromResourceName((int)ResourceDll, "slika");
    FreeLibrary(ResourceDll);
	// učitaj postavke prozora iz INI datoteke
    TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
    Left = ini->ReadInteger("Main Window", "Left", 0);
    Top = ini->ReadInteger("Main Window", "Top", 0);
    Width = ini->ReadInteger("Main Window", "Width", 700);
    Height = ini->ReadInteger("Main Window", "Height", 500);
	TColor backgroundColor = (TColor)ini->ReadInteger("Appearance", "BackgroundColor", clGreen);
	delete ini;  //obrisi taj ini objekat nakon koristenja
    Color = backgroundColor;
	translateForm(this, selectedLanguage, translation);
    ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
    selectedLanguage = ini->ReadString("Language", "SelectedLanguage", "HR");
    delete ini;  // Delete ini object after use
    TRegistry* Registry = new TRegistry(KEY_READ);
    Registry->RootKey = HKEY_CURRENT_USER;
    UnicodeString KLJUC = "Software\\appHotel";
    if (Registry->OpenKey(KLJUC, false)) {
        if (Registry->ValueExists("Korisnik")) {
            EditKorisnik->Text = Registry->ReadString("Korisnik");
        }
        if (Registry->ValueExists("Lozinka")) {
            EditLozinka->Text = Registry->ReadString("Lozinka");
            CheckBoxZapamti->Checked = true;
        }
        else {
            CheckBoxZapamti->Checked = false;
        }
        Registry->CloseKey();
    }
	delete Registry;
    ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
    int fontSize = ini->ReadInteger("Font", "FontSize", Font->Size);
	delete ini;
    Font->Size = fontSize;
	// refreshaj te postavke ako postoji FormZaposlenici
	if (FormZaposlenici) {
        FormZaposlenici->RefreshSettings();
	}

}
 //------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
 //zapamti kordinate prozora
	TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
	ini->WriteInteger("Main Window", "Left", Left);
	ini->WriteInteger("Main Window", "Top", Top);
	ini->WriteInteger("Main Window", "Width", Width);
	ini->WriteInteger("Main Window", "Height", Height);
	ini->WriteInteger("Appearance", "BackgroundColor", Color);
	ini->WriteInteger("Font", "FontSize", Font->Size);
    ini->WriteInteger("Font", "FontColor", Font->Color);
    delete ini;
	//zapamti jezik
	ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
    ini->WriteString("Language", "SelectedLanguage", selectedLanguage);
	delete ini;

    TRegistry *Registry = new TRegistry;
	Registry->RootKey = HKEY_CURRENT_USER;
    UnicodeString KLJUC = "Software\\appHotel";
	if (Registry->OpenKey(KLJUC, true)) { //otvori ključ za pisanje
		try {
			if (CheckBoxZapamti->Checked) {
				Registry->WriteString("Korisnik", EditKorisnik->Text);
                Registry->WriteString("Lozinka", EditLozinka->Text);
                Registry->WriteBool("ZapamtiMe", true);
			} else {
                if (Registry->ValueExists("Korisnik")) {
					Registry->DeleteValue("Korisnik");
				}
                if (Registry->ValueExists("Lozinka")) {
					Registry->DeleteValue("Lozinka");
                }
                Registry->WriteBool("ZapamtiMe", false);
            }
        } catch (...) {
            ShowMessage("Greška pri spremanju podataka u registar!");
        }
		Registry->CloseKey(); //kljuc se zatvori
	}
	delete Registry; // oslobode se resursi

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
	// ucitaj jezik iz ini filea
    TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
    String selectedLanguage = ini->ReadString("Language", "SelectedLanguage", "EN");
    delete ini;
	// poziv funkcije za prijevod jezika
    translateForm(this, selectedLanguage, translation);
    translateForm(FormZaposlenici, selectedLanguage, translation);
    translateForm(FormTemperatura, selectedLanguage, translation);
    translateForm(FormDownload, selectedLanguage, translation);
    translateForm(FormXML, selectedLanguage, translation);
	translateForm(FormTCPclient, selectedLanguage, translation);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonSetColorClickClick(TObject *Sender)
{
// otvori dijalog za boju
	if (ColorDialog1->Execute()) {
		ShowMessage("Boja je uspješno odabrana !");
		//tu odabranu boju postavi
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
void __fastcall TForm1::ButtonFontClick(TObject *Sender)
{
    int fontSize = StrToIntDef(EditFontSize->Text, 0);

    TIniFile* iniFile = new TIniFile("settings.ini");
    iniFile->WriteInteger("Font", "FontSize", fontSize);
    delete iniFile;

	Font->Size = fontSize;

    if (FormZaposlenici) {
		FormZaposlenici->Font->Size = fontSize;
	}
}
//---------------------------------------------------------------------------
 void __fastcall TForm1::BENGClick(TObject *Sender)
{

	 translateForm(this, "EN", translation);
	selectedLanguage = "EN"; // Postavi jezik na engleski
	TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
	ini->WriteString("Language", "SelectedLanguage", selectedLanguage);
	delete ini;
	 translateForm(this,"EN", translation);
	 translateForm(FormZaposlenici, "EN", translation);
	 translateForm(FormTemperatura, "EN", translation);
	 translateForm(FormDownload, "EN", translation);
	 translateForm(FormXML, "EN", translation);
	 translateForm(FormTCPclient, "EN", translation);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::BHRVClick(TObject *Sender)
{
	   translateForm(this, "HR", translation);
	selectedLanguage = "HR"; // Postavi jezik na hrvatski
	TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
	ini->WriteString("Language", "SelectedLanguage", selectedLanguage);
	delete ini;

	 translateForm(this,"HR", translation);
	 translateForm(FormZaposlenici, "HR", translation);
	 translateForm(FormTemperatura, "HR", translation);
	 translateForm(FormDownload, "HR", translation);
	 translateForm(FormXML, "HR", translation);
	 translateForm(FormTCPclient, "HR", translation);

}
//---------------------------------------------------------------------------



