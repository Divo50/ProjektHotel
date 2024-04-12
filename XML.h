//---------------------------------------------------------------------------

#ifndef XMLH
#define XMLH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
//---------------------------------------------------------------------------
class TFormXML : public TForm
{
__published:	// IDE-managed Components
	TXMLDocument *XMLDocument1;
	TListView *ListViewXML;
	TButton *GumbUcitajXML;
	TButton *GumbDodajXML;
	TEdit *EditSoba;
	TEdit *EditIme;
	TEdit *EditPrezime;
	TEdit *EditKrevet;
	TEdit *EditCijena;
	TEdit *EditBalkon;
	TGroupBox *GroupBoxDodaj;
	TButton *GumbSaveXML;
	TButton *GumbBrisiXML;
	void __fastcall GumbUcitajXMLClick(TObject *Sender);
	void __fastcall GumbDodajXMLClick(TObject *Sender);
	void __fastcall GumbSaveXMLClick(TObject *Sender);
	void __fastcall GumbBrisiXMLClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormXML(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormXML *FormXML;
//---------------------------------------------------------------------------
#endif
