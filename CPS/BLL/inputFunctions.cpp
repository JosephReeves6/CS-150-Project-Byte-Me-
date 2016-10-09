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
  //function code
}




/*input is an integer to represent the spot that is being left returns 
1 to confirm that the person is leaving a valid spot returns 0 if it was not a valid spot*/
/***************************************** fucntion to leave a spot **********************************/
bool leaveSpot(Spot x, int leftSpot)
{
  //function code
}



/****************prints out all of the currently available spots in the lot**************************/
void displayAll(Spot x)
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
  }
    return spotsList;
}
}// end of display all 
