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
#include "BLL/Car.h"


using namespace std;

int main() {
/*
//{testStart: Get a spot by ID.
	DataRetriever findSpot;
	Spot spot;
	list<Spot> spotsList = findSpot.GetSpotByID(5);

	  for(list<Spot>::iterator it = spotsList.begin(); it!= spotsList.end(); ++it) {
	    Spot spot = *it;
	    cout << "ID: " << spot.GetId() << " STATUS: " << spot.GetStatus() << endl;
	  }
// testEnd: Get a spot by ID.}

//{testStart: Get All spots.
	  list<Spot> spotsList2 = findSpot.GetAllSpots();

	  for(list<Spot>::iterator it = spotsList2.begin(); it!= spotsList2.end(); ++it) {
		    Spot spot = *it;
		    cout << "ID: " << spot.GetId() << " STATUS: " << spot.GetStatus() << endl;
		  }
// testEnd: Get All spots.}
*/


/*
//{testStart: Update a spot by ID.
	DataConnector x;
	list<Spot> spotsList3 = x.UpdateSpotStatus(3,5);

	for(list<Spot>::iterator it = spotsList3.begin(); it!= spotsList3.end(); ++it) {
			    Spot spot = *it;
			    cout << "ID: " << spot.GetId() << " STATUS: " << spot.GetStatus() << endl;
			  }
			  */


/*
//Get All Cars Info
	DataRetriever x;
	  list<Car> carsList1 = x.GetAllCarsInfo();

	  for(list<Car>::iterator it = carsList1.begin(); it!= carsList1.end(); ++it) {
		    Car car = *it;
		    cout << "Car ID: " << car.getID()
		    	 <<" SIZE: " <<car.getSize()
		         <<" TYPE: " << car.getType()
		         <<" PASS: " << car.getPass()
				 << endl;
		  }
// testEnd: Update a spot by ID.}
 *
 */
    //<Driver ID="3" Type="normal" Size="0" Pass="abc"/>

	DataRetriever x;
	Car car;
	car.setID(11);
	car.setType("normal");
	car.setSize(1);
	car.setPass("123456abcs");
	x.AddNewCar(car);

	return 0;
}

