/*
 * file containing the functions for user commands
 */
 #include "Spot.h" //this will allow you to access the member functions from the Spot class
 #include "Car.h" //this will allow you to access the Car class
 #include <vector>
 #include <iterator>
 #include <list>
 #include "tinyxm12.h"
 /* the class name is Spot, and the object being passed to 
 * each function is labeled as x
 */

using namespace std;
using namespace tinyxm12; 
static const char* path = "DAL/ParkingStrucute.xml";


/*returns the next available spot or 0 if there are no spots available */
/*************************fucntion that gets a spot for the user ***********************************/
int getSpot(Spot x, Car y)
{
  XMLDocument dataStruc;
  MakeConnection(dataStruc);
  
  
  XMLNode * pRoot = dataStruc.FirstChild();
  XMLElement * pListElement = pRoot -> FristChildElement("Spot"); 
  list<Spot> spotsList;
  cont char * xmlID = 0;
  const char * xmlStatus = 0;
  
   cout<<"*********************************************************"<<endl; 
   cout<<"************************ GET SPOT  **********************"<<endl;
   cout<<"*********************************************************"<<endl;
  
  int count = 0; // keeps track of the amount of taken parking spots  
 
  while ( pListElement != 0 ){
    
    xmlID = pListElement -> Attribute("ID");
    if( xmlID == 0 ) cout << XML_ERROR_PASSING_ATTRIBUTE;
    int id = std::atoi (xmlID);
    
    xmlStatus = pListElement -> Attribute("Status");
    if( xmlStatus == 0 ) cout << XML_ERROR_PASSING_ATTRIBUTE;
    int status = std::atoi (xmlStatus);
   
    if( status == 1) count ++; 
   
    if( count == 21 ) 
    cout<<"\tThere are no parking spots available at the moment. Please wait for the next available spot."<<endl. 
    
    if( x == id ){
      Spot p;
     p.SetID(id);
     pListElement -> Attribute("Status");
     pListElement ->SetAttribute("Status",1);// set status to 1 meaning spot is taken
     spotsList.push_back(p); 
     break;
    }
    
    pListElement = pListElement -> NextSiblingElement("Spots"); 
  } // end of while 
    return spotsList;
} // end of getspot 





/*input is an integer to represent the spot that is being left returns 
1 to confirm that the person is leaving a valid spot returns 0 if it was not a valid spot*/
/***************************************** fucntion to leave a spot **********************************/
bool leaveSpot(Spot x, int leftSpot)
{
  XMLDocument dataStruc;
  MakeConnection(dataStruc);
  
  
  XMLNode * pRoot = dataStruc.FirstChild();
  XMLElement * pListElement = pRoot -> FristChildElement("Spot"); 
  list<Spot> spotsList;
  cont char * xmlID = 0;
  const char * xmlStatus = 0;
  
   cout<<"*********************************************************"<<endl; 
   cout<<"****************  PARKING SPOT LIST  ********************"<<endl;
   cout<<"*********************************************************"<<endl;
  
  while ( pListElement != 0 ){
    
    xmlID = pListElement -> Attribute("ID");
    if( xmlID == 0 ) cout << XML_ERROR_PASSING_ATTRIBUTE;
    int id = std::atoi (xmlID);
    
    xmlStatus = pListElement -> Attribute("Status");
    if( xmlStatus == 0 ) cout << XML_ERROR_PASSING_ATTRIBUTE;
    int status = std::atoi (xmlStatus);
    
    if ( x == id ){
     pListElement -> Attribute("Status");
     pListElement ->SetAttribute("Status",0);// set status to 0 meaning spot is open
     pRoot -> InsetAfterChild(pListElement,pListElement -> NextSiblingElement("Spot"));
     break;
    }// end if
    
    pListElement = pListElement -> NextSiblingElement("Spots"); 
  }// end while 
    
    xmlDoc.InsertEndChild(pRoot); // ?
    xmlDoc.SaveFile(path);
    spotsList = GetAllSpots();
 
    xmlDoc.DeleteNode(pRoot);  // ?
    xmlDoc.DeleteChildren();
    xmlDoc.Clear()
     
    return spotsList;
}// end leave spot 




/****************prints out all of the currently available spots in the lot**************************/
void displayAll()
{
  XMLDocument dataStruc;
  MakeConnection(dataStruc);
  
  
  XMLNode * pRoot = dataStruc.FirstChild();
  XMLElement * pListElement = pRoot -> FristChildElement("Spot"); 
  list<Spot> spotsList;
  cont char * xmlID = 0;
  const char * xmlStatus = 0;
  
   cout<<"*********************************************************"<<endl; 
   cout<<"****************  PARKING SPOT LIST  ********************"<<endl;
   cout<<"*********************************************************"<<endl;
  
  while ( pListElement != 0 ){
    
    xmlID = pListElement -> Attribute("ID");
    if( xmlID == 0 ) cout << XML_ERROR_PASSING_ATTRIBUTE;
    int id = std::atoi (xmlID);
    
    xmlStatus = pListElement -> Attribute("Status");
    if( xmlStatus == 0 ) cout << XML_ERROR_PASSING_ATTRIBUTE;
    int status = std::atoi (xmlStatus);
    
    cout<<"ID: "<< id <<"\tStatus: "<< status <<endl; 
    spotsList.push_back(p); 
    
    pListElement = pListElement -> NextSiblingElement("Spots"); 
  } // end of while 
    return spotsList;
}// end of display all function 



