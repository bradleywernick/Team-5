#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool login();

int main(){
	int input = 0;
	bool loggedIn = false;

	cout << "\t\tFacebook \t\t" << endl;
	cout << endl << endl;
	cout << "\t\t[1] Login \t\t" << endl;
	cout << "\t\t[2] Register \t\t" << endl;
	cout << "\t\t[3] Exit \t\t" << endl;
	cout << "\t\t\t"; cin >> input;

	switch (input){
	case 1:
		while (loggedIn == false){
			loggedIn = login();
			if (loggedIn == false){
				cout << "\t\t[1] Retry \t\t" << endl;
				cout << "\t\t[2] Register \t\t" << endl;
				cout << "\t\t"; cin >> input;
				if (input == 2){ break; }
			}
			break;
		}
	case 2:
		cout << "\t\t" << "Under Construction" << endl;
		system("pause");
		break;
	case 3:
		return 0;
	default:
		cout << "\t\t" << "An Error has occured." << endl;
		system("pause");
		return 0;
	}
	return 0;
}

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
			system("pause");
			found = true;
			break;
		}
	}

	if (!found) {
		cout << "\t\t Invalid Input" << endl;
	}
	return found;
}
