
//---------------------------------------------------------------------------
#ifndef WebModuleUnit1H
#define WebModuleUnit1H
//---------------------------------------------------------------------------
#include <System.SysUtils.hpp>
#include <System.Classes.hpp>
#include <Web.HTTPApp.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <vector>
#include <memory>
#include<podatci.h>
//---------------------------------------------------------------------------
class Car {
public:
	String marka;
	String model;
	String registracija;
	Car(const String& marka, const String& model, const String& registracija)
		: marka(marka), model(model), registracija(registracija) {}
};

class Parking {
private:
	std::vector<std::unique_ptr<Car>> cars;
public:
	void AddCar(const String& marka, const String& model, const String& registracija) {
		cars.push_back(std::make_unique<Car>(marka, model, registracija));
	}
	String GetCarsInfo() {
		String info;
		for (const auto& car : cars) {
			info += "Marka: " + car->marka + ", Model: " + car->model + ", Registracija: " + car->registracija + "\n";
		}
		return info;
	}
};
class TWebModule1 : public TWebModule
{
__published:	// IDE-managed Components
	TXMLDocument *XMLDocument1;
	void __fastcall WebModule1DefaultHandlerAction(TObject *Sender, TWebRequest *Request,
		  TWebResponse *Response, bool &Handled);
	void __fastcall WebModule1WebItemGodisnjiAction(TObject *Sender, TWebRequest *Request,
		  TWebResponse *Response, bool &Handled);
	void __fastcall WebModule1WebActionItemSobeAction(TObject *Sender, TWebRequest *Request,
		  TWebResponse *Response, bool &Handled);
	void __fastcall WebModule1WebActionItemAutiAction(TObject *Sender, TWebRequest *Request,
		  TWebResponse *Response, bool &Handled);
private:
		  Parking parking;
		  String GetEmptyRooms(_di_IXMLHotelType hotel);
public:		// User declarations
	__fastcall TWebModule1(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
#endif


