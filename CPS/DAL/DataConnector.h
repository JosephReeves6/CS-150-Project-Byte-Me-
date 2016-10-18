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
#include "../BLL\Spot.h"
#include "../BLL\Car.h"

using namespace std;
using namespace tinyxml2;
static const char* pathPS ="CPS/DAL/Data/ParkingStructure.xml";
static const char* pathCDI ="CPS/DAL/Data/CarAndDriversInfo.xml";


#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("DB connection Error: %i\n", a_eResult); /*return a_eResult;*/ }
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

	void MakeConnectionPS(XMLDocument &xmlDoc){

					    XMLError eResult = xmlDoc.LoadFile(pathPS);
					    //xmlDoc.Parse(xml);
					    XMLCheckResult(eResult);
					    cout << "ErrorID  : " << xmlDoc.ErrorID() <<endl<<"ErrorName: " <<xmlDoc.ErrorName()<<endl;
					}
	void MakeConnectionCDI(XMLDocument &xmlDoc){

						    XMLError eResult = xmlDoc.LoadFile(pathCDI);
						    //xmlDoc.Parse(xml);
						    XMLCheckResult(eResult);
						    cout << "ErrorID  : " << xmlDoc.ErrorID() <<endl<<"ErrorName: " <<xmlDoc.ErrorName()<<endl;
						}

	list<Spot> GetAllSpots(){
			 XMLDocument xmlDoc;
			 MakeConnectionPS(xmlDoc);

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

		list<Car> GetAllCarsInfo(){
			 XMLDocument xmlDoc;
			 MakeConnectionCDI(xmlDoc);

			    XMLNode * pRoot = xmlDoc.FirstChild();
			    XMLElement * pListElement = pRoot->FirstChildElement("Driver");
			    list<Car> carsList;

			    // <Driver ID="3" Type="normal" Size="0" Pass="abc"/>
			    const char * szAttributeTextID = 0;
			    const char * szAttributeTextSize = 0;
			    const char * szAttributeTextType = 0;
			    const char * szAttributeTextPass = 0;


			    while (pListElement != 0) {

			      szAttributeTextID = pListElement->Attribute("ID");
			      if (szAttributeTextID == 0) cout << XML_ERROR_PARSING_ATTRIBUTE;
			      int id = std::atoi (szAttributeTextID);

			      szAttributeTextType = pListElement->Attribute("Type");
			      if (szAttributeTextType == 0) cout << XML_ERROR_PARSING_ATTRIBUTE;
			      string type = (szAttributeTextType);

			      szAttributeTextSize = pListElement->Attribute("Size");
			      if (szAttributeTextSize == 0) cout << XML_ERROR_PARSING_ATTRIBUTE;
			      int size = std::atoi (szAttributeTextSize);

			      szAttributeTextPass = pListElement->Attribute("Pass");
			      if (szAttributeTextPass == 0) cout << XML_ERROR_PARSING_ATTRIBUTE;
			      string pass = (szAttributeTextPass);

			        Car p;

			        p.setID(id);
			        p.setType((string)type);
			        p.setSize(size);
			        p.setPass(pass);

			        carsList.push_back(p);

			      pListElement = pListElement->NextSiblingElement("Driver");
			    }

			    return carsList;
		}

		bool AddNewCar(Car car){
			 XMLDocument xmlDoc;
			MakeConnectionCDI(xmlDoc);
			XMLNode * pRoot = xmlDoc.FirstChild();
			 XMLElement * pListElement = xmlDoc.NewElement("Driver");
		    list<Car> carsList;
		    // <Driver ID="3" Type="normal" Size="0" Pass="abc"/>

		    pListElement->SetAttribute("ID",car.getID());
		    pListElement->SetAttribute("Type",car.getType().c_str());
		    pListElement->SetAttribute("Size",car.getSize());
		    pListElement->SetAttribute("Pass",car.getPass().c_str());

		    pRoot->InsertEndChild(pListElement);

		    XMLError eResult = xmlDoc.SaveFile(pathCDI);
			XMLCheckResult(eResult);
			cout << "ErrorID  : " << xmlDoc.ErrorID() <<endl<<"ErrorName: " <<xmlDoc.ErrorName()<<endl;

			if (xmlDoc.ErrorID()!=0)
				return false;
			else true;

		}

		list<Spot> Query(int x) {
		    list<Spot> spotsList;

		    XMLDocument xmlDoc;
		    MakeConnectionPS(xmlDoc);

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
		        xmlDoc.DeleteNode(pRoot);
		   	    xmlDoc.DeleteChildren();
		   	    xmlDoc.Clear();
		    return spotsList;
		  }

		list<Spot> UpdateSpotStatus(int x,int s) {
	    list<Spot> spotsList;

	    XMLDocument xmlDoc;
	    MakeConnectionPS(xmlDoc);

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
	    xmlDoc.SaveFile(pathPS);
	    spotsList = GetAllSpots();


	    xmlDoc.DeleteNode(pRoot);
	    xmlDoc.DeleteChildren();
	    xmlDoc.Clear();
	    return spotsList;
	  }




};


#endif
