//============================================================================
// Name        : CPS.cpp
// Author      : ByteMe Team
// Version     :
// Copyright   : CSCI 150
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include "BLL/DataRetriever.h"
#include "BLL/Spot.h"



using namespace std;

int main() {
	DataRetriever findSpot;
	Spot spot;
	list<Spot> spotsList = findSpot.Query(5);

	  for(list<Spot>::iterator it = spotsList.begin(); it!= spotsList.end(); ++it) {
	    Spot spot = *it;
	    cout << "ID: " << spot.GetId() << " STATUS: " << spot.GetStatus() << endl;
	  }

/*
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
*/
	return 0;
}
