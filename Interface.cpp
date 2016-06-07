//Bradley Wernick
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include	<conio.h>
#include <cstring>
#include "Security.h"
#include "UserClass.h"

using namespace std;

string Username;
Security S = Security();

void UserRegister(); //Register a new user. Can be changed to bool if needed
bool Login(); //login a user
string getCurrentUser();
string MaskedInput(); //masked input function. requires <cstring> and <conio.h>

int main(){
	bool loggedIn = false;
	char input;

	do{
		loggedIn = false; //If exit to main menu, login is false

		system("CLS");
		cout << "\t\t" << "====================================" << endl;
		cout << "\t\t" << "            Not Facebook            " << endl;
		cout << "\t\t" << "              Main Menu             " << endl;
		cout << "\t\t" << "====================================" << endl << endl;
		cout << "\t\t" << "          [1] Login                 " << endl;
		cout << "\t\t" << "          [2] Register              " << endl;
		cout << "\t\t" << "          [3] Exit                  " << endl << endl;
		cout << "\t\t" << "====================================" << endl;
		cout << "\t\t" << "Enter your choice: " << endl;
		cout << "\t\t";  cin >> input;
		cin.ignore(100, '\n'); cin.clear();

		if (input == '1'){
			cout << "\t\t";  system("CLS");
			loggedIn = Login(); //use a bool to confirm

			if (loggedIn == false){ cout << "\t\t" << "Login Failed" << endl; cout << "\t\t"; system("pause"); } //Tell user login failed, take back to main
		}else if (input == '2'){
			cout << "\t\t"; system("CLS");
			UserRegister(); //register new user
		}else if (input == '3'){
			break;
		}else{
			cout << "\t\t";  system("CLS");
			cout << endl << "Please enter a valid number." << endl;
		}

		if (loggedIn == true){ //if logged in
			//Enter another interface for that user
			break;
		}

	} while (input != '3');

	if (loggedIn){
		User U(getCurrentUser());
		cout << "\t\t"; cout << "Proof of concept" << endl; cout << "\t\t"; system("pause");
	}

	return 0;
}

void UserRegister(){
	string inputUsername, inputPassword;
	string fullname, job, education, age;
	int i = 0;
	bool validUser = false;

	cout << "\t\t" << "Welcome!" << endl;

	cout << "\t\t" << "Please enter a new username: ";
	cin >> inputUsername;

	cout << "\t\t"; cout << "Enter your password: ";
	inputPassword = MaskedInput();

	S.add(inputUsername, inputPassword);

	cout << endl << "\t\tRegistration Sucessful!" << endl;

	cout << "Please enter some information about yourself:" << endl;
	cout << "What's your full name?" << endl;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, fullname, '\n');
	cin.clear();

	cout << "Where do you work?" << endl;
	getline(cin, job, '\n');
	cin.clear();

	cout << "Where did you go to school?" << endl;
	getline(cin, education, '\n');
	cin.clear();

	cout << "How old are you?" << endl;
	getline(cin, age, '\n');
	cin.clear();

	cout << "Thank you for your time. Your account is being created." << endl;

	User U(inputUsername, fullname, job, education, age);

	cout << "\t\t"; system("pause");
	return; //return true;
}

bool Login(){
	string inputUsername, inputPassword; //for storage
	bool Auth = false; //Auth variable

	cout << "\t\t"; cout << "Enter UserName: "; //get username
	cin >> inputUsername;

	cout << "\t\t"; cout << "Enter Password: "; //get password
	inputPassword = MaskedInput();

	cout << endl << "\t\t" << "Logging In..." << endl; 

	Auth = S.authenticate(inputUsername, inputPassword); //Authenticate with the security class

	if (Auth == true){ Username = inputUsername; };
	return Auth;
}


string getCurrentUser(){
	return Username; //return the Username. Make sure logged in first.
}

string MaskedInput(){
	char passwd[50]; //char array for input. any larger is likely not needed
	memset(passwd, 0, 50); //set memory for array
	int i = 0; //loop iterator
	passwd[0] = _getch(); //conio.h get function, benefits are there is no screen echo, downside is it likely fails on non-windows
	while (passwd[i] != '\r'){ //while no return key pressed
		if (passwd[i] == '\b'){
			cout << '\b' << '\b';
		}
		else{
			cout << '*'; //output *
		}

		i++; //iterate
		passwd[i] = _getch(); //get next char from user
	}
	return string(passwd); //cast char array to string and return
}