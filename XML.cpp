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

_di_IXMLHotelType hotel = GetHotel(XMLDocument1);

      ListViewXML->Items->Clear();
   for(int i = 0; i < hotel->Count; i++){
	 ListViewXML->Items->Add();
	 ListViewXML->Items->Item[i]->Caption = hotel->Soba[i]->brojSobe;
	 ListViewXML->Items->Item[i]->SubItems->Add (hotel->Soba[i]->imeGosta);
	 ListViewXML->Items->Item[i]->SubItems->Add (hotel->Soba[i]->prezimeGosta);
	 ListViewXML->Items->Item[i]->SubItems->Add (hotel->Soba[i]->brojKreveta);
	 ListViewXML->Items->Item[i]->SubItems->Add (hotel->Soba[i]->cijena);
     ListViewXML->Items->Item[i]->SubItems->Add (hotel->Soba[i]->balkon);

   }
}
//---------------------------------------------------------------------------


void __fastcall TFormXML::GumbDodajXMLClickClick(TObject *Sender)
{
	 // Provjera praznih polja
    if (EditSoba->Text == "" || EditIme->Text == "" || EditPrezime->Text == "" ||
        EditKrevet->Text == "" || EditCijena->Text == "" || EditBalkon->Text == "")
    {
        ShowMessage("Sva polja moraju biti popunjena!");
        return;
    }

    _di_IXMLHotelType hotel = GetHotel(XMLDocument1);
    _di_IXMLSobaType soba = hotel->Add();

    // Postavljanje vrijednosti pomoæu svojstava
    soba->brojSobe = StrToInt(EditSoba->Text);
    soba->imeGosta = EditIme->Text;
    soba->prezimeGosta = EditPrezime->Text;
    soba->brojKreveta = StrToInt(EditKrevet->Text);
    soba->cijena = StrToInt(EditCijena->Text);
    soba->balkon = EditBalkon->Text;

    GumbUcitajXMLClick(Sender);

    // Spremanje XML-a s lijepim formatiranjem
    XMLDocument1->Options = XMLDocument1->Options << TXMLDocOption::doNodeAutoIndent;
	XMLDocument1->SaveToFile("podatci.xml");
}
//---------------------------------------------------------------------------



void __fastcall TFormXML::GumbSaveXMLClickClick(TObject *Sender)
{
	 // Provjera je li odabrana stavka u ListView-u
    if (ListViewXML->ItemIndex == -1)
    {
        ShowMessage("Nije odabrana soba za ažuriranje!");
        return;
	}

    _di_IXMLHotelType hotel = GetHotel(XMLDocument1);
    _di_IXMLSobaType soba = hotel->Soba[ListViewXML->ItemIndex];

    // Provjera praznih polja
    if (EditSoba->Text == "" || EditIme->Text == "" || EditPrezime->Text == "" ||
        EditKrevet->Text == "" || EditCijena->Text == "" || EditBalkon->Text == "")
    {
        ShowMessage("Sva polja moraju biti popunjena!");
        return;
    }

    // Ažuriranje sobe
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

void __fastcall TFormXML::GumbBrisiXMLClickClick(TObject *Sender)
{
	 // Provjera je li odabrana stavka u ListView-u
	if (ListViewXML->ItemIndex == -1)
	{
		ShowMessage("Nije odabrana soba za brisanje!");
		return;
	}

	// Potvrda brisanja
	if (MessageDlg("Jeste li sigurni da želite obrisati ovu sobu?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	{
		_di_IXMLHotelType hotel = GetHotel(XMLDocument1);

		hotel->Delete(ListViewXML->ItemIndex);

		XMLDocument1->SaveToFile("podatci.xml");

		// Osvježavanje prikaza
		GumbUcitajXMLClick(Sender);
	}
}
//---------------------------------------------------------------------------

