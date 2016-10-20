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
  EncryptDec(pass);
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

void Car::EncryptDec(string &toEncrypt) {
    char key[3] = {'K', 'C', 'Q'}; //Any chars will work, in an array of any size
    string output = toEncrypt;

    for (int i = 0; i < toEncrypt.size(); i++)
        output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];

    toEncrypt =output;
}

void Car::Encrypt(string &strTarget)
{
	unsigned char strTar[strTarget.size()];
	unsigned char *val=new unsigned char[strTarget.length()];
	strcpy((char *)val,strTarget.c_str());
	strcpy((char *)strTar, (char *)val);

	strTar[6] = 0xFF; strTar[1] = 0x61; strTar[5] = 0x31; strTar[2] = 0x62; strTar[4] = 0x30; strTar[0] = 0x60; strTar[3] = 0x63;

	for (unsigned int EKYtR = 0, TKlah = 0; EKYtR < 7; EKYtR++)
	{
	        TKlah = strTar[EKYtR];
	        TKlah ++;
	        strTar[EKYtR] = TKlah;

	}

	strTarget = string((char*)strTar);


}
