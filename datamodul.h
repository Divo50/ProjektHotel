//---------------------------------------------------------------------------

#ifndef datamodulH
#define datamodulH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TDataModule1 : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *ADOConnection1;
	TADOTable *TOdjel;
	TAutoIncField *TOdjelsifOdjel;
	TWideStringField *TOdjelimeOdjela;
	TWideStringField *TOdjelbrojZaposlenika;
	TADOTable *TSmjene;
	TAutoIncField *TSmjenesifSmjena;
	TWideStringField *TSmjeneopisSmjena;
	TDateTimeField *TSmjenevrijemeSmjena;
	TWideStringField *TSmjenedanSmjena;
	TADOTable *TZaposlenici;
	TDataSource *DOdjel;
	TDataSource *DSmjene;
	TDataSource *DZaposlenici;
	TAutoIncField *TZaposlenicisifZaposlenik;
	TWideStringField *TZaposleniciimeZaposlenik;
	TWideStringField *TZaposleniciprezimeZaposlenik;
	TDateTimeField *TZaposlenicidatumRodjenja;
	TIntegerField *TZaposlenicisifOdjel;
	TIntegerField *TZaposlenicisifSmjena;
	TBCDField *TZaposleniciPlaca;
	TCurrencyField *TZaposleniciPlacakn;
	void __fastcall TZaposleniciCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
	__fastcall TDataModule1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#endif
