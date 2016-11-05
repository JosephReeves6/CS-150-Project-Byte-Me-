/*
 * file containing the functions for user commands
 */

 #include <vector>
 #include <iterator>
 #include <list>
 #include <queue>
 #include "DataRetriever.h"
 #include "Spot.h"

using namespace std;
std::queue<int> myqueue;


/****************prints out all of the currently available spots in the lot**************************/
void displayAll()
{
	  DataRetriever dataB;
	  list<Spot> spotsList_1 = dataB.GetAllSpots();
 
      cout<<"*********************************************************"<<endl; 
      cout<<"****************  PARKING SPOT LIST  ********************"<<endl;
      cout<<"*********************************************************"<<endl;
 
	  for(list<Spot>::iterator it = spotsList_1.begin(); it!= spotsList_1.end(); ++it) 
	  {
		    Spot spot = *it;
		    cout << "ID: " << spot.GetId() << "\tSTATUS: " << spot.GetStatus() << endl; 
	  } // end of for loop

	 
} // end of displayAll


/*input is an integer to represent the spot that is being left returns 
1 to confirm that the person is leaving a valid spot returns 0 if it was not a valid spot*/
/***************************************** fucntion to leave a spot **********************************/
bool leaveSpot(int x) // int x is the id of the person leaving  
{
   
	DataRetriever dataB;
	list<Spot> spotsList_2 = dataB.UpdateStatus(x,0); // x = id and 0 equals status which means spot is  now  open 
	
	if ( ! myqueue.empty() )
	{
	cout <<"Person with id"<<myqueue.front()<<"was removed from waitlist. Spot was available"<<endl; 
	dataB.UpdateStatus(x, 1); // added
	myqueue.pop();
    //return spot.GetId(); ?? 
	} 

	return 0;
}// end leave spot 


/*returns the next available spot or 0 if there are no spots available */
/*************************fucntion that gets a spot for the user ***********************************/ 
int getSpot(Car x)
{
    string wait;;
 	DataRetriever findSpot;
	list<Spot> spotsList_3 = findSpot.GetAllSpots();

	for(list<Spot>::iterator it = spotsList_3.begin(); it!= spotsList_3.end(); ++it) 
	{
	    Spot spot = *it;
          
     //************** spot open *******************************
	    if (spot.GetStatus() == 0)
        {
            findSpot.UpdateStatus(spot.GetId(), 1); // added
            return spot.GetId();  
        } // end of if


    //********************** spot closed ***************************
	 if ( spot.GetStatus() == 1)
        {
            
            cout <<"The spot you wish to get is not available."<< endl;
            cout <<"Do you wish to wait for the spot to open ? (yes or no)"<<endl;
            cin >> wait ;
          
        	if ( wait == "yes")
          	{
           		myqueue.push (spot.GetId());  /////// id of the car 
            	cout << " You were added to the waitlist. Please wait for your spot to open "<< endl;
          	}// end of if
          
        	else if( wait == "no")
            	return 0 ;
          
        	else
            	cout <<" Input wasnt recognized. Please input a valid argument" << endl;
          
		} // end of if
        
    }// end of for loop

	return -1;
 
}// end of display all function 



