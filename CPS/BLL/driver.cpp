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


using namespace std;

int main(void){
 bool running = true;
	int choice;

	//Main Menu for program
	do {
		cout << "Welcome!" << endl;
		cout << "Please select the following:\n" << endl;
		cout << "1 - New User" << endl;
		cout << "2 - Returning User" << endl;
		cout << "3 - Exit\n" << endl;

		cin >> choice;

		//Ask user if they have app before or would like to exit app
		switch (choice)
		{
		case 1:
			cout << endl << "Login:\n" << endl;
			cout << "User ID" << endl;
			break;
		case 2:
			cout << endl << "Sign up:\n" << endl;
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
