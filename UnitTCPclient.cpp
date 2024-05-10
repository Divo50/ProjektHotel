//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitTCPClient.h"
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
	    /*
        IdTCPClient1->Host = EHost->Text;
			IdTCPClient1->Connect();
			IdTCPClient1->Socket->Write(EditTCPclient->Text.ToInt());
			int brojGostiju = IdTCPClient1->Socket->ReadInt32();
			ShowMessage(brojGostiju);
			IdTCPClient1->Disconnect();
	*/

    IdTCPClient1->Host = EHost->Text;
    IdTCPClient1->Connect();

	// Slanje podataka na server
	IdTCPClient1->Socket->Write(EditSoba->Text.ToInt());
	IdTCPClient1->Socket->Write(EditKuhinja->Text.ToInt());
	IdTCPClient1->Socket->Write(EditRestoran->Text.ToInt());
	IdTCPClient1->Socket->Write(EditPraonica->Text.ToInt());

	// Čekanje odgovora od servera (ukupni račun)
	int ukupniRacun = IdTCPClient1->Socket->ReadInt32();
	ShowMessage("Ukupni račun za vodu: " + IntToStr(ukupniRacun) + " eura.");

	IdTCPClient1->Disconnect();
}
//---------------------------------------------------------------------------


