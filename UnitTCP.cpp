//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitTCP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormTCP *FormTCP;
//---------------------------------------------------------------------------
__fastcall TFormTCP::TFormTCP(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormTCP::IdTCPServer1Execute(TIdContext *AContext)
{
	 int brGostiju = AContext->Connection->Socket->ReadInt32();
	 AContext->Connection->Socket->Write(brGostiju * 3);
	 AContext->Connection->Disconnect();
}
//---------------------------------------------------------------------------

