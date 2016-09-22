//============================================================================
// Name        : CPS.cpp
// Author      : ByteMe Team
// Version     :
// Copyright   : CSCI 150
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "DAL\tinyxml2.h"

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

const char* path ="DAL/Data/ParkingStructure.xml";
static const char* xml =
				"<?xml version=\"1.0\"?>"
				"<!DOCTYPE PLAY SYSTEM \"\ParkingStructure.dtd\">"
				;

int main() {


		XMLDocument xmlDoc;
		xmlDoc.Parse( xml );
		XMLError eResult = xmlDoc.LoadFile(path);
		XMLCheckResult(eResult);
		cout << "ErrorID  : " << xmlDoc.ErrorID() <<endl<<"ErrorName: " <<xmlDoc.ErrorName()<<endl;


		XMLNode * pPark = xmlDoc.NewElement("P1");
		//Manually

		xmlDoc.InsertFirstChild(pPark);


		//auto
		for (int i= 1; i <= 20; i++) {
					XMLElement * pElement = xmlDoc.NewElement("Spot");
					pElement->SetAttribute("ID",i);
					if(i%2 != 0)
						pElement->SetAttribute("Status",0);
					else
						pElement->SetAttribute("Status",1);
					pPark->InsertEndChild(pElement);
		}
		xmlDoc.InsertEndChild(pPark);
		eResult = xmlDoc.SaveFile(path);


		XMLCheckResult(eResult);
		cout << "ErrorID  : " << xmlDoc.ErrorID() <<endl<<"ErrorName: " <<xmlDoc.ErrorName()<<endl;




	return 0;
}
