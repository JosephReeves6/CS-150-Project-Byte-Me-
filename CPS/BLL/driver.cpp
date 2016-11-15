// Name: driver.cpp
// Car Parking Service Simulation
// Author: Byte Me
// Created on October 9, 2016
//
// This program will simulate a parking service which allows users secure entry/
// the ability to get and leave spots/ as well as the ability to display the entire
// parking lot.
//
// In the following file, it will ask if the user is new or returning.
// In the case that it is a new user, the program will assign a new ID and
// create an object for the users' car to store in the data base. If it a
// returning user,the program will ask for the user's ID and password
// The next step is to prompt the user with three options
//      displayAll  - which displays the parking lot
//      getSpot     - which returns the next open spot
//          if no open spot is availiable the user can choose to go
//          into a queue and wait for a spot to open up
//      leaveSpot   - which causes the spot to become vacant in the database
// The program will continue to run until a user ends it.

#include <iostream>
#include <istream>
#include "Spot.h"           //include the Spot class
#include "Car.h"            //include the Car class
#include "DataRetriever.h"  //include the DataRetriever class
#include <list>
#include <queue>

using namespace std;

//FUNCTION DECLARATIONS

//functions from InputFunctions.cpp file
void displayAll();
bool leaveSpot(int x, queue<int> myqueue);
int getSpot( Car x, queue<int> myqueue);

Car newuser(int ID);
queue<int> waitqueue;
void userInput(Car car);


//begin main function
int main(void){
    bool running = true;
    int choice, tempID;
    int j = 0;
    Car tempCar;
    DataRetriever Data; 
    
    
    list<Car> carList = Data.GetAllCarsInfo();/*****a function that returns the list of cars from XML File****/ 
    string IDs[100]; //array of passwords with index as ID for security purposes
    
    //set all initial passwords to "/0"
    for (int i = 0; i < 100; ++i) {
        IDs[i] = "/0";
    }
    
    //set Passwords from carList with the ID as the index
    for (list<Car>::iterator i = carList.begin(); i != carList.end() ; ++i)
    {
        IDs[i->getID()] = i->getPass();  /// changed
    }
    
    
    //Main interface for parking lot users
    //will not terminate until prompted by user
    do {
        cout << "Welcome!" << endl;
        cout << "Please select the following:\n" << endl;
        cout << "1 - Returning User" << endl;
        cout << "2 - New User" << endl;
        cout << "3 - Exit\n" << endl;
        
        cin >> choice;
        
       
        switch (choice)
        {
                /*
                    Returning User:
                    -Get ID from user and check to make sure it is a valid ID
                    -Retrieve Car object based on ID, and ask user to input the password
                    -verification complete, move forward to user input
                */
            case 1:
            {
                cout << endl << "Login:\n" << endl;
                cout << "User ID" << endl;
                cin >> tempID;
                
                //check if ID is in the system
                if (tempID > 999 || IDs[tempID] == "/0") 
                {
                    cout << "Error: Invalid User ID" << endl;
                }
                else //ID is valid
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
                    
                    Car tempPass;
                    tempPass.setPass(pass);
                    
                    if (tempPass.getPass() != tempCar.getPass())
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
                
            /*
                    New User:
                    -send a valid ID to the newuser function which creates a Car object for the new user
                    -call the user input function
                */
            case 2:
            {
                cout << endl << "Sign up:\n" << endl;
                
                //get a new ID to send to the user that is not already active
                while (IDs[j] != "/0") 
                    j++;
                
                //create a new car for the user
                tempCar = newuser(j);
                
                //add new car to the list
                carList.push_back(tempCar);
                
                //add car to XML file
                Data.AddNewCar(tempCar); /////// ?????????????
                
                //add ID to the IDs array
                IDs[j] = tempCar.getPass(); /// changed to true
                
                //allow user to access the program functions
                userInput(tempCar);
                
                
            }
                break;
            case 3://exit
                running = false; //Exits app if selected
                break;
            default:
                cout << "Invalid entry. Please reenter" << endl;
                break;
        }
    } while (running); //Keeps running until User select exit
    
    return 0;
}

/*
    FUNCTION newuser takes a valid ID as input, which will be displayed to the new user as their
    new ID. The User is then prompted to fill out the various aspects of the Car class and finally
    a Car object is created with teh user's inputs and returned at the end of the function. 
*/
Car newuser(int ID)
{
    Car car;
    
    string type, pass;
    int size;
    
    //display the new user's ID
    cout << "Your driver ID is: " << ID;
    cout << endl;
    
    //get car type from new user
    cout << "Please enter type of car: ";
    cin >> type;
    cout << endl;
    
    //get car size from new user
    cout << "Please enter size compact(0) or normal(1) or oversized(2): ";
    cin >> size;
    cout << endl;
    
    //get password from new user
    cout << "Please enter a password with 7 characters: ";
    cin >> pass;
    cout << endl;
    
    //create a Car object with the given new user inputs
    car.setID(ID);
    car.setType(type);
    car.setSize(size);
    car.setPass(pass);
    
    return car;
}


/*
    FUNCTION userInput takes the currents user's Car object as input and displays the user interface
    the user is prompted to choose between 4 selections
        displayAll  - which displays the parking lot
        getSpot     - which returns the next open spot
            if no open spot is availiable the user can choose to go
            into a queue and wait for a spot to open up
        leaveSpot   - which causes the spot to become vacant in the database
*/
void userInput(Car car)
{
    int choice;
    
    cout << "Please select the following:\n" << endl;
    cout << "1 - Get Spot" << endl;
    cout << "2 - Leave Spot" << endl;
    cout << "3 - Print all Spots" << endl;
    cout << "4 - Leave the program" << endl;
    
    cin >> choice; 
    
    switch(choice)
    {
        //make a call to the function getSpot and return the next open spot and display to the user
        case 1:
        {
            int s = getSpot(car, waitqueue); 
            if (s != -1)
                cout <<"your spot is "<< s << endl;  
        }
            break;
        //prompt the user to enter the spot they are leaving then call leaveSpot to update that spot's 
        //status in the database
        case 2:
        {
            int x;
            cout << "Enter the spot you are leaving:" << endl;
            cin >> x;
            leaveSpot(x, waitqueue);  
        }
            break;
        //display all spots and the parking structure 
        //recall userInput so the user can get or leave a spot after seeing the display
        case 3:
        {
            displayAll(); 
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

