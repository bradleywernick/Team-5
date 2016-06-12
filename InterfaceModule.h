//Bradley Wernick
#ifndef INTERFACEMODULE_H
#define INTERFACEMODULE_H

#include <iostream>
#include <string>
#include <vector>
#include "UserClass.h"

class InterfaceModule{
	friend class User;
private:
	string CurrentUsername;
	User CurrentUser;
	string Emote = "(._.)"; //default emote. Emotes are pointless, but hey, they are fun.
public:
	InterfaceModule(User input){ CurrentUsername = input.getUser(); CurrentUser = User(input.getUser()); }
	void start(); //First menu, call this to begin interface stuff
	
private: //the rest are private to avoid outside access
	void showProfile(); //Show own profile
	void displayProfile(User, bool); //Show given user's profile, bool for isFriend
	void editProfile(); //change data about user
	void printTimeline(); //print a list of statuses from newest to oldest
	
	void searchPeople(); //search the bst for a username
	void setStatus(); //set the current status for your profile
	void checkFriendRequests(); //check the list of friend requests, allows profile viewing and accpting requests
	void viewFriends(); //view a list of friends, can view their profiles
	void setEmoticon(); //Currently not saved, so is set per login. Pointless but fun
};

void InterfaceModule::start(){
	char input; //control character
	do{
		system("CLS"); //clear screen
		cout << "\t\t"; cout << "Logged in as: " << CurrentUser.getName() << endl << endl;
		cout << "\t\t"; cout << "[1] View Profile			" << endl;
		cout << "\t\t"; cout << "[2] Set Current Status     " << endl;
		cout << "\t\t"; cout << "[3] Set Emote				" << endl;
		cout << "\t\t";cout << "[4] Search Users			" << endl;
		cout << "\t\t"; cout << "[5] Check Friend Requests  " << endl;
		cout << "\t\t"; cout << "[6] View Friends    		" << endl;
		cout << "\t\t"; cout << "[7] Logout					" << endl;
		cout << "\t\t"; cin >> input; cin.ignore(100, '\n'); cin.clear();
		if (input == '1'){ showProfile(); }
		if (input == '2'){ setStatus(); }
		if (input == '3'){ setEmoticon(); }
		if (input == '4'){ searchPeople(); }
		if (input == '5'){ checkFriendRequests(); }
		if (input == '6'){ viewFriends(); }

		if (input < '1' || input > '7'){ cout << "\t\t" << "Invalid Input." << endl; cout << "\t\t"; system("pause"); }
	} while (input != '7');
}

void InterfaceModule::showProfile(){
	char input;
	do{
		system("CLS"); //clear screen
		cout << "\t\t"; cout << CurrentUser.getName() << "\t\t" << "Emote: " << Emote << endl;
		cout << "\t\t"; cout << "Current Status: " << CurrentUser.getCurrentStatus() << endl;
		cout << "\t\t"; cout << "================================" << endl;
		cout << "\t\t"; cout << "About Me:" << endl;
		cout << "\t\t"; cout << "--------------------------------" << endl;
		cout << "\t\t"; cout << "Age: " << CurrentUser.getAge() << endl;
		cout << "\t\t"; cout << "Job: " << CurrentUser.getJob() << endl;
		cout << "\t\t"; cout << "School: " << CurrentUser.getEducation() << endl;

		cout << endl << endl << endl;
		cout << "\t\t"; cout << "[1] Change Current Status     " << endl;
		cout << "\t\t"; cout << "[2] Set Emote				" << endl;
		cout << "\t\t"; cout << "[3] Search Users			" << endl;
		cout << "\t\t"; cout << "[4] Check Friend Requests" << endl;
		cout << "\t\t"; cout << "[5] Print Timeline" << endl;
		cout << "\t\t"; cout << "[6] Return to main screen	" << endl;
		cout << "\t\t"; cin >> input; cin.ignore(100, '\n'); cin.clear();

		if (input == '1'){ setStatus(); }
		if (input == '2'){ setEmoticon(); }
		if (input == '3'){ searchPeople(); }
		if (input == '4'){ checkFriendRequests(); }
		if (input == '5'){ printTimeline(); }
		if (input < '1' || input > '6'){ cout << "\t\t" << "Invalid Input." << endl; cout << "\t\t"; system("pause"); }
	} while (input != '6');
}

void InterfaceModule::setEmoticon(){ //Why not?
	char input; //control variable
	do{
		system("CLS"); //clear screen
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

		cout << "\t\t"; cin >> input; cin.ignore(100, '\n'); cin.clear();

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
	string status; //string
	system("CLS"); //clear screen
	cout << "\t\t"; cout << "Current Status: " << CurrentUser.getCurrentStatus() << endl; //get the current status
	cout << "\t\t"; cout << "Please input your status: ";
	getline(cin, status, '\n'); //get input
	cin.clear();
	CurrentUser.setCurrentStatus(status); //set the status
	cout << "\t\t"; cout << "Status Changed!" << endl;
	cout << "\t\t"; system("pause");
}

void InterfaceModule::printTimeline(){
	system("CLS"); //clear screen
	cout << "\t\t"; cout << "Timeline" << endl;
	cout << "\t\t"; cout << "--------" << endl;
	CurrentUser.printTimeline();
	cout << "\t\t"; system("pause");
}

void InterfaceModule::viewFriends(){
	int input;
	do{
		system("CLS"); //clear screen
		cout << "\t\t"; cout << "Friends" << endl;
		CurrentUser.friendList->print();
		cout << endl << "\t\t" << "Whose profile do you want to view?"
			<< endl << "\t\t" << "Please input the number indicated on the list,"
			<< endl << "\t\t" << "or zero to return." << endl; 

		cout << "\t\t"; cin >> input; cin.ignore(100, '\n'); cin.clear();

		if (input == 0){ return; }
		if (input < 0 || input > CurrentUser.friendList->count()){ cout << "\t\t"; cout << "Invalid Input, please try again." << endl; }

		vector<string> flist = CurrentUser.friendList->returnData();

		User Fr(flist[input]);
		displayProfile(Fr, true);
	} while (true);
}

void InterfaceModule::displayProfile(User U, bool isFriend){
	char input;
	if (isFriend){
		do{
			system("CLS"); //clear screen
			cout << "\t\t"; cout << U.getName() << "\t\t" << "Emote: " << Emote << endl;
			cout << "\t\t"; cout << "Current Status: " << U.getCurrentStatus() << endl;
			cout << "\t\t"; cout << "================================" << endl;
			cout << "\t\t"; cout << "About Me:" << endl;
			cout << "\t\t"; cout << "--------------------------------" << endl;
			cout << "\t\t"; cout << "Age: " << U.getAge() << endl;
			cout << "\t\t"; cout << "Job: " << U.getJob() << endl;
			cout << "\t\t"; cout << "School: " << U.getEducation() << endl;
			cout << endl << "\t\t"; cout << "[1] Print Timeline";
			//cout << endl << "\t\t"; cout << "[2] View Friends";
			cout << endl << "\t\t"; cout << "[2] Return";
			cout << endl << "\t\t"; cin >> input; cin.ignore(100, '\n'); cin.clear();
			if (input == '1'){
				system("CLS"); //clear screen
				U.printTimeline();
				system("pause");
			}
			/*if (input == '2'){
				//Shoot.
			}*/
		} while (input != '2');
	}else{
		do{
			system("CLS"); //clear screen
			cout << "\t\t"; cout << U.getName() << "\t\t" << "Emote: " << Emote << endl;
			cout << "\t\t"; cout << "You cannot view anymore information about this user without being friends." << endl;
			cout << endl << "\t\t"; cout << "[1] Add as Friend";
			cout << endl << "\t\t"; cout << "[2] Return";
			cout << endl << "\t\t"; cin >> input; cin.ignore(100, '\n'); cin.clear();
			if (input == '1'){ CurrentUser.addFriend(U); }
		} while (input != '2');
	}
}

void InterfaceModule::checkFriendRequests(){
	int input;
	do{
		system("CLS"); //clear screen
		cout << "\t\t"; cout << "Pending Friend Requests" << endl;
		CurrentUser.friendRequests->print();
		 cout << endl << "\t\t" << "Whose profile do you want to view?" 
			<< endl << "\t\t" << "Please input the number indicated on the list," 
			<< endl << "\t\t" <<  "or zero to return." << endl;
		cout << "\t\t"; cin >> input; cin.ignore(100, '\n'); cin.clear();

		if (input == 0){ return; }
		if (input < 0 || input > CurrentUser.pendingFriendList->count()){ cout << "\t\t"; cout << "Invalid Input, please try again." << endl; }

		vector<string> requestlist = CurrentUser.friendRequests->returnData(); //get a list of requests
		User U(requestlist[input]); //creates the object, getting the data from the files

		do{
			system("CLS"); //clear screen
			cout << "\t\t"; cout << U.getName() << "\t\t" << "Emote: " << Emote << endl;
			cout << "\t\t"; cout << "You cannot view anymore information about this user without being friends." << endl;
			cout << endl << "\t\t"; cout << "[1] Accept Friend Request";
			cout << endl << "\t\t"; cout << "[2] Return";
			cout << endl << "\t\t"; cin >> input; cin.ignore(100, '\n'); cin.clear();
			if (input == '1'){ 
				CurrentUser.acceptFriendRequest(U); //accept the request
				requestlist[input].erase(); //remove user from requestlist
				break; //exit
			}
		} while (input != '2');
	} while (true);
}

void InterfaceModule::searchPeople(){ //this will return to the profile or main menu after 1 search, makes input parsing easier
	string input; //self-explanatory
	vector<string> flist = CurrentUser.friendList->returnData(); //for detecting if the found user is a friend or not
	system("CLS"); //clear screen
	cout << "\t\t"; cout << "Search Users" << endl;
	cout << "\t\t"; cout << "Enter the username of the person you are looking for: " << endl;
	getline(cin, input, '\n'); cin.clear(); cout << endl;
	cout << "\t\t"; cout << "Searching..." << endl; system("pause");
	User U; U.changeUser(input);
	U = userList->searchBST(U);

	//basically, if no name is assigned to the user object as a result of the search, then nothing was found.
	if (U.getName() == ""){ cout << "\t\t" << "No one with that name exists in our database." << endl; } 
	else{ //otherwise
		bool isFriend = false; 
		for (int i = 0; i < flist.size(); i++){ //if the name matches one of the names in friend list, they are friends
			if (flist[i] == U.getName()){
				isFriend = true;
			}
		}
		displayProfile(U, isFriend); //displays that user's profile.
	}
}

void InterfaceModule::editProfile(){
	char input;
	string newData;
	do{
		system("CLS"); //clear screen
		cout << "\t\t"; cout << "Current Profile:" << endl;
		cout << "\t\t"; cout << CurrentUser.getName() << "\t\t" << "Emote: " << Emote << endl;
		cout << "\t\t"; cout << "Current Status: " << CurrentUser.getCurrentStatus() << endl;
		cout << "\t\t"; cout << "================================" << endl;
		cout << "\t\t"; cout << "About Me:" << endl;
		cout << "\t\t"; cout << "--------------------------------" << endl;
		cout << "\t\t"; cout << "Age: " << CurrentUser.getAge() << endl;
		cout << "\t\t"; cout << "Job: " << CurrentUser.getJob() << endl;
		cout << "\t\t"; cout << "School: " << CurrentUser.getEducation() << endl;

		cout << endl; 
		cout << "\t\t"; cout << "[1] Edit Name" << endl;
		cout << "\t\t"; cout << "[2] Edit Age" << endl;
		cout << "\t\t"; cout << "[3] Edit Job" << endl;
		cout << "\t\t"; cout << "[4] Edit School" << endl;
		cout << "\t\t"; cout << "[5] Exit" << endl;
		cin >> input; cin.ignore(100, '\n'); cin.clear();

		if (input < 0 || input > 5){ cout << "\t\t"; cout << "Invalid Input. Please try again." << endl; }

		if (input == 1){
			system("CLS");
			cout << "\t\t"; cout << "Name: " << CurrentUser.getName() << endl;
			cout << "\t\t" << "Enter Name: ";
			getline(cin, newData, '\n');
			cin.clear(); cout << endl;
			CurrentUser.changeName(newData);
			cout << "\t\t" << "Change Successful!" << endl;
			system("pause");
		}

		if (input == 2){
			system("CLS");
			cout << "\t\t"; cout << "Age: " << CurrentUser.getName() << endl;
			cout << "\t\t" << "Enter Age: ";
			getline(cin, newData, '\n');
			cin.clear(); cout << endl;
			CurrentUser.changeAge(newData);
			cout << "\t\t" << "Change Successful!" << endl;
			system("pause");
		}

		if (input == 3){
			system("CLS");
			cout << "\t\t"; cout << "Job: " << CurrentUser.getName() << endl;
			cout << "\t\t" << "Enter Job: ";
			getline(cin, newData, '\n');
			cin.clear(); cout << endl;
			CurrentUser.changeJob(newData);
			cout << "\t\t" << "Change Successful!" << endl;
			system("pause");
		}

		if (input == 4){
			system("CLS");
			cout << "\t\t"; cout << "School: " << CurrentUser.getName() << endl;
			cout << "\t\t" << "Enter School: ";
			getline(cin, newData, '\n');
			cin.clear(); cout << endl;
			CurrentUser.changeSchool(newData);
			cout << "\t\t" << "Change Successful!" << endl;
			system("pause");
		}

	} while (input != 5);

}

#endif