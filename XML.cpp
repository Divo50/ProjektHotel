//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XML.h"
#include "podatci.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormXML *FormXML;
//---------------------------------------------------------------------------
__fastcall TFormXML::TFormXML(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormXML::GumbUcitajXMLClick(TObject *Sender)
{
	 // učitaj adresar korištenjem komponente TXMLDocument komponente "XMLDocument1"
   _di_IXMLHotelType hotel = GetHotel(XMLDocument1);
   ListViewXML->Items->Clear();
   for(int i = 0; i < hotel->Count; i++){
	 ListViewXML->Items->Add();
	 ListViewXML->Items->Item[i]->Caption = hotel->Soba[i]->brojSobe;
	 ListViewXML->Items->Item[i]->SubItems->Add(hotel->Soba[i]->imeGosta);
	 ListViewXML->Items->Item[i]->SubItems->Add(hotel->Soba[i]->prezimeGosta);
	 ListViewXML->Items->Item[i]->SubItems->Add(hotel->Soba[i]->brojKreveta);
	 ListViewXML->Items->Item[i]->SubItems->Add(hotel->Soba[i]->cijena);
	 ListViewXML->Items->Item[i]->SubItems->Add(hotel->Soba[i]->balkon);

   }

}
//---------------------------------------------------------------------------
void __fastcall TFormXML::GumbDodajXMLClick(TObject *Sender)
{
	_di_IXMLHotelType hotel = GetHotel(XMLDocument1);
	_di_IXMLSobaType soba = hotel->Add();

	// Postavljanje vrijednosti pomoću svojstava
	soba->brojSobe = StrToInt(EditSoba->Text); // Konverzija teksta u integer
	soba->imeGosta = EditIme->Text;
	soba->prezimeGosta = EditPrezime->Text;
	soba->brojKreveta = StrToInt(EditKrevet->Text); // Konverzija teksta u integer
	soba->cijena = StrToInt(EditCijena->Text); // Konverzija teksta u integer
	soba->balkon = EditBalkon->Text;

	GumbUcitajXMLClick(Sender);

	XMLDocument1->SaveToFile("podatci.xml");
}
//---------------------------------------------------------------------------


void __fastcall TFormXML::GumbSaveXMLClick(TObject *Sender)
{
	_di_IXMLHotelType hotel = GetHotel(XMLDocument1);
	_di_IXMLSobaType soba = hotel->Soba[ListViewXML->ItemIndex];



		 soba->brojSobe = StrToInt(EditSoba->Text);
         	soba->imeGosta = EditIme->Text;
         	soba->prezimeGosta = EditPrezime->Text;
         	soba->brojKreveta = StrToInt(EditKrevet->Text);
         	soba->cijena = StrToInt(EditCijena->Text);
         	soba->balkon = EditBalkon->Text;

			GumbUcitajXMLClick(Sender);

			XMLDocument1->SaveToFile("podatci.xml");



}
//---------------------------------------------------------------------------

void __fastcall TFormXML::GumbBrisiXMLClick(TObject *Sender)
{

	if(ListViewXML->ItemIndex == -1)
		return;
	_di_IXMLHotelType hotel = GetHotel(XMLDocument1);

	hotel->Delete(ListViewXML->ItemIndex);

	XMLDocument1->SaveToFile("podatci.xml");
}
//---------------------------------------------------------------------------

