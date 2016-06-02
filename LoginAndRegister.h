//Bradley Wernick
#ifndef LoginAndRegister_H
#define LoginAndRegister_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class LoginAndRegister{
private:
	string Username, Password;
	string inputUsername, inputPassword;
public:
	LoginAndRegister(){};
	void UserRegister(); //Register a new user. Can be changed to bool if needed
	bool Login(); //login a user
	string getCurrentUser();
};

void LoginAndRegister::UserRegister(){
	string line = " ";
	ifstream readFile("userdata.txt");
	char input;
	int i = 0;
	bool validUser = false;

	cout << "\t\t" << "Welcome!" << endl;

	while (!readFile.eof()) {
		cout << "\t\t" << "Please enter a new username: ";
		cin >> inputUsername;
		
		getline(readFile, Username, ' ');
		getline(readFile, Password);
		if (Username.compare(inputUsername) == 0){
			cout << endl << "\t\t" << "Somebody else already has that name." << endl;
			cout << "\t\t" << "Retry? [Y/N]" << endl;
			cout << "\t\t"; cin >> input; cin.ignore(100, '\n'); cin.clear();
			switch (input){
			case 'Y': case 'y':
				continue;
			case 'N': case 'n':
				return; //return false;
			}
		}else{
			break;
		}
	}

	cout << "\t\t"; cout << "Enter your password: ";
	cin >> inputPassword;

	ofstream writeFile("userdata.txt", ofstream::app); //Append rather than truncate
	if (!writeFile.is_open()){ writeFile.open("userdata.txt", ofstream::app); }

	writeFile << inputUsername << " " << inputPassword << endl;
	cout << endl << "\t\tRegistration Sucessful!" << endl;
	cout << "\t\t"; system("pause");
	return; //return true;
}

bool LoginAndRegister::Login(){
	string line;
	ifstream readFile("userdata.txt");
	
	if (!readFile.is_open()){ readFile.open("userdata.txt"); }

	cout << "\t\t"; cout << "Enter UserName: ";
	cin >> inputUsername;

	cout << "\t\t"; cout << "Enter Password: ";
	cin >> inputPassword;

	string searchPattern = inputUsername + " " + inputPassword;

	cout << "\t\t" << "Logging In..." << endl;

	bool found = false;
	while (getline(readFile, line) && !found) {
		if (line.compare(searchPattern) == 0) { //if login data is found
			found = true; //breaks the loop
		}
	}

	if (found){
		cout << "\t\t" << "Login Successful!" << endl;
		cout << "\t\t" << "Welcome " << inputUsername << endl;
		Username = inputUsername;
		cout << "\t\t"; system("pause");
	}else{
		cout << "\t\t Invalid Input" << endl;
	}

	return found;
}

string LoginAndRegister::getCurrentUser(){
	return Username;
}


#endif