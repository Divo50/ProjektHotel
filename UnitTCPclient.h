//---------------------------------------------------------------------------

#ifndef UnitTCPclientH
#define UnitTCPclientH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
//---------------------------------------------------------------------------
class TFormTCPclient : public TForm
{
__published:	// IDE-managed Components
	TLabel *LabelTCPclient;
	TEdit *EditTCPclient;
	TGroupBox *GroupBox1;
	TButton *ButtonTCP;
	TIdTCPClient *IdTCPClient1;
	TEdit *EHost;
	void __fastcall ButtonTCPClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormTCPclient(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTCPclient *FormTCPclient;
//---------------------------------------------------------------------------
#endif
