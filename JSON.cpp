//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "JSON.h"
#include <System.JSON.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormJSON *FormJSON;
//---------------------------------------------------------------------------
__fastcall TFormJSON::TFormJSON(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormJSON::GumbUcitajJSONClick(TObject *Sender)
{
	// load json file
	std::unique_ptr<TStringStream> jsonStream(new TStringStream);
	jsonStream->LoadFromFile("popis.json");

	// create JSON object that represents entire JSON file
	TJSONObject* jsonFile = (TJSONObject*)TJSONObject::ParseJSONValue(jsonStream->DataString);

	// create JSON object that represent array from inside addresBook object
	TJSONArray* popisArray = (TJSONArray*)TJSONObject::ParseJSONValue(jsonFile->GetValue("popis")->ToString());

	// read and output each address book contact
	ListViewJSON->Items->Clear();
	for (int i = 0; i < popisArray->Count; i++) {
		// read contact info
		String ime_pica = popisArray->Items[i]->GetValue<UnicodeString>("ime_pica");
		String vrsta_pica = popisArray->Items[i]->GetValue<UnicodeString>("vrsta_pica");
		int godina_proizvodnje = popisArray->Items[i]->GetValue<int>("godina_proizvodnje");
		double postotak_alkohola = popisArray->Items[i]->GetValue<double>("postotak_alkohola");
		String drzava_proizvodnje = popisArray->Items[i]->GetValue<UnicodeString>("drzava_proizvodnje");

		// show contact info inside ListView component
		ListViewJSON->Items->Add();
		ListViewJSON->Items->Item[i]->Caption = ime_pica;
		ListViewJSON->Items->Item[i]->SubItems->Add(vrsta_pica);
		ListViewJSON->Items->Item[i]->SubItems->Add(godina_proizvodnje);
		ListViewJSON->Items->Item[i]->SubItems->Add(postotak_alkohola);
		ListViewJSON->Items->Item[i]->SubItems->Add(drzava_proizvodnje);
	}
}
//---------------------------------------------------------------------------
void __fastcall TFormJSON::GumbDodajJSONClick(TObject *Sender)
{
	ListViewJSON->Items->Add();
	int lastIndex = ListViewJSON->Items->Count-1;
	ListViewJSON->Items->Item[lastIndex]->Caption = EditImeJSON->Text;
	ListViewJSON->Items->Item[lastIndex]->SubItems->Add(EditVrstaJSON->Text);
	ListViewJSON->Items->Item[lastIndex]->SubItems->Add(EditGodinaJSON->Text);
	ListViewJSON->Items->Item[lastIndex]->SubItems->Add(EditAlkohoJSON->Text);
	ListViewJSON->Items->Item[lastIndex]->SubItems->Add(EditDrzavaJSON->Text);
}
//---------------------------------------------------------------------------
void __fastcall TFormJSON::GumbBrisiJSONClick(TObject *Sender)
{
	ListViewJSON->DeleteSelected();
}
//---------------------------------------------------------------------------
void __fastcall TFormJSON::GumbUpdateJSONClick(TObject *Sender)
{
	if(ListViewJSON->ItemIndex == -1)
		return;

	ListViewJSON->Items->Item[ListViewJSON->ItemIndex]->Caption = EditImeJSON->Text;
	ListViewJSON->Items->Item[ListViewJSON->ItemIndex]->SubItems-> Strings[0] = EditVrstaJSON->Text;
	ListViewJSON->Items->Item[ListViewJSON->ItemIndex]->SubItems-> Strings[1] = EditGodinaJSON->Text;
	ListViewJSON->Items->Item[ListViewJSON->ItemIndex]->SubItems-> Strings[2] = EditAlkohoJSON->Text;
	ListViewJSON->Items->Item[ListViewJSON->ItemIndex]->SubItems-> Strings[3] = EditDrzavaJSON->Text;
}
//---------------------------------------------------------------------------
void __fastcall TFormJSON::GumbSpremiJSONClick(TObject *Sender)
{

	String jsonDoc;
	jsonDoc = "{";
		jsonDoc += "\"popis\":";
		jsonDoc += "[";

		for(int i = 0; i < ListViewJSON->Items->Count; i++){
			jsonDoc +=
			"{"
				"\"ime_pica\":\"" + ListViewJSON->Items->Item[i]->Caption + "\"," +
				"\"vrsta_pica\":\"" + ListViewJSON->Items->Item[i]->SubItems->Strings[0] + "\"," +
				"\"godina_proizvodnje\":\"" + ListViewJSON->Items->Item[i]->SubItems->Strings[1] + "\"," +
				"\"postotak_alkohola\":" + ListViewJSON->Items->Item[i]->SubItems->Strings[2] + "," +
				"\"drzava_proizvodnje\":\"" + ListViewJSON->Items->Item[i]->SubItems->Strings[3] + "\"," +
			"}";
			jsonDoc += (i+1 != ListViewJSON->Items->Count) ? "," : "";
		}
		jsonDoc += "]";
	jsonDoc += "}";

	//Application->MessageBoxW(jsonDoc.w_str(), L"", 0);
	// format json document (line breaks, indents..)
	jsonDoc = ((TJSONObject*)TJSONObject::ParseJSONValue(jsonDoc))->Format(2);

	std::unique_ptr<TStringStream> ss(new TStringStream);
	ss->WriteString(jsonDoc);
	ss->SaveToFile("popis.json");
}
//---------------------------------------------------------------------------
