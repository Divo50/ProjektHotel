//---------------------------------------------------------------------------

#ifndef ProjektHotelH
#define ProjektHotelH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
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
	TComboBox *ComboBox1;
	TButton *ButtonReg;
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall ButtonRegClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
private:
  TFont* currentFont;
  TColor backgroundColor;
	// User declarations
public:		// User declarations
	std::map<String, std::map<String, String>> translation;
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
