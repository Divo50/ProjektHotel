//---------------------------------------------------------------------------

#ifndef RentH
#define RentH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------

class Automobil;
#ifdef EXPORTS
	#define DLL_EXPORT __declspec(dllexport)
#else
	#define DLL_EXPORT __declspec(dllimport)
#endif



class DLL_EXPORT TDllForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *EditOdrasli;
	TButton *ButtonRacun;
	TGroupBox *GroupBox1;
	TEdit *EditDjeca;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *EditDani;
	TLabel *Label4;
	TEdit *EditPopust;
	TGroupBox *GroupBox2;
	TComboBox *ComboBoxMarka;
	TLabel *Label5;
	TLabel *Label6;
	TComboBox *ComboBoxGorivo;
	TComboBox *ComboBoxMjenjac;
	TLabel *Label7;
	TEdit *EditBrojDana;
	TLabel *Label8;
	TButton *ButtonProvjera;
	TEdit *PopustEdit;
	TLabel *Label9;
	TButton *ButtonRezerviraj;
	TComboBox *ComboBoxModel;
	TLabel *Label10;
	TButton *ButtonVrati;
	void __fastcall ButtonRacunClick(TObject *Sender);
	void __fastcall ButtonProvjeraClick(TObject *Sender);
	void __fastcall ButtonRezervirajClick(TObject *Sender);
	void __fastcall ComboBoxMarkaChange(TObject *Sender);
	void __fastcall ButtonVratiClick(TObject *Sender);
private:

   				 Automobil* pronadjiAutomobil(String marka, String gorivo, String mjenjac, String model);
               Automobil* pronadeniAutomobil; // Dodano za pohranu pronaðenog automobila
public:		// User declarations
	__fastcall TDllForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDllForm1 *DllForm1;
//---------------------------------------------------------------------------
#endif
