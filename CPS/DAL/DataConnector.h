/*
 * DataConnector.h
 *
 *  Created on: Sep 21, 2016
 *      Author: ByteMe Team
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include "tinyxml2.h"
#include "..\BLL\Spot.h"

using namespace std;
using namespace tinyxml2;

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); /*return a_eResult;*/ }
#endif


class DataConnector {


public:
	DataConnector();
	virtual ~DataConnector();

	std::list<Spot> Query(int x) {
	    std::list<Spot> spotsList;

	    XMLDocument xmlDoc;
	    XMLError eResult = xmlDoc.LoadFile(this->path);

	    XMLCheckResult(eResult);
	    cout << "ErrorID  : " << xmlDoc.ErrorID() <<endl<<"ErrorName: " <<xmlDoc.ErrorName()<<endl;

	    XMLNode * pRoot = xmlDoc.FirstChild();

	    XMLElement * pListElement = pRoot->FirstChildElement("Spot");

	    const char * szAttributeTextID = 0;
	    const char * szAttributeTextStatus = 0;

	    while (pListElement != 0) {

	      szAttributeTextID = pListElement->Attribute("ID");
	      if (szAttributeTextID == 0) cout << XML_ERROR_PARSING_ATTRIBUTE;
	      int id = std::atoi (szAttributeTextID);

	      szAttributeTextStatus = pListElement->Attribute("Status");
	      if (szAttributeTextStatus == 0) cout << XML_ERROR_PARSING_ATTRIBUTE;
	      int status = std::atoi (szAttributeTextStatus);

	      if (x == id || x == status) {
	        Spot p;
	        p.SetStatus(status);
	        p.SetId(id);
	        spotsList.push_back(p);
	      }

	      pListElement = pListElement->NextSiblingElement("Spot");
	    }

	    return spotsList;
	  }

private:
	const char* path ="DAL/Data/ParkingStructure.xml";
	static const char* xml =
					"<?xml version=\"1.0\"?>"
					"<!DOCTYPE PLAY SYSTEM \"\ParkingStructure.dtd\">"
					;

};


