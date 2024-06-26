//---------------------------------------------------------------------------

#ifndef ProjektHotelH
#define ProjektHotelH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>

#include <System.SysUtils.hpp>
#include <map>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *LabelHotel;
	TLabel *LabelLozinka;
	TLabel *LabelKorisnik;
	TEdit *EditKorisnik;
	TEdit *EditLozinka;
	TButton *ButtonReg;
	TCheckBox *CheckBoxPassword;
	TButton *Button1;
	TColorDialog *ColorDialog1;
	TButton *ButtonSetColorClick;
	TEdit *EditFontSize;
	TButton *ButtonFont;
	TCheckBox *CheckBoxZapamti;
	TImage *Image1;
	TButton *BENG;
	TButton *BHRV;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall CheckBoxPasswordClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ButtonSetColorClickClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ButtonFontClick(TObject *Sender);
	void __fastcall ButtonRegClick(TObject *Sender);
	void __fastcall BENGClick(TObject *Sender);
	void __fastcall BHRVClick(TObject *Sender);
private:
  TFont  *currentFont;
  TColor backgroundColor;
  UnicodeString selectedLanguage; // Deklaracija samo jednom
  	std::map<String, std::map<String, String>> translation;
	// User declarations
public:		// User declarations

	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
