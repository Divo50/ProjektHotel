
//---------------------------------------------------------------------------
#include "WebModuleUnit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include <System.JSON.hpp>
#include<podatci.h>

TComponentClass WebModuleClass = __classid(TWebModule1);
//---------------------------------------------------------------------------
__fastcall TWebModule1::TWebModule1(TComponent* Owner)
	: TWebModule(Owner)
{
	parking.AddCar("Toyota", "Corolla", "ABC-123-D");
	parking.AddCar("Honda", "Civic", "XYZ-789-CR");
	parking.AddCar("Ford", "Mustang", "MUS-456-BZ");
}
//---------------------------------------------------------------------------

void __fastcall TWebModule1::WebModule1DefaultHandlerAction(TObject *Sender, TWebRequest *Request,
          TWebResponse *Response, bool &Handled)
{
  Response->Content =
	"<html>"
	"<head><title>Web Server Application</title></head>"
	"<body>Web Server Application</body>"
	"</html>";
}
//---------------------------------------------------------------------------


void __fastcall TWebModule1::WebModule1WebItemGodisnjiAction(TObject *Sender, TWebRequest *Request,
          TWebResponse *Response, bool &Handled)
{
    if(Request->QueryFields->Count != 3)
    {
        Response->StatusCode = 400; // Bad Request
		Response->Content =
			"<html>"
			"<head><title>Web Server Application - Godisnji</title></head>"
			"<body>Not enough arguments!</body>"
			"</html>";
        Handled = true;
        return;
    }
    try
    {
        if(Request->MethodType == mtGet)
        {
            int godineStaza = StrToInt(Request->QueryFields->Values["godineStaza"]);
			String pozicija = Request->QueryFields->Values["pozicija"];
			int brojDjece = StrToInt(Request->QueryFields->Values["brojDjece"]);
            int godisnji = 20; // osnovni broj dana godisnjeg odmora
			// Dodavanje dana na temelju godina staza
			godisnji += godineStaza;
			// Dodavanje dana na temelju pozicije
            if (pozicija == "direktor") {
				godisnji += 5;
			} else if (pozicija == "menadzer") {
                godisnji += 3;
			} else {
				godisnji += 1; // ostale pozicije
			}
			// Dodavanje dana na temelju broja djece
			godisnji += brojDjece * 2;
			std::unique_ptr<TJSONObject> jsonResponse(new TJSONObject());
			jsonResponse->AddPair("godineStaza", static_cast<TJSONValue*>(new TJSONNumber(godineStaza)));
			jsonResponse->AddPair("pozicija", static_cast<TJSONValue*>(new TJSONString(pozicija)));
			jsonResponse->AddPair("brojDjece", static_cast<TJSONValue*>(new TJSONNumber(brojDjece)));
			jsonResponse->AddPair("godisnji", static_cast<TJSONValue*>(new TJSONNumber(godisnji)));
			Response->ContentType = "application/json";
			Response->Content = jsonResponse->ToString();
			Response->StatusCode = 200; // OK
		}
		else
		{
			Response->StatusCode = 405; // Method Not Allowed
			Response->Content =
				"<html>"
				"<head><title>Web Server Application - Godisnji</title></head>"
				"<body>Method not supported!</body>"
				"</html>";
		}
	}
	catch(const EConvertError& e)
	{
		Response->StatusCode = 400; // Bad Request
		Response->Content =
			"<html>"
			"<head><title>Web Server Application - Godisnji</title></head>"
			"<body>Invalid number format!</body>"
            "</html>";
    }
	Handled = true;
}
//---------------------------------------------------------------------------

String TWebModule1::GetEmptyRooms(_di_IXMLHotelType hotel) {
	String resultXml = "<empty_rooms>";
	for (int i = 0; i < hotel->Count; i++) {
		_di_IXMLSobaType soba = hotel->Soba[i];
		if (soba->imeGosta == "x" && soba->prezimeGosta == "x") {
			resultXml += "<room>";
			resultXml += "<number>" + IntToStr(soba->brojSobe) + "</number>";
            resultXml += "<price>" + FloatToStr(soba->cijena) + "</price>";
			resultXml += "<balcony>" + soba->balkon + "</balcony>";
			resultXml += "</room>";
		}
	}
	resultXml += "</empty_rooms>";
	return resultXml;
}

void __fastcall TWebModule1::WebModule1WebActionItemSobeAction(TObject *Sender, TWebRequest *Request,
		  TWebResponse *Response, bool &Handled)
{
	try {
		XMLDocument1->LoadFromFile("C:\\Users\\Win11\\Documents\\Desktop\\hoteli\\podatci.xml");
		_di_IXMLHotelType hotel = GetHotel(XMLDocument1);
		String resultXml = GetEmptyRooms(hotel);
		Response->StatusCode = 200;
		Response->ReasonString = "OK";
		Response->ContentType = "application/xml; charset=UTF-8";
		Response->Content = resultXml;
	} catch (const Exception &e) {
		Response->StatusCode = 500;
		Response->ReasonString = "Internal Server Error";
		Response->ContentType = "text/plain; charset=UTF-8";
		Response->Content = "Error: " + e.Message;
	}
}
//---------------------------------------------------------------------------

void __fastcall TWebModule1::WebModule1WebActionItemAutiAction(TObject *Sender, TWebRequest *Request,
		  TWebResponse *Response, bool &Handled)
{
	String carsInfo = parking.GetCarsInfo();
	Response->Content = "<html><body><h1>Parkirani auti:</h1><pre>" + carsInfo + "</pre></body></html>";
	Handled = true;
}
//---------------------------------------------------------------------------

