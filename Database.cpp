
	//---------------------------------------------------------------------------

	#include <vcl.h>
	#pragma hdrstop

	#include "Database.h"
	#include "datamodul.h"



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
		 DataModule1->TOdjel->Insert();
		 DataModule1->TOdjel->FieldByName("imeOdjela")->AsString = "Parking";
		 DataModule1->TOdjel->FieldByName("brojZaposlenika")->AsInteger = 3;
		 DataModule1->TOdjel->Post();

    }
    //---------------------------------------------------------------------------

    void __fastcall TDBForm::Button2Click(TObject *Sender)
	{
			DataModule1->TOdjel->Delete();
    }
    //---------------------------------------------------------------------------

    void __fastcall TDBForm::Button3Click(TObject *Sender)
    {
		   DataModule1->TZaposlenici->Insert();
		   DataModule1->TZaposlenici->FieldByName("imeZaposlenik")->AsString = "Lovre";
		   DataModule1->TZaposlenici->FieldByName("prezimeZaposlenik")->AsString = "Rajiæ";
		   DataModule1->TZaposlenici->FieldByName("datumRodjenja")->AsDateTime = EncodeDate(2000, 2, 26);
		   DataModule1->TZaposlenici->FieldByName("sifOdjel")->AsInteger = 4;
		   DataModule1->TZaposlenici->FieldByName("sifSmjena")->AsInteger = 1;
		   DataModule1->TZaposlenici->Post();
    }
    //---------------------------------------------------------------------------

    void __fastcall TDBForm::Button4Click(TObject *Sender)
    {
			DataModule1->TZaposlenici->Delete();
    }
	//---------------------------------------------------------------------------


    	void __fastcall TDBForm::Button5Click(TObject *Sender)
    	{
			   DataModule1->TSmjene->Insert();
			   DataModule1->TSmjene->FieldByName("opisSmjena")->AsString = "Jutro";
			   DataModule1->TSmjene->FieldByName("vrijemeSmjena")->AsDateTime = EncodeDate(2024, 4, 19);
			   DataModule1->TSmjene->FieldByName("danSmjena")->AsString = "Utorak";
			   DataModule1->TSmjene->Post();
    	}
    	//---------------------------------------------------------------------------


    void __fastcall TDBForm::Button6Click(TObject *Sender)
	{
			DataModule1->TSmjene->Delete();
    }
	//---------------------------------------------------------------------------




void __fastcall TDBForm::CheckBoxOdjelClick(TObject *Sender)
{
	// Provjera je li checkbox odabran
	if (CheckBoxOdjel->Checked) {
		// Postavljanje filtera na tablicu TOdjel
		DataModule1->TOdjel->Filter = "brojZaposlenika > 10";
		// Primjena filtriranja
		DataModule1->TOdjel->Filtered = true;
	} else {
		// Ako checkbox nije odabran, uklonite filter
		DataModule1->TOdjel->Filter = "";
		DataModule1->TOdjel->Filtered = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDBForm::ButtonSortClick(TObject *Sender)
{
	DataModule1->TOdjel-> IndexFieldNames = "brojZaposlenika";
}
//---------------------------------------------------------------------------


