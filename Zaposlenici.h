//---------------------------------------------------------------------------

#ifndef ZaposleniciH
#define ZaposleniciH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFormZaposlenici : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TLabel *LabelZaposlenik;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:            // User declarations
  void ApplySettings();

public:
	void RefreshSettings();	// User declarations
 void __fastcall FormCreate(TObject *Sender);
	__fastcall TFormZaposlenici(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormZaposlenici *FormZaposlenici;
//---------------------------------------------------------------------------
#endif
