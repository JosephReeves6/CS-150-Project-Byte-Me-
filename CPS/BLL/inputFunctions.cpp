/*
 * file containing the functions for user commands
 */

 #include <vector>
 #include <iterator>
 #include <list>
 #include "DataRetriever.h"
 #include "Spot.h"

using namespace std;


/****************prints out all of the currently available spots in the lot**************************/
void displayAll()
{
	  DataRetriever dataB;
	  list<Spot> spotsList_1 = dataB.GetAllSpots();
 
      cout<<"*********************************************************"<<endl; 
      cout<<"****************  PARKING SPOT LIST  ********************"<<endl;
      cout<<"*********************************************************"<<endl;
 
	  for(list<Spot>::iterator it = spotsList_1.begin(); it!= spotsList_1.end(); ++it) {
		    Spot spot = *it;
		    cout << "ID: " << spot.GetId() << "\tSTATUS: " << spot.GetStatus() << endl; 
	  } // end of for loop

	 
} // end of getspot 


/*input is an integer to represent the spot that is being left returns 
1 to confirm that the person is leaving a valid spot returns 0 if it was not a valid spot*/
/***************************************** fucntion to leave a spot **********************************/
bool leaveSpot(int x) // int x is the id of the person leaving  
{
   
	DataRetriever dataB;
	list<Spot> spotsList_2 = dataB.UpdateStatus(x,0); // x = id and 0 equals status which means spot is  now  open  ////// changed

	for(list<Spot>::iterator it = spotsList_2.begin(); it!= spotsList_2.end(); ++it) {
			    Spot spot = *it;
			    cout << "ID: " << spot.GetId() << " STATUS: " << spot.GetStatus() << endl;
			  }
return 0;
}// end leave spot 


/*returns the next available spot or 0 if there are no spots available */
/*************************fucntion that gets a spot for the user ***********************************/ 
int getSpot(Car x)
{

 	DataRetriever findSpot;
	list<Spot> spotsList_3 = findSpot.GetAllSpots(); //// changed
	  for(list<Spot>::iterator it = spotsList_3.begin(); it!= spotsList_3.end(); ++it) {
	    Spot spot = *it;
	    if (spot.GetStatus() == 0) ///// changed
        {
            findSpot.UpdateStatus(spot.GetId(), 1);
		    return spot.GetId(); /////// changed
        }
	  }
	return -1;
 
}// end of display all function 



