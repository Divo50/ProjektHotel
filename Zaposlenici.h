//---------------------------------------------------------------------------

#ifndef ZaposleniciH
#define ZaposleniciH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <map>
//---------------------------------------------------------------------------
class TFormZaposlenici : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1Sobe;
	TButton *Button2Pica;
	TButton *ButtonZ;
	TButton *ButtonTCP;
	TButton *ButtonUDP;
	TButton *Button7;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TButton *ButtonCurrency;
	TButton *ButtonCjenik;
	TButton *Button10;
	TLabel *LabelZaposlenik;
	TButton *BHRV;
	TButton *BENG;
	void __fastcall Button1SobeClick(TObject *Sender);
	void __fastcall Button2PicaClick(TObject *Sender);
	void __fastcall ButtonZClick(TObject *Sender);
	void __fastcall ButtonTCPClick(TObject *Sender);
	void __fastcall ButtonUDPClick(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall ButtonCurrencyClick(TObject *Sender);
	void __fastcall ButtonCjenikClick(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BHRVClick(TObject *Sender);
	void __fastcall BENGClick(TObject *Sender);
private:            // User declarations
  void ApplySettings();
    UnicodeString selectedLanguage; // Deklaracija samo jednom
	std::map<String, std::map<String, String>> prijevod;
public:
	void RefreshSettings();	// User declarations
 void __fastcall FormCreate(TObject *Sender);
	__fastcall TFormZaposlenici(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormZaposlenici *FormZaposlenici;
//---------------------------------------------------------------------------
#endif
