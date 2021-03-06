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


/****************prints out all of the currently available spots in the lot**************************/
void displayAll()
{		
	  // declaring a class object 
	  DataRetriever dataB;
	  list<Spot> spotsList_1 = dataB.GetAllSpots();
	
	  char spotdisplay[20];
	  int statusdisplay[21];
	  int w = 0;
 
      cout<<"*********************************************************"<<endl; 
      cout<<"****************  PARKING SPOT LIST  ********************"<<endl;
      cout<<"*********************************************************"<<endl;
 
	 // This section is going through our list of Spots and is printing the ID with its corresponding status
	 // until it reaches the end of the list. 
	  for(list<Spot>::iterator it = spotsList_1.begin(); it!= spotsList_1.end(); ++it) 
	  {
		    Spot spot = *it;
		    cout << "ID: " << spot.GetId() << "\tSTATUS: " << spot.GetStatus() << endl; 
		  
		    statusdisplay[w] = spot.GetStatus();
		    w++;
	  } // end of for loop

	 	  int i = 0;

	  while(i<=20)
	  		{
	  			if(statusdisplay[i] == 1)
	  			{
	  				spotdisplay[i] = '*';
	  			}
	  			else
	  			{
	  				spotdisplay[i] = ' ';
	  			}

	  			i++;
	  		}

	  		char grid[41][27] = {{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
	  				             {'|','|',spotdisplay[0],spotdisplay[0],spotdisplay[0],'|','|',spotdisplay[1],spotdisplay[1],spotdisplay[1],'|','|',spotdisplay[2],spotdisplay[2],spotdisplay[2],'|','|','_','_','_','|','|'},
	  		                     {'|','|',spotdisplay[0],spotdisplay[0],spotdisplay[0],'|','|',spotdisplay[1],spotdisplay[1],spotdisplay[1],'|','|',spotdisplay[2],spotdisplay[2],spotdisplay[2],'|','|',spotdisplay[3],spotdisplay[3],spotdisplay[3],'|','|'},
	  		                     {'|','|',spotdisplay[0],spotdisplay[0],spotdisplay[0],'|','|',spotdisplay[1],spotdisplay[1],spotdisplay[1],'|','|',spotdisplay[2],spotdisplay[2],spotdisplay[2],'|','|',spotdisplay[3],spotdisplay[3],spotdisplay[3],'|','|'},
	  		                     {'|','|',spotdisplay[0],spotdisplay[0],spotdisplay[0],'|','|',spotdisplay[1],spotdisplay[1],spotdisplay[1],'|','|',spotdisplay[2],spotdisplay[2],spotdisplay[2],'|','|',spotdisplay[3],spotdisplay[3],spotdisplay[3],'|','|'},
	  							 {' ',' ',' ','1',' ',' ',' ',' ','2',' ',' ',' ',' ','3',' ',' ',' ',' ','4'},
	  							 {' '},
	  							 {'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
	  							 {'|','|',spotdisplay[4],spotdisplay[4],spotdisplay[4],'|','|',spotdisplay[5],spotdisplay[5],spotdisplay[5],'|','|',spotdisplay[6],spotdisplay[6],spotdisplay[6],'|','|','_','_','_','|','|'},
	  							 {'|','|',spotdisplay[4],spotdisplay[4],spotdisplay[4],'|','|',spotdisplay[5],spotdisplay[5],spotdisplay[5],'|','|',spotdisplay[6],spotdisplay[6],spotdisplay[6],'|','|',spotdisplay[7],spotdisplay[7],spotdisplay[7],'|','|'},
	  							 {'|','|',spotdisplay[4],spotdisplay[4],spotdisplay[4],'|','|',spotdisplay[5],spotdisplay[5],spotdisplay[5],'|','|',spotdisplay[6],spotdisplay[6],spotdisplay[6],'|','|',spotdisplay[7],spotdisplay[7],spotdisplay[7],'|','|'},
	  							 {'|','|',spotdisplay[4],spotdisplay[4],spotdisplay[4],'|','|',spotdisplay[5],spotdisplay[5],spotdisplay[5],'|','|',spotdisplay[6],spotdisplay[6],spotdisplay[6],'|','|',spotdisplay[7],spotdisplay[7],spotdisplay[7],'|','|'},
	  							 {' ',' ',' ','5',' ',' ',' ',' ','6',' ',' ',' ',' ','7',' ',' ',' ',' ','8'},
	  							 {' '},
	  							 {'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
	  							 {'|','|',spotdisplay[8],spotdisplay[8],spotdisplay[8],'|','|',spotdisplay[9],spotdisplay[9],spotdisplay[9],'|','|',spotdisplay[10],spotdisplay[10],spotdisplay[10],'|','|','_','_','_','|','|'},
	  							 {'|','|',spotdisplay[8],spotdisplay[8],spotdisplay[8],'|','|',spotdisplay[9],spotdisplay[9],spotdisplay[9],'|','|',spotdisplay[10],spotdisplay[10],spotdisplay[10],'|','|',spotdisplay[11],spotdisplay[11],spotdisplay[11],'|','|'},
	  							 {'|','|',spotdisplay[8],spotdisplay[8],spotdisplay[8],'|','|',spotdisplay[9],spotdisplay[9],spotdisplay[9],'|','|',spotdisplay[10],spotdisplay[10],spotdisplay[10],'|','|',spotdisplay[11],spotdisplay[11],spotdisplay[11],'|','|'},
	  							 {'|','|',spotdisplay[8],spotdisplay[8],spotdisplay[8],'|','|',spotdisplay[9],spotdisplay[9],spotdisplay[9],'|','|',spotdisplay[10],spotdisplay[10],spotdisplay[10],'|','|',spotdisplay[11],spotdisplay[11],spotdisplay[11],'|','|'},
	  							 {' ',' ',' ','9',' ',' ',' ',' ','1','0',' ',' ',' ','1','1',' ',' ',' ','1', '2'},
	  							 {' '},
	  							 {'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
	  							 {'|','|',spotdisplay[12],spotdisplay[12],spotdisplay[12],'|','|',spotdisplay[13],spotdisplay[13],spotdisplay[13],'|','|',spotdisplay[14],spotdisplay[14],spotdisplay[14],'|','|','_','_','_','|','|'},
	  							 {'|','|',spotdisplay[12],spotdisplay[12],spotdisplay[12],'|','|',spotdisplay[13],spotdisplay[13],spotdisplay[13],'|','|',spotdisplay[14],spotdisplay[14],spotdisplay[14],'|','|',spotdisplay[15],spotdisplay[15],spotdisplay[15],'|','|'},
	  							 {'|','|',spotdisplay[12],spotdisplay[12],spotdisplay[12],'|','|',spotdisplay[13],spotdisplay[13],spotdisplay[13],'|','|',spotdisplay[14],spotdisplay[14],spotdisplay[14],'|','|',spotdisplay[15],spotdisplay[15],spotdisplay[15],'|','|'},
	  							 {'|','|',spotdisplay[12],spotdisplay[12],spotdisplay[12],'|','|',spotdisplay[13],spotdisplay[13],spotdisplay[13],'|','|',spotdisplay[14],spotdisplay[14],spotdisplay[14],'|','|',spotdisplay[15],spotdisplay[15],spotdisplay[15],'|','|'},
	  							 {' ',' ',' ','1','3',' ',' ',' ','1','4',' ',' ',' ','1','5',' ',' ',' ','1', '6'},
	  							 {' '},
	  							 {'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
	  							 {'|','|',spotdisplay[16],spotdisplay[16],spotdisplay[16],spotdisplay[16],'|','|',spotdisplay[17],spotdisplay[17],spotdisplay[17],spotdisplay[17],'|','|',spotdisplay[18],spotdisplay[18],spotdisplay[18],spotdisplay[18],'|','|',spotdisplay[19],spotdisplay[19],spotdisplay[19],spotdisplay[19],'|','|'},
	  							 {'|','|',spotdisplay[16],spotdisplay[16],spotdisplay[16],spotdisplay[16],'|','|',spotdisplay[17],spotdisplay[17],spotdisplay[17],spotdisplay[17],'|','|',spotdisplay[18],spotdisplay[18],spotdisplay[18],spotdisplay[18],'|','|',spotdisplay[19],spotdisplay[19],spotdisplay[19],spotdisplay[19],'|','|'},
	  							 {'|','|',spotdisplay[16],spotdisplay[16],spotdisplay[16],spotdisplay[16],'|','|',spotdisplay[17],spotdisplay[17],spotdisplay[17],spotdisplay[17],'|','|',spotdisplay[18],spotdisplay[18],spotdisplay[18],spotdisplay[18],'|','|',spotdisplay[19],spotdisplay[19],spotdisplay[19],spotdisplay[19],'|','|'},
	  							 {'|','|',spotdisplay[16],spotdisplay[16],spotdisplay[16],spotdisplay[16],'|','|',spotdisplay[17],spotdisplay[17],spotdisplay[17],spotdisplay[17],'|','|',spotdisplay[18],spotdisplay[18],spotdisplay[18],spotdisplay[18],'|','|',spotdisplay[19],spotdisplay[19],spotdisplay[19],spotdisplay[19],'|','|'},
	  							 {' ',' ',' ','1','7',' ',' ',' ',' ','1','8',' ',' ',' ',' ','1','9',' ',' ',' ',' ','2', '0'},
	  							 {' '},
	  							 {'_','_','_','_','_','_','_','_'},
	  							 {'|','|',spotdisplay[20],spotdisplay[20],spotdisplay[20],spotdisplay[20],'|','|'},
	  							 {'|','|',spotdisplay[20],spotdisplay[20],spotdisplay[20],spotdisplay[20],'|','|'},
	  							 {'|','|',spotdisplay[20],spotdisplay[20],spotdisplay[20],spotdisplay[20],'|','|'},
	  							 {'|','|',spotdisplay[20],spotdisplay[20],spotdisplay[20],spotdisplay[20],'|','|'},
	  		                     {' ',' ',' ','2','1'}};


	  		for (int i =0; i < 41; i ++)
	  		{
	  			for (int j =0; j < 27; j++)
	  			{
	  				cout << grid[i][j];
	  			}

	  			cout << endl;
	  		}

} // end of displayAll


/*input is an integer to represent the spot that is being left returns 
1 to confirm that the person is leaving a valid spot returns 0 if it was not a valid spot*/
/***************************************** fucntion to leave a spot **********************************/
bool leaveSpot(int x, queue<int>& myqueue) // int x is the spot of the person leaving  
{
   
	DataRetriever dataB;
	list<Spot> spotsList_2 = dataB.UpdateStatus(x,0);
	
	if ( ! myqueue.empty() )
	{
	cout <<"Person with id"<<myqueue.front()<<"was removed from waitlist. Spot "<< x << " was available"<<endl; 
	dataB.UpdateStatus(x, 1);
	myqueue.pop();
	} 

	return 0;
}// end leave spot 


/*returns the next available spot or 0 if there are no spots available */
/*************************fucntion that gets a spot for the user ***********************************/ 
int getSpot(Car x, queue<int>& myqueue)
{
    string wait;
 	DataRetriever findSpot;
	list<Spot> spotsList_3 = findSpot.GetAllSpots();

	for(list<Spot>::iterator it = spotsList_3.begin(); it!= spotsList_3.end(); ++it) 
	{
	    Spot spot = *it;
          
    //************** spot open *******************************
    //If a spot is open update the status of the parking spot with the users id and input a 1 
    //which means the spot is taken. 
	    if (spot.GetStatus() == 0)
       		 {
           		 findSpot.UpdateStatus(spot.GetId(), 1);
           		 return spot.GetId();  
        	} // end of if
		
	}// end of for loop


    //********************** spot closed ***************************
    //If the program reaches this part it means that there was no avialable spot. Therefore, it as 
    //the user if it want to wait for a spot to open. Upon request the user is pused into a queue. 
	    cout <<"The spot you wish to get is not available."<< endl;
            cout <<"Do you wish to wait for the spot to open ? (yes or no)"<<endl;
            cin >> wait ;
          
            do 
	    {
	    if ( wait == "yes")
          	{
           		myqueue.push (x.getID());  
            		cout << " You were added to the waitlist. Please wait for your spot to open "<< endl;
			return -1;
          	}// end of if
		 
            else if( wait == "no")
            		return -1 ;
          
            else
            		cout <<" Input wasnt recognized. Please input a valid argument" << endl;
	    } while (true);
	
        
	return -1;
 
}// end of display all function 



