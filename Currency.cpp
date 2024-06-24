//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Currency.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormCur *FormCur;
//---------------------------------------------------------------------------
__fastcall TFormCur::TFormCur(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormCur::Button1Click(TObject *Sender)
{
	RESTClient1->BaseURL = "https://www.amdoren.com/api/currency.php";

	RESTRequest1->Params->AddItem("api_key", "BYLBAmYhSxQfAEaMaxKvTt9vFKnTMR");

	RESTRequest1->Execute();

	Memo1->Lines->Clear();
	Memo1->Lines->Add(RESTResponse1->Content);
}
//---------------------------------------------------------------------------



