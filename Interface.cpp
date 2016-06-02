//Bradley Wernick
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "LoginAndRegister.h"

using namespace std;

int main(){
	LoginAndRegister log;
	bool loggedIn = false;
	char input;

	do{
		loggedIn = false; //If exit to main menu, login is false

		system("CLS");
		cout << "====================================" << endl;
		cout << "            Not Facebook            " << endl;
		cout << "              Main Menu             " << endl;
		cout << "====================================" << endl << endl;
		cout << "          [1] Login                 " << endl;
		cout << "          [2] Register              " << endl;
		cout << "          [3] Exit                  " << endl << endl;
		cout << "====================================" << endl;
		cout << "Enter your choice: " << endl;
		cin >> input;
		cin.ignore(100, '\n'); cin.clear();

		if (input == '1'){
			system("CLS");
			loggedIn = log.Login(); //use a bool to confirm

			if (loggedIn == false){ cout << "Login Failed" << endl; system("pause"); } //Tell user login failed, take back to main
		}else if (input == '2'){
			system("CLS");
			log.UserRegister(); //register new user
		}else{
			cout << endl << "Please enter a valid number." << endl;
		}

		if (loggedIn == true){ //if logged in
			//Enter another interface for that user
		}

	} while (input != '3');

	return 0;
}