//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "ProjektHotel.h"
#include "Unit2.h"
#include "XML.h"
#include "JSON.h"
#include "Database.h"
#include "CustomFormat.h"
#include "UnitTCPclient.h"
#include "UnitUDPclient.h"
#include "Zaposlenici.h"
#include "tempconvert.h"
#include "Temperatura.h"
#include "Currency.h"
#include "Download.h"
#include "C:\Users\Danko\Desktop\NTP\hoteli\ProjektHotel-main\DLL\Rent.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormZaposlenici *FormZaposlenici;
//---------------------------------------------------------------------------
__fastcall TFormZaposlenici::TFormZaposlenici(TComponent* Owner)
	: TForm(Owner)
{
	ApplySettings();




}
//---------------------------------------------------------------------------


void __fastcall TFormZaposlenici::Button1Click(TObject *Sender)
{
		FormXML->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFormZaposlenici::Button2Click(TObject *Sender)
{
	   FormJSON->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFormZaposlenici::Button3Click(TObject *Sender)
{
       FormCustom->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFormZaposlenici::Button4Click(TObject *Sender)
{
              DBForm->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFormZaposlenici::Button5Click(TObject *Sender)
{
           FormTCPclient->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFormZaposlenici::Button6Click(TObject *Sender)
{
         FormUDPClient->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFormZaposlenici::Button7Click(TObject *Sender)
{
		   FormTemperatura->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TFormZaposlenici::FormCreate(TObject *Sender)
{
	 ApplySettings();

}
void __fastcall TFormZaposlenici::Button8Click(TObject *Sender)
{
		   FormCur->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormZaposlenici::Button9Click(TObject *Sender)
{
		   FormDownload->ShowModal();
}
//---------------------------------------------------------------------------
void TFormZaposlenici::ApplySettings()
{
 TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");

	// Apply background color
	TColor backgroundColor = (TColor)ini->ReadInteger("Appearance", "BackgroundColor", clGreen);
	Color = backgroundColor;

	// Apply font size
	int fontSize = ini->ReadInteger("Font", "FontSize", Font->Size);
	Font->Size = fontSize;

	// Apply font color (if necessary)
	TColor fontColor = (TColor)ini->ReadInteger("Font", "FontColor", Font->Color);
	Font->Color = fontColor;

	delete ini;
}
//---------------------------------------------------------------------------
void TFormZaposlenici::RefreshSettings()
{
	 ApplySettings();

	TIniFile* ini = new TIniFile(GetCurrentDir() + "\\settings.ini");
	int fontSize = ini->ReadInteger("Font", "FontSize", Font->Size);
	delete ini;

	Font->Size = fontSize;

}
void __fastcall TFormZaposlenici::Button10Click(TObject *Sender)
{
	 TDllForm1* dllform = new TDllForm1(this);
	if(dllform->ShowModal() == mrClose)

	delete dllform;
}
//---------------------------------------------------------------------------


void __fastcall TFormZaposlenici::FormShow(TObject *Sender)
{
  LabelZaposlenik->Caption = "Korisnik: " + Form1->EditKorisnik->Text;

}
//---------------------------------------------------------------------------

