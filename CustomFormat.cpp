//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
 #include <vector>
#include "CustomFormat.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormCustom *FormCustom;
//---------------------------------------------------------------------------
__fastcall TFormCustom::TFormCustom(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

class MyFileFormat {
public:
	wchar_t name[40];
	float version;

	MyFileFormat() {
		wcsncpy(name, L"Recepcioneri na današnjoj smjeni", 40);
		version = 1.0;
	}
};
//---------------------------------------------------------------------------

class Recepcija {
public:
	wchar_t ime[15], prezime[15], pozicija[25], mail[40], brojTelefona[25];

	Recepcija() = default;
	Recepcija(wchar_t* _ime, wchar_t* _prezime, wchar_t* _pozicija,
			wchar_t* _mail, wchar_t* _brojTelefona) {
		wcsncpy(ime, _ime, 15);
		wcsncpy(prezime, _prezime, 15);
		wcsncpy(pozicija, _pozicija, 25);
		wcsncpy(mail, _mail, 40);
		wcsncpy(brojTelefona, _brojTelefona, 25);
	}
};

//---------------------------------------------------------------------------
void __fastcall TFormCustom::GumbSpremiClick(TObject *Sender)
{
    // create contacts
	std::vector<Recepcija> recepcija =
	{
		Recepcija(L"Ivana", L"Matijević", L"Pomoćni recepcioner", L"ivana.matijevic@gmail.com", L"+385 95 456 2345"),
		Recepcija(L"Luka", L"Horvat", L"Glavni recepcioner", L"luka.horvat@gmail.com", L"+385 95 555 9876"),
	};

	// save file format header to file
	MyFileFormat Header;
	std::unique_ptr<TFileStream> recepcijaStream(new TFileStream("recepcija.mff", fmCreate));
	recepcijaStream->Write(&Header, sizeof(MyFileFormat));

	// save contacts to file
	for (int i = 0; i < recepcija.size(); i++)
		recepcijaStream->Write(&recepcija[i], sizeof(Recepcija));
}
//---------------------------------------------------------------------------
void __fastcall TFormCustom::GumbOtvoriClick(TObject *Sender)
{
    // load data from file
	std::unique_ptr<TMemoryStream> recepcijaStream(new TMemoryStream);
	recepcijaStream->LoadFromFile("recepcija.mff");

	// read header
	MyFileFormat Header;
	recepcijaStream->Read(&Header, sizeof(MyFileFormat));

	// is this the correct format?
	if(String(Header.name) != "Recepcioneri na današnjoj smjeni" || Header.version != 1.0){
		ShowMessage("Wrong format!");
		return;
	}
	// read all contacts
	Recepcija tmp;
	int recepcijaCount = (recepcijaStream->Size - sizeof(Header)) / sizeof(Recepcija);
	for(int i = 0; i < recepcijaCount; i++){
		UnicodeString rec;
		recepcijaStream->Read(&tmp, sizeof(Recepcija));
		rec += String(tmp.ime) + " ";
		rec += String(tmp.prezime) + ", ";
		rec += String(tmp.pozicija) + ", ";
		rec += String(tmp.mail) + ", ";
		rec += String(tmp.brojTelefona);
		ShowMessage(rec);
	}
}
//---------------------------------------------------------------------------
