//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Database.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDBForm *DBForm;
//---------------------------------------------------------------------------
__fastcall TDBForm::TDBForm(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TDBForm::Button1Click(TObject *Sender)
{
	 TOdjel->Insert();
	 TOdjel->FieldByName("imeOdjela")->AsString = "Parking";
	 TOdjel->FieldByName("brojZaposlenika")->AsInteger = 3;
	 TOdjel->Post();

}
//---------------------------------------------------------------------------

void __fastcall TDBForm::Button2Click(TObject *Sender)
{
        TOdjel->Delete();
}
//---------------------------------------------------------------------------

void __fastcall TDBForm::Button3Click(TObject *Sender)
{
	   TZaposlenici->Insert();
	   TZaposlenici->FieldByName("imeZaposlenik")->AsString = "Lovre";
	   TZaposlenici->FieldByName("prezimeZaposlenik")->AsString = "Rajiæ";
	   TZaposlenici->FieldByName("datumRodjenja")->AsDateTime = EncodeDate(2000, 2, 26);
	   TZaposlenici->FieldByName("sifOdjel")->AsInteger = 1;
	   TZaposlenici->FieldByName("sifSmjena")->AsInteger = 10;
	   TZaposlenici->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDBForm::Button4Click(TObject *Sender)
{
        TZaposlenici->Delete();
}
//---------------------------------------------------------------------------

void __fastcall TDBForm::Button5Click(TObject *Sender)
{
	   TSmjene->Insert();
	   TSmjene->FieldByName("opisSmjena")->AsString = "Jutro";
	   TSmjene->FieldByName("vrijemeSmjena")->AsDateTime = EncodeDate(2024, 4, 19);
	   TSmjene->FieldByName("danSmjena")->AsString = "Utorak";
	   TSmjene->Post();
}
//---------------------------------------------------------------------------

void __fastcall TDBForm::Button6Click(TObject *Sender)
{
		TSmjene->Delete();
}
//---------------------------------------------------------------------------

