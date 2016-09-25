/*
 * DataConnector.h
 *
 *  Created on: Sep 21, 2016
 *      Author: ByteMe Team
 */
#ifndef DataConnector_h
#define DataConnector_h

#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include "tinyxml2.h"
#include "..\BLL\Spot.h"

using namespace std;
using namespace tinyxml2;
static const char* path ="DAL/Data/ParkingStructure.xml";


#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); /*return a_eResult;*/ }
#endif
/*
static const char* xml =
					"<?xml version=\"1.0\"?>"
					"<!DOCTYPE PLAY SYSTEM \"\ParkingStructure.dtd\">"
					;
*/

class DataConnector {


public:
	DataConnector(){};
	virtual ~DataConnector(){};
		void MakeConnection(XMLDocument &xmlDoc){

		    XMLError eResult = xmlDoc.LoadFile(path);
		    //xmlDoc.Parse(xml);
		    XMLCheckResult(eResult);
		    cout << "ErrorID  : " << xmlDoc.ErrorID() <<endl<<"ErrorName: " <<xmlDoc.ErrorName()<<endl;
		}
		list<Spot> GetAllSpots(){
			 XMLDocument xmlDoc;
			 MakeConnection(xmlDoc);

			    XMLNode * pRoot = xmlDoc.FirstChild();
			    XMLElement * pListElement = pRoot->FirstChildElement("Spot");
			    list<Spot> spotsList;
			    const char * szAttributeTextID = 0;
			    const char * szAttributeTextStatus = 0;

			    while (pListElement != 0) {

			      szAttributeTextID = pListElement->Attribute("ID");
			      if (szAttributeTextID == 0) cout << XML_ERROR_PARSING_ATTRIBUTE;
			      int id = std::atoi (szAttributeTextID);

			      szAttributeTextStatus = pListElement->Attribute("Status");
			      if (szAttributeTextStatus == 0) cout << XML_ERROR_PARSING_ATTRIBUTE;
			      int status = std::atoi (szAttributeTextStatus);
			        Spot p;
			        p.SetStatus(status);
			        p.SetId(id);
			        spotsList.push_back(p);

			      pListElement = pListElement->NextSiblingElement("Spot");
			    }

			    return spotsList;
		}

		list<Spot> Query(int x) {
		    list<Spot> spotsList;

		    XMLDocument xmlDoc;
		    MakeConnection(xmlDoc);

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
		        break;
		      }

		      pListElement = pListElement->NextSiblingElement("Spot");
		    }

		    return spotsList;
		  }

		list<Spot> UpdateSpotStatus(int x,int s) {
	    list<Spot> spotsList;

	    XMLDocument xmlDoc;
	    MakeConnection(xmlDoc);

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
	    	  //pListElement->SetAttribute("Status",s);
	    	  pListElement->Attribute("Status");
	    	  pListElement->SetAttribute("Status",s);
	    	  pRoot->InsertAfterChild(pListElement,pListElement->NextSiblingElement("Spot"));
	    	  //pRoot->InsertEndChild();

	    	  break;
	      }

	      pListElement = pListElement->NextSiblingElement("Spot");
	    }
	    xmlDoc.InsertEndChild(pRoot);
	    xmlDoc.SaveFile(path);
	    spotsList = GetAllSpots();


	    xmlDoc.DeleteNode(pRoot);
	    xmlDoc.DeleteChildren();
	    xmlDoc.Clear();
	    return spotsList;
	  }



};


#endif
