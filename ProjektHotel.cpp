//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ProjektHotel.h"
#include "Unit2.h"
#include <Registry.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
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
			{"EN", "User"},
			{"HR", "Korisnik"}
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
}
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
	translateForm(this, ComboBox1->Text, translation);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonRegClick(TObject *Sender)
{           Form2->LabelDobrodosli->Caption = "Dobrodo�ao, " + EditKorisnik->Text + "!";
			Form2->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
		   TIniFile* ini = new TIniFile (GetCurrentDir() + "\\settings.ini");
    ini->WriteInteger ("Main Window", "Left", Left);
    ini->WriteInteger ("Main Window", "Top", Top);
    ini->WriteInteger ("Main Window", "Width", Width);
    ini->WriteInteger ("Main Window", "Height", Height);

    // Spremanje postavki fonta
    ini->WriteString("Font", "Name", currentFont->Name);
    ini->WriteInteger("Font", "Size", currentFont->Size);

    // Spremanje postavki boje pozadine
    ini->WriteInteger("Background", "Color", backgroundColor);

	delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	TIniFile* ini = new TIniFile (GetCurrentDir() + "\\settings.ini");
    Left = ini->ReadInteger ("Main Window", "Left", 0);
    Top = ini->ReadInteger ("Main Window", "Top", 0);
	Width = ini->ReadInteger ("Main Window", "Width", 700);
	Height = ini->ReadInteger ("Main Window", "Height", 500);

	// �itanje postavki fonta
	currentFont = new TFont();
	currentFont->Name = ini->ReadString("Font", "Name", "Helvetica");
	currentFont->Size = ini->ReadInteger("Font", "Size", 8);

	// �itanje postavki boje pozadine
	backgroundColor = static_cast<TColor>(ini->ReadInteger("Background", "Color", clGray));

	delete ini;

    // Postavljanje fonta i boje pozadine
	Font->Name = "Arial";
	Color = clGray;



}
//---------------------------------------------------------------------------

