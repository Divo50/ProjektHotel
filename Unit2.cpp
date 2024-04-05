//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include<Registry.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
	  TIniFile* ini = new TIniFile (GetCurrentDir() + "\\settings.ini");

	  // Èitanje postavki boje pozadine
	backgroundColor = static_cast<TColor>(ini->ReadInteger("Background", "Color", clGray));

	delete ini;

	// Postavljanje fonta i boje pozadine
	Font->Name = "Arial";
	Color = clTeal;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
	  TIniFile* ini = new TIniFile (GetCurrentDir() + "\\settings.ini");

	  ini->WriteInteger("Background", "Color", backgroundColor);
}
//---------------------------------------------------------------------------

