//---------------------------------------------------------------------------


#pragma hdrstop

#include "datamodul.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
__fastcall TDataModule1::TDataModule1(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TDataModule1::TZaposleniciCalcFields(TDataSet *DataSet)
{
		        /*
			double placa = DataSet->FieldByName("Placa")->AsCurrency;
					DataSet->FieldByName("Placa (kn)")->AsCurrency = placa * 7,5;
        */

		double placa = DataSet->FieldByName("Plaća")->AsCurrency;
		double placaKn = placa * 7.53;
		DataSet->FieldByName("Plaća (kn)")->AsCurrency = placaKn;
}
//---------------------------------------------------------------------------


