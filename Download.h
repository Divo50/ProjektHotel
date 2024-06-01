//---------------------------------------------------------------------------

#ifndef DownloadH
#define DownloadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdIntercept.hpp>
#include <IdInterceptThrottler.hpp>
#include <IdIOHandler.hpp>
#include <IdIOHandlerSocket.hpp>
#include <IdIOHandlerStack.hpp>
#include <IdSSL.hpp>
#include <IdSSLOpenSSL.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormDownload : public TForm
{
__published:	// IDE-managed Components
	TEdit *ELink;
	TProgressBar *ProgressBar1;
	TButton *Button1;
	TButton *Button2;
	TIdSSLIOHandlerSocketOpenSSL *OpenSSL;
	TIdInterceptThrottler *Throttler;
	TIdHTTP *HTTP_klijent;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TGroupBox *GroupBox1;
	TLabel *statusLabel;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall HTTP_klijentWorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax);
	void __fastcall HTTP_klijentWork(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount);
	void __fastcall HTTP_klijentWorkEnd(TObject *ASender, TWorkMode AWorkMode);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TFormDownload(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDownload *FormDownload;
//---------------------------------------------------------------------------
#endif
