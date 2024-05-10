//---------------------------------------------------------------------------

#ifndef UnitUDPclientH
#define UnitUDPclientH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPClient.hpp>
//---------------------------------------------------------------------------
class TFormUDPClient : public TForm
{
__published:	// IDE-managed Components
	TIdUDPClient *IdUDPClient1;
	TEdit *EditPoruka;
	TLabel *Label1;
	TButton *ButtonUDP;
	TEdit *EHost;
	void __fastcall ButtonUDPClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormUDPClient(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormUDPClient *FormUDPClient;
//---------------------------------------------------------------------------
#endif
