//Bradley Wernick
#ifndef INTERFACEMODULE_H
#define INTERFACEMODULE_H

#include <iostream>
#include <string>
#include "UserClass.h"

class InterfaceModule{
	friend class User;
private:
	string CurrentUsername;
	User CurrentUser;
	string Emote = "(._.)";
public:
	InterfaceModule(User input){ CurrentUsername = input.getUser(); CurrentUser = User(input.getUser()); }
	void start(); //Call this
	void showProfile(); //For own user
	void displayProfile(string input); //for other people
	void editProfile(); //change data about user
	//void searchPeople();
	void setStatus();
	//void checkFriendRequests();
	//void viewFriends();
	void setEmoticon(); //Currently not saved, so is set per login
};

void InterfaceModule::start(){
	char input;
	do{
		system("CLS");
		cout << "\t\t"; cout << "Logged in as: " << CurrentUser.getName() << endl << endl;
		cout << "\t\t"; cout << "[1] View Profile			" << endl;
		cout << "\t\t"; cout << "[2] Set Current Status     " << endl;
		cout << "\t\t"; cout << "[3] Set Emote				" << endl;
		//cout << "\t\t";cout << "[4] Search Users			" << endl;
		//cout << "\t\t";cout << "[5] Check Friend Requests  " << endl;
		cout << "\t\t"; cout << "[6] Logout					" << endl;
		cin >> input; cin.ignore(100, '\n'); cin.clear();
		if (input == '1'){ showProfile(); }
		if (input == '2'){ setStatus(); }
		if (input == '3'){ setEmoticon(); }
		//if (input == '4'){ searchPeople(); }
		//if (input == '5'){ checkFriendRequests(); }

		if (input < '1' || input > '6'){ cout << "\t\t" << "Invalid Input." << endl; cout << "\t\t"; system("pause"); }
	} while (input != '6');
}

void InterfaceModule::showProfile(){
	char input;
	do{
		system("CLS");
		cout << "\t\t"; cout << CurrentUser.getName() << "\t\t" << "Emote: " << Emote << endl;
		cout << "\t\t"; cout << "Current Status: " << CurrentUser.getCurrentStatus() << endl;
		cout << "\t\t"; cout << "================================" << endl;
		cout << "\t\t"; cout << "About Me:" << endl;
		cout << "\t\t"; cout << "--------------------------------" << endl;
		cout << "\t\t"; cout << "Age: " << CurrentUser.getAge() << endl;
		cout << "\t\t"; cout << "Employment: " << CurrentUser.getJob() << endl;
		cout << "\t\t"; cout << "Education: " << CurrentUser.getEducation() << endl;

		cout << endl << endl << endl;
		cout << "\t\t"; cout << "[1] Change Current Status     " << endl;
		cout << "\t\t"; cout << "[2] Set Emote				" << endl;
		//cout << "\t\t";cout << "[3] Search Users			" << endl;
		//cout << "\t\t";cout << "[4] Check Friend Requests" << endl;
		cout << "\t\t"; cout << "[5] Return to main screen	" << endl;
		cout << "\t\t"; cin >> input; cin.ignore(100, '\n'); cin.clear();

		if (input == '1'){ setStatus(); }
		if (input == '2'){ setEmoticon(); }
		//if (input == '3'){ searchPeople(); }
		//if (input == '4'){ checkFriendRequests(); }
		if (input < '1' || input > '5'){ cout << "\t\t" << "Invalid Input." << endl; cout << "\t\t"; system("pause"); }
	} while (input != '5');
}

void InterfaceModule::setEmoticon(){ //Why not?
	char input;
	do{
		system("CLS");
		cout << "\t\t"; cout << "Set Emoticon for Profile:" << endl;
		cout << "\t\t"; cout << "[1] (^_^)" << endl; //Happy
		cout << "\t\t"; cout << "[2] ;~;" << endl;  //Cry
		cout << "\t\t"; cout << "[3] o_O " << endl; //o_O
		cout << "\t\t"; cout << "[4]（ ﾟДﾟ）" << endl;  //shock
		cout << "\t\t"; cout << "[5] (=_=)" << endl; //tired
		cout << "\t\t"; cout << "[6] <3"<< endl; //heart
		cout << "\t\t"; cout << "[7] </3" << endl; //broken heart
		cout << "\t\t"; cout << "[8] (>_<)" << endl; // >_<
		cout << "\t\t"; cout << "[9] (._.)" << endl; // looking down, default emote

		cin >> input; cin.ignore(100, '\n'); cin.clear();

		if (input == '1'){ Emote = "(^_^)"; break; }
		if (input == '2'){ Emote = ";~;"; break; }
		if (input == '3'){ Emote = "o_O"; break; }
		if (input == '4'){ Emote = "（ ﾟДﾟ）"; break; }
		if (input == '5'){ Emote = "(=_=)"; break; }
		if (input == '6'){ Emote = "<3"; break; }
		if (input == '7'){ Emote = "</3"; break; }
		if (input == '8'){ Emote = "(>_<)"; break; }
		if (input == '9'){ Emote = "(._.)"; break; }
		if (input < '1' || input > '9'){
			cout << "\t\t"; cout << "Invalid Input, please try again." << endl; cout << "\t\t"; system("pause");
		}
	} while (true); //Only the best loop code
}

void InterfaceModule::setStatus(){
	string status;
	system("CLS");
	cout << "\t\t"; cout << "Current Status: " << CurrentUser.getCurrentStatus() << endl;
	cout << "\t\t"; cout << "Please input your status: ";
	getline(cin, status, '\n');
	cin.clear();
	CurrentUser.setCurrentStatus(status);
	cout << "\t\t"; cout << "Status Changed!" << endl;
	cout << "\t\t"; system("pause");
}

#endif