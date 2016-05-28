#include <iostream>
#include <fstream>
#include <string>
#include "User.h"

using namespace std;

bool login();
bool registerUser();

int main(){
	User u;
	int input = 0;
	bool loggedIn = false;

	cout << "\t\tFacebook Login\t\t" << endl;
	cout << "\t\t--------------\t\t" << endl;
	cout << "\t\t[1] Login \t\t" << endl;
	cout << "\t\t[2] Register \t\t" << endl;
	cout << "\t\t[3] Exit \t\t" << endl;
	cout << "\t\t"; cin >> input;

	switch (input){
	case 1:
		do{
			loggedIn = u.Login();
			if (loggedIn == false){
				cout << "\t\t[1] Retry\t\t" << endl << "\t\t[2] Register\t\t" << endl << "\t\t[3] Exit \t\t" << endl;
				cout << "\t\t"; cin >> input;
				if (input == 2){ u.UserRegister(); break; }
				if (input == 3){ return 0; }
			}else{ continue; }
		} while (loggedIn == false);
		break;
	case 2:
		u.UserRegister();
		break;
	case 3:
		return 0;
	default:
		cout << "\t\t" << "An Error has occured." << endl;
		cout << "\t\t"; system("pause");
		return 0;
	}
	return 0;
}
/*
 bool login(){
	string line = " ";
	ifstream readFile("userdata.txt");
	string UserInput;
	string PassInput;
	string UserName;
	string Password;

	cout << "\t\t"; cout << "Enter UserName: ";
	cin >> UserInput;

	cout << "\t\t"; cout << "Enter Password: ";
	cin >> PassInput;

	cout << "\t\t" << "Logging In..." << endl;

	bool found = false;
	while (getline(readFile, line)) {
		readFile >> UserName >> Password;

		if (UserInput == UserName && PassInput == Password) {
			cout << "\t\tLogin Successfully!" << endl;
			cout << "\t\t"; system("pause");
			found = true;
			break;
		}
	}

	if (!found) {
		cout << "\t\t Invalid Input" << endl;
	}
	return found;
}

 bool registerUser(){
	 string line = " ";
	 ifstream readFile("userdata.txt");
	 string unameIn;
	 string unusedpassString;
	 string Username;
	 string Password;
	 char input;
	 bool validUser = false;

	 cout << "\t\t"; cout << "Welcome to the *Not a Facebook Clone* account creation" << endl;

		while (getline(readFile, line)) {
			cout << "\t\t"; cout << "Enter your username: ";
			cin >> Username;
			readFile >> unameIn >> unusedpassString;
			if (Username == unameIn){
				cout << endl << "\t\tSomebody else already has that name." << endl;
				cout << "\t\tRetry? [Y/N]" << endl;
				cout << "\t\t"; cin >> input;
				switch(input){
				case 'Y': case 'y': 
					continue;
				case 'N': case 'n':
					return false;
				}
			}else{
				break;
			}
		}


		cout << "\t\t"; cout << "Enter your password: ";
		cin >> Password;
		ofstream writeFile("userdata.txt", ofstream::app); //Append rather than truncate
		writeFile << Username << " " << Password << endl;
		cout << endl << "\t\tRegistration Sucessful!" << endl;
		cout << "\t\t"; system("pause");
		return true;
 }
 */