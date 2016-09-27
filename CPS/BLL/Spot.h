/*
 * Spot.h
 *
 *  Created on: Sep 22, 2016
 *      Author: ByteMe Team
 */

#ifndef SPOT_H
#define SPOT_H



class Spot {
public:
	
	//Constructor. Sets the ID and status according to the parameters. 
	Spot(){
		this->id =0;
		this->status=0;
	}

	// Function to set the ID of a specific spot in the parking lot.
	void SetId(int id) {
	  this->id = id;
	}

	// Function to set the status of a parking spot. Either its empty 
	// taken or will be available soon. 
	void SetStatus(int status) {
	  this->status = status;
	}

	// Function to retrieve the ID of the parking spot.
	int GetId() {
	  return this->id;
	}

	// Function to retrieve the Status of the parking spot.
	int GetStatus() {
	  return this->status;
	}

private:
	  int id;	// Stores the id of the parking spot.
	  int status;	/* Stores the status of the parking spot either represented 
			 by a 0,1, or 2. 0 corresponding to open 1 taken and 2 soon 
			 available.*/ 
};




#endif
