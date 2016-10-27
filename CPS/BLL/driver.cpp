// Name: driver.cpp
// Car Parking Service
// Author: Byte Me
// Created on October 9, 2016
//
// In the following file, it will ask if the user is new or returning.
// In the case that it is a new user, the program will assign a new ID and
// create an object for the users' car to store in the data base. If it a
// returning user,the program will ask for the user's ID*/
//

#include <iostream>
#include <istream>
#include "Spot.h" //////// changed
#include "Car.h"  ////// changed
#include "DataRetriever.h" //// changed
#include <list>

using namespace std;
void displayAll();
bool leaveSpot(int x);
int getSpot( Car x);
Car newuser(int ID);

void userInput(Car car);

int main(void){
    bool running = true;
    int choice, tempID;
    int j = 0;
    Car tempCar;
    DataRetriever Data; //// changed
    
    list<Car> carList = Data.GetAllCarsInfo();/*****a function that returns the list of cars from XML File****/   /// get all spots ????
    string IDs[100]; //array of IDs for security purposes
    
    for (int i = 0; i < 100; ++i) {
        IDs[i] = "";
    }
    
    //set IDs from carList to true
    for (list<Car>::iterator i = carList.begin(); i != carList.end() ; ++i)
    {
        IDs[i->getID()] = i->getPass();  /// changed
    }
    
    
    //Main Menu for program
    do {
        cout << "Welcome!" << endl;
        cout << "Please select the following:\n" << endl;
        cout << "1 - Returning User" << endl;
        cout << "2 - New User" << endl;
        cout << "3 - Exit\n" << endl;
        
        cin >> choice;
        
        //Ask user if they have app before or would like to exit app
        switch (choice)
        {
            case 1:
            {
                cout << endl << "Login:\n" << endl;
                cout << "User ID" << endl;
                cin >> tempID;
                
                //check if ID is in the system
                if (tempID > 999 || IDs[tempID] == "") //// changed to true
                {
                    cout << "Error: Invalid User ID" << endl;
                }
                else
                {
                    cout << "Valid user ID. Retrieving Information" << endl;
                    
                    for (Car i : carList)
                    {
                        if (i.getID() == tempID)
                        {
                            tempCar = i;
                            break;
                        }
                    }
                    string pass;
                    cout << "Input Password:" << endl;
                    cin >> pass;
                    
                    if (pass != tempCar.getPass())
                    {
                        cout << "Incorrect password" << endl;
                        break;
                    }
                    
                    cout << "Password Verified" << endl;
                    
                    //verify information
                    cout << "size: " << tempCar.getSize() << " type: " << tempCar.getType() << endl;
                    
                    //allow user to access the program functions
                    userInput(tempCar);
                    
                }
            }
                break;
            case 2:
            {
                cout << endl << "Sign up:\n" << endl;
                
                //get a new ID to send to the user that is not already active
                while (IDs[j] != "") /// changed to true
                    j++;
                
                //create a new car for the user
                tempCar = newuser(j);
                
                //add new car to the list
                carList.push_back(tempCar);
                
                //add car to XML file
                Data.AddNewCar(tempCar); /////// ?????????????
                
                //add ID to the IDs array
                IDs[j] = true; /// changed to true
                
                //allow user to access the program functions
                userInput(tempCar);
                
                
            }
                break;
            case 3:
                running = false; //Exits app if selected
                break;
            default:
                cout << "Invalid entry. Please reenter" << endl;
                break;
        }
    } while (running); //Keeps running until User select exit
    
    return 0;
}

Car newuser(int ID)
{
    Car car;
    
    string type, pass;
    int size;
    
    cout << "Your driver ID is: " << ID;
    cout << endl;
    
    cout << "Please enter type of car: ";
    cin >> type;
    cout << endl;
    
    cout << "Please enter size compact(0) or normal(1) or oversized(2): ";
    cin >> size;
    cout << endl;
    
    cout << "Please enter a password with 7 characters: ";
    cin >> pass;
    cout << endl;
    
    //call function
    car.setID(ID);
    car.setType(type);
    car.setSize(size);
    car.setPass(pass);
    
    return car;
}

void userInput(Car car)
{
    int choice;
    
    cout << "Please select the following:\n" << endl;
    cout << "1 - Get Spot" << endl;
    cout << "2 - Leave Spot" << endl;
    cout << "3 - Print all Spots" << endl;
    cout << "4 - Leave the program" << endl;
    
    cin >> choice; /////////////// changed
    
    switch(choice)
    {
        case 1:
        {
            int s = getSpot(car); //////////????????
            cout <<"your spot is "<< s << endl;  //////////// changed
        }
            break;
            
        case 2:
        {
            int x;
            cout << "Enter the spot you are leaving:" << endl;
            cin >> x;
            leaveSpot(x);  /////////// ????????????
        }
            break;
            
        case 3:
        {
            displayAll(); //////////// ??????????????
            userInput(car);
        }
            break;
            
        case 4:
            cout << "Leaving program" << endl;
            break;
            
        default:
        {
            cout << "Error: invalid input "<< endl; ///////// changed
            userInput(car);
        }
            break;
    }
    
    return;
    
}

