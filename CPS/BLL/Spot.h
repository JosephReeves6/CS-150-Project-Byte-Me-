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
	Spot();
	virtual ~Spot();
	void SetId(int id) {
	  this->id = id;
	}

	void SetStatus(int status) {
	  this->status = status;
	}

	int GetId() {
	  return this->id;
	}

	int GetStatus() {
	  return this->status;
	}

private:
	  int id;
	  int status;
};




#endif
