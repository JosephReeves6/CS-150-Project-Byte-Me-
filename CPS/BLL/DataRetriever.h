/*
 * DataRetriever.h
 *
 *  Created on: Sep 21, 2016
 *      Author: ByteMe Team
 */
#ifndef DataRetriever_h
#define DataRetriever_h

#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include "../DAL/DataConnector.h"
#include "Spot.h"
#include "Car.h"

using namespace std;

class DataRetriever {


public:
	DataRetriever(){};

	list<Spot> GetSpotByID(int id) {
	    return temp.Query(id);
	  }

	list<Spot> GetAllSpots(){
		return temp.GetAllSpots();
	}

	list<Car> GetAllCarsInfo(){
		return temp.GetAllCarsInfo();
	}

	bool AddNewCar(Car car){
		return temp.AddNewCar(car);
	}

	list<Spot> UpdateStatus(int spotId,int status){
			this->spotsList = temp.UpdateSpotStatus(spotId,status);
			return spotsList;
		}

private:
	list<Spot> spotsList;
	DataConnector temp;

};

#endif
