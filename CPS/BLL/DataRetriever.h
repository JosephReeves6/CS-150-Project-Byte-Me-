/*
 * DataRetriever.h
 *
 *  Created on: Sep 21, 2016
 *      Author: ByteMe Team
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include "../DAL/DataConnector.h"

#include "Spot.h"

using namespace std;

class DataRetriever {


public:
	DataRetriever(){};

	list<Spot> Query(int x) {

		DataConnector temp;
		this->spotsList = temp.Query(x);
	    return spotsList;
	  }


private:
	list<Spot> spotsList;

};


