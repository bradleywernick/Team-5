//Bradley Wernick
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include	<conio.h>
#include <cstring>
#include "Security.h"
#include "UserClass.h"
#include "InterfaceModule.h"
#include "bstADT.h"
#include "LList.h"

using namespace std;

string Username; //holds username from authntication if it is a success
Security S = Security(); //For Login and Registering
bstADT<User> *userList = new bstADT<User>(); //tree of all users
//bstADT<string> *userList = new bstADT<string>(); //tree of all users

void UserRegister(); //Register a new user. Can be changed to bool if needed
bool Login(); //login a user
void startUp();
void Debug(); //tree print and such
void RemoveUser();
string MaskedInput(); //masked input function. requires <cstring> and <conio.h>

int main(){
	bool loggedIn = false;
	int input;
	do{
		loggedIn = false; //If exit to main menu, login is false

		system("CLS");
		cout << "\t\t" << "====================================" << endl;
		cout << "\t\t" << "           Status Stash             " << endl; // GG
		cout << "\t\t" << "====================================" << endl << endl;
		cout << "\t\t" << "          [1] Login                 " << endl;
		cout << "\t\t" << "          [2] Register              " << endl;
		cout << "\t\t" << "          [3] Debug                 " << endl;
		cout << "\t\t" << "          [4] Remove User           " << endl;
		cout << "\t\t" << "          [5] Exit                  " << endl << endl;
		cout << "\t\t" << "====================================" << endl;
		cout << "\t\t" << "Enter your choice: ";
		cin >> input; cout << endl;
		cin.ignore(100, '\n'); cin.clear();

		if (input == 1){
			cout << "\t\t";  system("CLS");
			loggedIn = Login(); //use a bool to confirm

			if (loggedIn == false){ cout << "\t\t" << "Login Failed" << endl; cout << "\t\t"; system("pause"); } //Tell user login failed, take back to main
		}else if (input == 2){
			cout << "\t\t"; system("CLS");
			UserRegister(); //register new user
		}
		else if (input == 3){
			Debug();
		}
		else if (input == 4){
			RemoveUser();
		}
		else if (input == 5){
			break;
		}else{
			cout << "\t\t";  system("CLS");
			cout << endl << "\t\t" << "Please enter a valid number." << endl;
			cout << "\t\t"; system("pause");
		}

		if (loggedIn){ //if logged in
			User U(Username); //create user object
			cout << "\t\t"; cout << "Loading Profile..." << endl; //Tell user some bullshit about loading times
			cout << "\t\t"; system("pause"); //pause the program so they can push a button. 
			startUp(); //populate the tree
			InterfaceModule module(U, userList); //Create the module
			module.start(); //start up
			loggedIn = false; //once exited, no longer logged in, therfore exit if, and return to main menu
		}

	} while (input != 5);

	return 0;
}

void UserRegister(){ //this code should be self-explanatory
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
	cout << "\t\t"; system("pause");

	system("CLS");
	cout <<  endl << "\t\t" << "Profile Creation:" << endl;
	cout << "\t\t"; cout << "Please enter some information about yourself: " << endl;
	cout << "\t\t"; cout << "What's your full name? ";

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, fullname, '\n');
	cin.clear();

	cout << endl; cout << "\t\t"; cout << "Where do you work? ";
	getline(cin, job, '\n');
	cin.clear();

	cout << endl; cout << "\t\t"; cout << "Where did you go to school? ";
	getline(cin, education, '\n');
	cin.clear();

	cout << endl; cout << "\t\t"; cout << "How old are you? ";
	getline(cin, age, '\n');
	cin.clear();

	cout << endl; cout << "\t\t"; cout << "Thank you for your time. Your account is being created." << endl;

	string status = "There is nothing here at the moment.";
	User U(inputUsername, fullname, job, education, age, status); 

	cout << "\t\t"; system("pause");

	ofstream writeFile("Username.txt", ofstream::app);
	writeFile << inputUsername << endl;
	writeFile.close();

	return; //return true;
}

bool Login(){ //this code should be self-explanatory
	string inputUsername, inputPassword; //for storage
	bool Auth = false; //Auth variable

	cout << "\t\t"; cout << "Enter UserName: "; //get username
	getline(cin, inputUsername, '\n');
	cin.clear();

	cout << "\t\t"; cout << "Enter Password: "; //get password
	inputPassword = MaskedInput();

	cout << endl << "\t\t" << "Logging In..." << endl; 

	Auth = S.authenticate(inputUsername, inputPassword); //Authenticate with the security class

	if (Auth){ Username = inputUsername; };
	return Auth;
}

string MaskedInput(){ //relies on conio.h and cstring
	char passwd[50]; //char array for input. any larger is likely not needed
	memset(passwd, 0, 50); //set memory for array
	int i = 0; //loop iterator
	passwd[0] = _getch(); //conio.h get function, benefits are there is no screen echo, downside is it likely fails on non-windows
	while (passwd[i] != '\r'){ //while no return key pressed
		if (i == 0 && passwd[i] == '\b'){
			cout << " \b";
		}
		if (passwd[i] == '\b' && i != 0){
			cout << "\b \b";
			i--; //backspace, thus move back one in the array
			passwd[i] = _getch(); //get next char from user
		}
		else{
			cout << '*'; //output *
			i++; //iterate
			passwd[i] = _getch(); //get next char from user
		}
	}
	return string(passwd); //cast char array to string and return
}

void startUp()
{
	ifstream s("Username.txt");
	string users;
	while (getline(s, users)){
		User temp(users);
		userList->insert(temp);
	}
}

void Debug(){
	startUp(); //populate the tree
	int input;
	do{
		system("CLS");
		cout << "\t\t"; cout << "  Debug: View Data in BST  " << endl;
		cout << "\t\t"; cout << "---------------------------" << endl;
		cout << "\t\t"; cout << "[1] Preorder Tree Print" << endl;
		cout << "\t\t"; cout << "[2] Inorder Tree Print" << endl;
		cout << "\t\t"; cout << "[3] Postorder Tree Print" << endl;
		cout << "\t\t"; cout << "[4] Indented Postorder Tree Print" << endl;
		cout << "\t\t"; cout << "[5] Hash Table" << endl;
		cout << "\t\t"; cout << "[6] Exit" << endl;
		cout << "\t\t"; cin >> input; cout << endl;
		cin.ignore(100, '\n'); cin.clear();

		system("CLS");
		if (input == 1){ userList->preorderPrint(); cout << "\t\t"; system("pause"); }
		if (input == 2){ userList->inorderPrint(); cout << "\t\t"; system("pause"); }
		if (input == 3){ userList->postorderPrint(); cout << "\t\t"; system("pause"); }
		if (input == 4){ userList->postorderIndented(); cout << "\t\t"; system("pause"); }
		if (input == 5){ S.print(); cout << "\t\t"; system("pause"); }
	} while (input != 6);
	return;
}

void RemoveUser(){
	system("CLS");
	string inputUsername, inputPassword; //for storage
	char input;
	bool Auth = false; //Auth variable
	
	cout << "\t\t" << "Account Removal Service" << endl;
	cout << "\t\t"; cout << "Enter Username: "; //get username
	getline(cin, inputUsername, '\n');
	cin.clear();

	cout << "\t\t"; cout << "Enter Password: "; //get password
	inputPassword = MaskedInput();
	cin.clear();

	cout << endl << "\t\t" << "Authenticating..." << endl;
	cout << "\t\t"; system("pause");
	Auth = S.authenticate(inputUsername, inputPassword); //Authenticate with the security class

	do{
		system("CLS");

		if (Auth){
			cout << "\t\t" << "Your Account Will be Deleted. Continue?" << endl;
			cout << "\t\t" << "[Y/N] "; cin >> input;
			if (input == 'y' || input == 'Y'){
				cout << "\t\t" << "Removing Data..." << endl;
				int deleted2 = remove((inputUsername + "Status").c_str());
				int deleted1 = remove(inputUsername.c_str());
				
				if (deleted1 != 0 && deleted2 != 0){
					perror("\t\tError deleting files!\n");
				}else{
					cout << "\t\tData successfully removed.\n";
					cout << "\t\t"; system("pause");
				}

				LList<string> *listofusers = new LList<string>();
				ifstream s("Username.txt");
				string users;
				while (getline(s, users)){
					listofusers->appendData(users);
				}

				listofusers->removeData(inputUsername);
				listofusers->FileWrite("Username.txt");
				return;

			}else if (input == 'n' || input == 'N'){
				cout << "\t\t" << "Account Deletion Process Terminated." << endl;
				cout << "\t\t"; system("pause");
				return;
			}else{
				cout << "\t\t" << "Invalid Input." << endl;
				cout << "\t\t"; system("pause");
			}
		}else{
			cout << "\t\t" << "Authentication Failed." << endl;
			cout << "\t\t"; system("pause");
			return;
		}
	} while (true);
}