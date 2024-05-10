//---------------------------------------------------------------------------

#ifndef JSONH
#define JSONH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormJSON : public TForm
{
__published:	// IDE-managed Components
	TListView *ListViewJSON;
	TButton *GumbUcitajJSON;
	TButton *GumbDodajJSON;
	TButton *GumbUpdateJSON;
	TButton *GumbBrisiJSON;
	TButton *GumbSpremiJSON;
	TGroupBox *GroupBoxDodaj;
	TEdit *EditAlkohoJSON;
	TEdit *EditVrstaJSON;
	TEdit *EditGodinaJSON;
	TEdit *EditDrzavaJSON;
	TEdit *EditImeJSON;
	void __fastcall GumbUcitajJSONClick(TObject *Sender);
	void __fastcall GumbDodajJSONClick(TObject *Sender);
	void __fastcall GumbBrisiJSONClick(TObject *Sender);
	void __fastcall GumbUpdateJSONClick(TObject *Sender);
	void __fastcall GumbSpremiJSONClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormJSON(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormJSON *FormJSON;
//---------------------------------------------------------------------------
#endif
