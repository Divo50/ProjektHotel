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
#include <Registry.hpp>
#include <map>
#include <memory>
#include <system.hash.hpp>
#include <System.StrUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_Codec"
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
// Function to generate a deterministic salt based on the username using a hash
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
    return ""; // Default empty string if translation not found
}

void translateForm(TForm* Form, String Language, const std::map<String, std::map<String, String>>& translation) {
	for (int i = 0; i < Form->ComponentCount; i++) {
        String componentName = Form->Components[i]->Name;
		String translatedText = getTranslation(translation, componentName, Language);
        if (!translatedText.IsEmpty() && IsPublishedProp(Form->Components[i], "Caption")) {
			SetPropValue(Form->Components[i], "Caption", translatedText);
        }
	}
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

    UnicodeString username = EditKorisnik->Text;
    UnicodeString password = EditLozinka->Text;

	// Generate a salt by hashing the username
	UnicodeString sol = generirajSol(username);

	// Concatenate the password with the salt
	password += sol;

    std::unique_ptr<THashSHA2> sha2(new THashSHA2);
    UnicodeString hashedPassword = sha2->GetHashString(password, THashSHA2::SHA256);
    std::vector<Userdata> users;

    std::unique_ptr<TMemoryStream> userStream(new TMemoryStream);

    try
    {
        userStream->LoadFromFile("userdata.mff");
    }
    catch (...)
    {
        MyFileFormat header;
        userStream->Clear();
        userStream->Write(&header, sizeof(MyFileFormat));
        userStream->Position = 0;
    }

    MyFileFormat header;
    userStream->Position = 0;
    userStream->Read(&header, sizeof(MyFileFormat));

    if (String(header.name) != "MyFileFormat" || header.version != 1.0)
    {
        ShowMessage("Pogrešan format datoteke!");
        return;
    }

    users.clear();
    Userdata tmp;
    while (userStream->Position < userStream->Size)
    {
        userStream->Read(&tmp, sizeof(Userdata));
        users.push_back(tmp);
    }

    bool userFound = false;
    for (int i = 0; i < users.size(); i++)
    {
        if (EditKorisnik->Text == users[i].korisnik)
        {
            userFound = true;
            UnicodeString storedHash = users[i].lozinka;

            // Concatenate the entered password with the salt
			UnicodeString enteredPw = EditLozinka->Text + sol;
            UnicodeString enteredHash = sha2->GetHashString(enteredPw, THashSHA2::SHA256);

            if (enteredHash == storedHash)
            {
				ShowMessage("Točna šifra - Uspješan login!");
				FormZaposlenici->ShowModal();
                return;
            }
            else
			{
				MessageDlg("Pogrešna šifra!", mtWarning, TMsgDlgButtons() << mbOK, 0);
                return;
            }
        }
    }

    if (!userFound)
    {
        const wchar_t* korisnik = EditKorisnik->Text.c_str();
        const wchar_t* lozinka = hashedPassword.c_str();

        users.push_back(Userdata(korisnik, lozinka));

        userStream->Clear();
        userStream->Position = 0;
        userStream->Write(&header, sizeof(MyFileFormat));
        for (int i = 0; i < users.size(); i++)
        {
            userStream->Write(&users[i], sizeof(Userdata));
        }
        userStream->SaveToFile("userdata.mff");
        ShowMessage("Uspješna registracija!");
    }

	userStream->Clear();










	if (CheckBoxZapamti->Checked)
	{
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
		EditKorisnik->Text = "";
		EditLozinka->Text = "";
	}

	FormZaposlenici->ShowModal();
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
        if (CheckBoxZapamti->Checked)
        {
            Registry->WriteString("Korisnik", EditKorisnik->Text);
            Registry->WriteString("Lozinka", EditLozinka->Text);
            Registry->WriteBool("ZapamtiMe", CheckBoxZapamti->Checked);
        }
        else
        {
            Registry->DeleteValue("Korisnik");
            Registry->DeleteValue("Lozinka");
            Registry->WriteBool("ZapamtiMe", false);
        }
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

