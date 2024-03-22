//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ProjektHotel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
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

