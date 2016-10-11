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
#include <Car.h>
#include <list>

using namespace std;

Car newuser(int ID);

void userInput(Car car);

int main(void){
 bool running = true;
	int choice, tempID;
	int j = 0;
	Car tempCar;
	
	list<Car> carList = getAllCars();/*****a function that returns the list of cars from XML File****/
	bool IDs[1000] = {0}; //array of IDs for security purposes
	
	//set IDs from carList to true
	for (Car i : carList)
	{
		IDs[i.getID()] = True;
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
			if (tempID > 999 || IDs[tempID] != True)
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
			while (IDs[j] == True)
				j++;
			
			//create a new car for the user
			tempCar = newuser(j);
			
			//add new car to the list 
			carList.push_back(tempCar);
			
			//add ID to the IDs array
			IDs[j] == True;
			
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
	
	string type;
	int size;

	cout << "Your driver ID is: " << ID;
	cout << endl;

	cout << "Please enter type of car: ";
	getline(cin, type);
	cout << endl;

	cout << "Please enter size compact(0) or normal(1) or oversized(2): ";
	cin >> size;
	cout << endl;

	//call function
	car.setID(ID);
	car.setType(type);
	car.setSize(size);
	
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
	
	cin >> choice
		
	switch(choice)
	{
		case 1:
		{
			cout << "Enter the spot you would like" << endl;
			int y;
			cin >> y;
			int s = getSpot(y);
			cout << your spot is << s;
		}
			break;
			
		case 2:
		{
			int x;
			cout << "Enter the spot you are leaving:" << endl;
			cin >> x;
			leaveSpot(x);
		}
			break;
			
		case 3:
		{
			printAllSpots();
			userInput(car);
		}
			break;
			
		case 4:
			cout << "Leaving program" << endl;
			break;
	
		default:
		{
			cout << "Error: invalid input << endl;
			userInput(car);
		}
			break;
	}
	
	return;
	
}
	
		
	
