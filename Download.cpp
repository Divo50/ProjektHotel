//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "Download.h"
#include "Zaposlenici.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDownload *FormDownload;
//---------------------------------------------------------------------------
__fastcall TFormDownload::TFormDownload(TComponent* Owner)
	: TForm(Owner)
{
       OpenSSL->SSLOptions->SSLVersions = TIdSSLVersions() << sslvTLSv1_2;

		HTTP_klijent->IOHandler = OpenSSL;

}
//---------------------------------------------------------------------------
UnicodeString ExtractUrlFileName(UnicodeString url) {
    int i = LastDelimiter('/', url);
    return url.SubString(i + 1, url.Length() - i);
}
//---------------------------------------------------------------------------
void __fastcall TFormDownload::Button1Click(TObject *Sender)
{
         TFileStream* fs = new TFileStream(ExtractUrlFileName(ELink->Text), fmCreate);

    HTTP_klijent->Get(ELink->Text, fs);
    delete fs;

}
//---------------------------------------------------------------------------

void __fastcall TFormDownload::HTTP_klijentWorkBegin(TObject *ASender, TWorkMode AWorkMode,
          __int64 AWorkCountMax)
{
	   ProgressBar1->Position = 0;

	ProgressBar1->Max = AWorkCountMax;

}
//---------------------------------------------------------------------------

void __fastcall TFormDownload::HTTP_klijentWork(TObject *ASender, TWorkMode AWorkMode,
          __int64 AWorkCount)
{
            // prikaz napretka preuzimanja datoteke
		ProgressBar1->Position = AWorkCount;

		float a = AWorkCount;

		statusLabel->Caption = String(FormatFloat("0.00",float(AWorkCount)/float(ProgressBar1->Max)*100)) + "%";

		Application->ProcessMessages();

}
//---------------------------------------------------------------------------

void __fastcall TFormDownload::HTTP_klijentWorkEnd(TObject *ASender, TWorkMode AWorkMode)

{
		if(ProgressBar1->Position == ProgressBar1->Max) {

	Application->MessageBox(L"Cjenik je uspješno preuzet", L"Preuzimanje završeno!", MB_ICONINFORMATION);
	}
	ProgressBar1->Position = 0;
	statusLabel->Caption = "0%";
}
//---------------------------------------------------------------------------

void __fastcall TFormDownload::Button3Click(TObject *Sender)
{
		 Throttler->BitsPerSec =   204800; // 25 kb/s = 2 * 1024 * 8
}
//---------------------------------------------------------------------------

void __fastcall TFormDownload::Button4Click(TObject *Sender)
{
				Throttler->BitsPerSec =  409600; // 50 kb/s = 50 * 1024 * 8
}
//---------------------------------------------------------------------------

void __fastcall TFormDownload::Button5Click(TObject *Sender)
{
			Throttler->BitsPerSec =  819200; //   100 kb/s = 100 * 1024 * 8
}
//---------------------------------------------------------------------------

void __fastcall TFormDownload::Button2Click(TObject *Sender)
{
	   Application->MessageBox(L"Preuzimanje prekinuto", L"Greška, cjenik nije preuzet!", MB_ICONSTOP);
       HTTP_klijent->Disconnect();
}
//---------------------------------------------------------------------------

