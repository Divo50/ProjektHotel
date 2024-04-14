//---------------------------------------------------------------------------

#ifndef CustomFormatH
#define CustomFormatH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFormCustom : public TForm
{
__published:	// IDE-managed Components
	TButton *GumbSpremi;
	TButton *GumbOtvori;
	void __fastcall GumbSpremiClick(TObject *Sender);
	void __fastcall GumbOtvoriClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormCustom(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormCustom *FormCustom;
//---------------------------------------------------------------------------
#endif
