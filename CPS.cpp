//============================================================================
// Name        : CPS.cpp
// Author      : ByteMe Team
// Version     :
// Copyright   : CSCI 150
// Description : C++, Ansi-style
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

int main() {

		XMLDocument xmlDoc;
		XMLError eResult = xmlDoc.LoadFile(path);
		XMLCheckResult(eResult);
		xmlDoc.Clear();
		cout << "ErrorID  : " << xmlDoc.ErrorID() <<endl<<"ErrorName: " <<xmlDoc.ErrorName()<<endl;

		XMLNode * pRoot = xmlDoc.NewElement("P1");

		//Manually
		xmlDoc.InsertFirstChild(pRoot);
		XMLElement * pElement = xmlDoc.NewElement("SpotNum");
		pElement->SetText(1);
		pRoot->InsertEndChild(pElement);

		pElement = xmlDoc.NewElement("SpotStatus");
		pElement->SetText("Available");
		pRoot->InsertEndChild(pElement);

		//auto
		for (int i= 0; i < 20; ++i) {
					pElement = xmlDoc.NewElement("SpotNum");
					pElement->SetText(i+2);
					pRoot->InsertEndChild(pElement);

					pElement = xmlDoc.NewElement("SpotStatus");
					if(i%2 != 0)
						pElement->SetText("Available");
					else
						pElement->SetText("Unavailable");
					pRoot->InsertEndChild(pElement);
		}


		eResult = xmlDoc.SaveFile(path);
		XMLCheckResult(eResult);
		cout << "ErrorID  : " << xmlDoc.ErrorID() <<endl<<"ErrorName: " <<xmlDoc.ErrorName()<<endl;




	return 0;
}
