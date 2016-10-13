/*
 * implementation file for Car class
 *
 */

#include "Car.h"

//constructor 
//sets values of private member variables
Car::Car(int ID, string type, int size,string pass)
{
  this->ID = ID;
  this->type = type;
  this->size = size;
  this->pass = pass;
}

Car::~Car(){

}
//sets the name variable
void Car::setID(int ID)
{
  this->ID = ID;
}


//sets the type variable
void Car::setType(string type)
{
  this->type = type;
}

void Car::setPass(string pass)
{
  this->pass = pass;
}
//sets the size variable
void Car::setSize(int size)
{
  this->size = size;
}


//returns the name variable
int Car::getID()
{
  return ID;
}


//returns the type variable
string Car::getType()
{
  return type;
}

string Car::getPass()
{
  return pass;
}
//returns the size variable
int Car::getSize()
{
  return size;
}
