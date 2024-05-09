//---------------------------------------------------------------------------

#ifndef UnitTCPH
#define UnitTCPH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPServer.hpp>
#include <IdContext.hpp>
//---------------------------------------------------------------------------
class TFormTCP : public TForm
{
__published:	// IDE-managed Components
	TIdTCPServer *IdTCPServer1;
	void __fastcall IdTCPServer1Execute(TIdContext *AContext);
private:	// User declarations
public:		// User declarations
	__fastcall TFormTCP(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormTCP *FormTCP;
//---------------------------------------------------------------------------
#endif
