//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitTCPclient.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormTCPclient *FormTCPclient;
//---------------------------------------------------------------------------
__fastcall TFormTCPclient::TFormTCPclient(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormTCPclient::ButtonTCPClick(TObject *Sender)
{
	IdTCPClient1->Host = EHost->Text;
	IdTCPClient1->Connect();
	IdTCPClient1->Socket->Write(EditTCPclient->Text.ToInt());
	int brojGostiju = IdTCPClient1->Socket->ReadInt32();
	ShowMessage(brojGostiju);
	IdTCPClient1->Disconnect();

}
//---------------------------------------------------------------------------
