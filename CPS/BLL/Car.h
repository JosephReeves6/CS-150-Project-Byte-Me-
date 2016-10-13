/*
 * header file for Car class
 *
 */

#ifndef CAR_H
#define CAR_H
#include <string>
using namespace std;

class Car
{
 private:
  //name is the driver's name
  //type refers to normal, handicap, privelaged, etc...
  //size is an int; 1 is compact, 2 is normal, 3 is oversized
  string type,pass;
  int size, ID;

 public:
  //Constructor
  //sets type to normal and size to 2 which is normal, if there is no input
  Car(int ID = 0, string type = "normal", int size = 2,string pass = "");
  ~Car();
  void setPass(string pass);
  //set functions
  //setName() takes a string and assigns it to the name variable of the object
  void setID(int ID); 

  //setType() takes a string and assigns it to the type variable of the object
  void setType(string type);

  //setSize() takes an int and assigns it to the size variable of the object  
  void setSize(int size);

  //get functions

  string getPass();
  //getName() returns the name member variable
  int getID();

  //getType() returns the type member variable
  string getType();

  //getSize() returns the size memebr variable
  int getSize();
};

#endif
