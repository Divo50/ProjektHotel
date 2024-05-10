//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitUDPclient.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormUDPClient *FormUDPClient;
//---------------------------------------------------------------------------
__fastcall TFormUDPClient::TFormUDPClient(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormUDPClient::ButtonUDPClick(TObject *Sender)
{
	int brojOsoba = StrToInt(EditPoruka->Text);
	AnsiString poruka;

	switch(brojOsoba) {
		case 1:
			poruka = "Cijena za 1 osobu je 40 eura.";
			break;
		case 2:
			poruka = "Cijena za 2 osobe je 70 eura.";
			break;
		case 3:
			poruka = "Cijena za 3 osobe je 150 eura.";
			break;
		case 4:
			poruka = "Cijena za 4 osobe je 200 eura.";
			break;
		default:
			poruka = "Nepoznat broj osoba.";
			break;
	}

	IdUDPClient1->SendBuffer(EHost->Text, 19500, ToBytes(poruka));
}
//---------------------------------------------------------------------------

