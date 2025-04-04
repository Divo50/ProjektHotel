//---------------------------------------------------------------------------

#ifndef DatabaseH
#define DatabaseH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TDBForm : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TDBGrid *DBGrid2;
	TDBGrid *DBGrid3;
	TDBNavigator *DBNavigator1;
	TDBNavigator *DBNavigator2;
	TDBNavigator *DBNavigator3;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TGroupBox *GroupBoxOdjel;
	TCheckBox *CheckBoxOdjel;
	TButton *ButtonSort;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall CheckBoxOdjelClick(TObject *Sender);
	void __fastcall ButtonSortClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDBForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDBForm *DBForm;
//---------------------------------------------------------------------------
#endif
