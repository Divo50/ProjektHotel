//---------------------------------------------------------------------------

#ifndef ProjektHotelH
#define ProjektHotelH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <map.h>
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
	void __fastcall ComboBox1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
	std::map<String, std::map<String, String>> translation
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
