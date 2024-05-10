//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitServers.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormServers *FormServers;
//---------------------------------------------------------------------------
__fastcall TFormServers::TFormServers(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormServers::IdTCPServer1Execute(TIdContext *AContext)
{
	    /*
         int brGostiju = AContext->Connection->Socket->ReadInt32();
			 AContext->Connection->Socket->Write(brGostiju * 3);
			 AContext->Connection->Disconnect();
	*/


	const int cijenaVodePoM3 = 2;

	int kolicinaSoba = AContext->Connection->Socket->ReadInt32();
	int kolicinaKuhinja = AContext->Connection->Socket->ReadInt32();
	int kolicinaRestoran = AContext->Connection->Socket->ReadInt32();
	int kolicinaPraonica = AContext->Connection->Socket->ReadInt32();

	int ukupnaPotrosnja = kolicinaSoba + kolicinaKuhinja + kolicinaRestoran + kolicinaPraonica;

	int ukupniRacun = ukupnaPotrosnja * cijenaVodePoM3;

	AContext->Connection->Socket->Write(ukupniRacun);

	AContext->Connection->Disconnect();
}
//---------------------------------------------------------------------------

void __fastcall TFormServers::IdUDPServer1UDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
		  TIdSocketHandle *ABinding)
{
    UnicodeString primljenaPoruka = BytesToString(AData);

	ShowMessage(primljenaPoruka);
}
//---------------------------------------------------------------------------

