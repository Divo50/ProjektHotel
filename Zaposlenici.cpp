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
#include "tempconvert.h"
#include "Temperatura.h"
#include "Currency.h"
#include "Download.h"
#include <map>
#include <memory>
#include "C:\Users\Danko\Desktop\NTP\hoteli\ProjektHotel-main\DLL\Rent.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormZaposlenici *FormZaposlenici;
//---------------------------------------------------------------------------
__fastcall TFormZaposlenici::TFormZaposlenici(TComponent* Owner)
	: TForm(Owner)
{
	ApplySettings();

		prijevod["LabelHotel"] =	{
		{
			{"EN", "Hotels"},
			{"HR", "Hoteli"}
		}
	};
	prijevod["LabelKorisnik"] =	{
		{
			{"EN", "Employee"},
			{"HR", "Zaposlenik"}
		}
	};
	prijevod["LabelLozinka"] =	{
		{
			{"EN", "Password"},
			{"HR", "Lozinka"}
		}
	};
	prijevod["ComboBox1"] =	{
		{
			{"EN", "Choose language"},
			{"HR", "Izaberite jezik"}
		}
	};

	prijevod["ButtonReg"] =	{
		{
			{"EN", "Register"},
			{"HR", "Registriraj se"}
		}
	};

	prijevod["CheckBoxPassword"] =	{
		{
			{"EN", "Show password"},
			{"HR", "Prikaži lozinku"}
		}
	};

	prijevod["CheckBoxZapamti"] =	{
		{
			{"EN", "Remember me"},
			{"HR", "Zapamti me"}
		}
	};

	prijevod["Button2"] =	{
		{
			{"EN", "Font size"},
			{"HR", "Velièina fonta"}
		}
	};

	prijevod["ButtonSetColorClick"] =	{
		{
			{"EN", "Background color"},
			{"HR", "Boja pozadine"}
		}
	};

	prijevod["Button7"] =	{
		{
			{"EN", "Temp. convert"},
			{"HR", "Pretvorba temp."}
		}
	};

	prijevod["GroupBox1"] =	{
		{
			{"EN", "Rooms i drinks"},
			{"HR", "Sobe i piæa"}
		}
	};

	prijevod["GroupBox2"] =	{
		{
			{"EN", "Employees"},
			{"HR", "Zaposlenici"}
		}
	};



	prijevod["Button10"] =	{
		{
			{"EN", "Renting"},
			{"HR", "Iznajmljivanje"}
		}
	};


	prijevod["ButtonUDP"] =	{
		{
			{"EN", "Days off"},
			{"HR", "Godisnji odmor"}
		}
	};

	prijevod["ButtonTCP"] =	{
		{
			{"EN", "Water bill"},
			{"HR", "Raèun za vodu"}
		}
	};



	prijevod["ButtonFont"] =	{
		{
			{"EN", "Font size"},
			{"HR", "Velicina fonta"}
		}
	};

	prijevod["ButtonCjenik"] =	{
		{
			{"EN", "Download menu"},
			{"HR", "Preuzmi cjenik"}
		}
	};

	prijevod["LabelZaposlenik"] =	{
		{
			{"EN", "User: "},
			{"HR", "Korisnik: "}
		}
	};

	prijevod["ButtonZ"] =	{
		{
			{"EN", "Hotel employees"},
			{"HR", "Zaposlenici hotela"}
		}
	};

	prijevod["Button2Pica"] =	{
		{
			{"EN", "Drinks"},
			{"HR", "Piæa"}
		}
	};

	prijevod["Button1Sobe"] =	{
		{
			{"EN", "Rooms"},
			{"HR", "Sobe"}
		}
	};


	prijevod["Label1Temp"] =	{
		{
			{"EN", "Input the temperature in C°"},
			{"HR", "Unesi temperaturu u C°"}
		}
	};

	prijevod["Label2Temp"] =	{
		{
			{"EN", "Temperature in F°: "},
			{"HR", "Temperatura u F°: "}
		}
	};

	prijevod["Label3Temp"] =	{
		{
			{"EN", "Input the temperature in F°"},
			{"HR", "Unesi temperaturu u F°"}
		}
	};

	prijevod["Label4Temp"] =	{
		{
			{"EN", "Temperature in C°: "},
			{"HR", "Temperatura u C°: "}
		}
	};

	prijevod["Label5Temp"] =	{
		{
			{"EN", "Pool temperatures"},
			{"HR", "Temperature bazena"}
		}
	};

	prijevod["Button1Temp"] =	{
		{
			{"EN", "Calculate"},
			{"HR", "Izraèunaj"}
		}
	};

	prijevod["Button2Temp"] =	{
		{
			{"EN", "Calculate"},
			{"HR", "Izraèunaj"}
		}
	};




	prijevod["ButtonPreuzmi"] =	{
		{
			{"EN", "Download menu"},
			{"HR", "Preuzmi cjenik"}
		}
	};

	prijevod["ButtonPonisti"] =	{
		{
			{"EN", "Cancel"},
			{"HR", "Poništi"}
		}
	};

	prijevod["GroupBoxCjenik"] =	{
		{
			{"EN", "Download speed"},
			{"HR", "Brzina preuzimanja"}
		}
	};



	prijevod["GroupBoxTCP"] =	{
		{
			{"EN", "Water consumption"},
			{"HR", "Potrošnja vode"}
		}
	};


	prijevod["ButtonTCPRacun"] =	{
		{
			{"EN", "Calculate"},
			{"HR", "Izraèunaj"}
		}
	};


	prijevod["Label1TCP"] =	{
		{
			{"EN", "Consumption for rooms(L)"},
			{"HR", "Potrošnja za sobe(L)"}
		}
	};

	prijevod["Label2TCP"] =	{
		{
			{"EN", "Consumption - kitchen(L)"},
			{"HR", "Potrošnja za kuhinju(L)"}
		}
	};

	prijevod["Label3TCP"] =	{
		{
			{"EN", "Consumption - restaurant(L)"},
			{"HR", "Potrošnja za restoran(L)"}
		}
	};

	prijevod["Label4TCP"] =	{
		{
			{"EN", "Consumption - Laundry room(L)"},
			{"HR", "Potrošnja za praonu(L)"}
		}
	};


	prijevod["MessageUkupniRacun"] =	{
		{
			{"EN", "Total water bill: "},
			{"HR", "Ukupni raèun za vodu: "}
		}
	};

	prijevod["ButtonCurrency"] =	{
		{
			{"EN", "Currency"},
			{"HR", "Valute"}
		}
	};


}
//---------------------------------------------------------------------------
 std::map<String, std::map<String, String>> prijevod;

String getprijevod(const std::map<String, std::map<String, String>>& prijevod, const String& key, const String& language) {
	auto itKey = prijevod.find(key);
	if (itKey != prijevod.end()) {
		auto itLang = itKey->second.find(language);
		if (itLang != itKey->second.end()) {
			return itLang->second;
		}
	}
	return "";
}
void translateForm(TForm* Form, const String& Language, const std::map<String, std::map<String, String>>& prijevod) {
	for (int i = 0; i < Form->ComponentCount; i++) {
		TComponent* component = Form->Components[i];
		String componentName = component->Name;
		String translatedText = getprijevod(prijevod, componentName, Language);
		if (!translatedText.IsEmpty() && IsPublishedProp(component, "Caption")) {
			SetPropValue(component, "Caption", translatedText);
		}
	}
}




void __fastcall TFormZaposlenici::Button1SobeClick(TObject *Sender)
{
		FormXML->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFormZaposlenici::Button2PicaClick(TObject *Sender)
{
	   FormJSON->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFormZaposlenici::ButtonZClick(TObject *Sender)
{
              DBForm->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFormZaposlenici::ButtonTCPClick(TObject *Sender)
{
           FormTCPclient->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFormZaposlenici::ButtonUDPClick(TObject *Sender)
{
         FormUDPClient->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFormZaposlenici::Button7Click(TObject *Sender)
{
		   FormTemperatura->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFormZaposlenici::FormCreate(TObject *Sender)
{
	 ApplySettings();

}
void __fastcall TFormZaposlenici::ButtonCurrencyClick(TObject *Sender)
{
		   FormCur->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormZaposlenici::ButtonCjenikClick(TObject *Sender)
{
		   FormDownload->ShowModal();
}
//---------------------------------------------------------------------------
void TFormZaposlenici::ApplySettings()
{
 TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");

	// primjeni boju pozadine
	TColor backgroundColor = (TColor)ini->ReadInteger("Appearance", "BackgroundColor", clGreen);
	Color = backgroundColor;

	// primjeni velièinu fonta
	int fontSize = ini->ReadInteger("Font", "FontSize", Font->Size);
	Font->Size = fontSize;

	// boja fonta, ne radi, nebitno
	TColor fontColor = (TColor)ini->ReadInteger("Font", "FontColor", Font->Color);
	Font->Color = fontColor;

	delete ini;
}
//---------------------------------------------------------------------------
void TFormZaposlenici::RefreshSettings()
{
	 ApplySettings();

	TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
	int fontSize = ini->ReadInteger("Font", "FontSize", Font->Size);
	delete ini;

	Font->Size = fontSize;

}
void __fastcall TFormZaposlenici::Button10Click(TObject *Sender)
{
	 TDllForm1* dllform = new TDllForm1(this);
	if(dllform->ShowModal() == mrClose)

	delete dllform;
}
//---------------------------------------------------------------------------


void __fastcall TFormZaposlenici::FormShow(TObject *Sender)
{


  LabelZaposlenik->Caption = LabelZaposlenik->Caption + Form1->EditKorisnik->Text;

}
//---------------------------------------------------------------------------

void __fastcall TFormZaposlenici::BHRVClick(TObject *Sender)
{
        translateForm(this, "HR", prijevod);
	selectedLanguage = "HR"; // Postavi jezik na hrvatski
	TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
	ini->WriteString("Language", "SelectedLanguage", selectedLanguage);
	delete ini;


	 translateForm(this,"HR", prijevod);
	 translateForm(FormZaposlenici, "HR", prijevod);
	 translateForm(FormTemperatura, "HR", prijevod);
	 translateForm(FormDownload, "HR", prijevod);
	 translateForm(FormXML, "HR", prijevod);
	 translateForm(FormTCPclient, "HR", prijevod);
	 translateForm(Form1, "HR", prijevod);

}
//---------------------------------------------------------------------------

void __fastcall TFormZaposlenici::BENGClick(TObject *Sender)
{
		 translateForm(this, "EN", prijevod);
	selectedLanguage = "EN"; // Postavi jezik na engleski
	TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
	ini->WriteString("Language", "SelectedLanguage", selectedLanguage);
	delete ini;

	 translateForm(this,"EN", prijevod);
	 translateForm(FormZaposlenici, "EN", prijevod);
	 translateForm(FormTemperatura, "EN", prijevod);
	 translateForm(FormDownload, "EN", prijevod);
	 translateForm(FormXML, "EN", prijevod);
	 translateForm(FormTCPclient, "EN", prijevod);
	 translateForm(Form1, "EN", prijevod);
}
//---------------------------------------------------------------------------


