//---------------------------------------------------------------------------

#ifndef UnitServersH
#define UnitServersH
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
#include <IdUDPBase.hpp>
#include <IdUDPServer.hpp>
#include <IdGlobal.hpp>
#include <IdSocketHandle.hpp>
//---------------------------------------------------------------------------
class TFormServers : public TForm
{
__published:	// IDE-managed Components
	TIdTCPServer *IdTCPServer1;
	TIdUDPServer *IdUDPServer1;
	void __fastcall IdTCPServer1Execute(TIdContext *AContext);
	void __fastcall IdUDPServer1UDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
          TIdSocketHandle *ABinding);
private:	// User declarations
public:		// User declarations
	__fastcall TFormServers(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormServers *FormServers;
//---------------------------------------------------------------------------
#endif
