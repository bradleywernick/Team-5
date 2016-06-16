#ifndef USER_H
#define USER_H
#include "LList.h"
#include "QueueADT.h"
#include "Stack.h"
#include<fstream>
#include<string>
#include<cstring>
#include<iomanip>
#include<iostream>
#include <iterator>
#include <vector>

class User{
protected:
	string userName;
	string name;
	string age;
	string employment;
	string school;
	string currentStatus;
	string emote = "(._.)";

public:
	//LList<string> *friendList = new LList<string>();
	//LList<string> *pendingFriendList = new LList<string>();
	//LList<string> *friendRequests = new LList<string>();

	//mutators
	void changeName(string newName);
	void changeAge(string newAge);
	void changeJob(string newJob);
	void changeSchool(string newSchool);
	void changeUser(string);
	void changeEmote(string newEmote){ emote = newEmote; }
	
	//get methods
	string getName(){ return name; }
	string getAge(){ return age; }
	string getJob(){ return employment; }
	string getEducation(){ return school; }
	string getEmote(){ return emote; }
	
	//general functions
    string getUser(){return userName;}
    string getCurrentStatus();

	void setCurrentStatus(string status);
	//void acceptFriendRequest(User &other);
	//void addFriend(User &other); //sends a friend request
	void write();
	//void writeFriends();
	//void getFileData();
	void printTimeline();

	//void printFriends();
	//void printPendingFriendRequests();

	//constructors
	User() {};
	User(string username, string fullname, string job, string education, string age1, string status){ //takes 5 parametes and writes them to a file
		userName = username;
		name = fullname;
		employment = job;
		school = education;
		age = age1;
		emote = "(._.)";
		write();
		setCurrentStatus(status);
        
	}

	User(string username){
		ifstream userfile(username);
		if(!userfile.eof()){
			getline(userfile, userName);
			getline(userfile, name);
			getline(userfile, employment);
			getline(userfile, school);
			getline(userfile, age);
			getline(userfile, emote);

			userfile.close();

			//getFileData();
            
			currentStatus = getCurrentStatus();

		}else{
			cout << endl << "No Such User" << endl;
		}
	}

	~User(){
		write();
		//writeFriends();
    }

	bool operator<(User& b) {
		string op = userName;
		string opB = b.userName;
		if (op < opB) {
			return true;
		}else {
			return false;
		}
	}

	bool operator>(User& b) {
		string op = userName;
		string opB = b.userName;
		if (op > opB) {
			return true;
		}else {
			return false;
		}
	}

	void operator=(User& other){
		userName = other.getUser();
		name = other.getName();
		age = other.getAge();
		employment = other.getJob();
		school = other.getEducation();
		currentStatus = other.getCurrentStatus();
	}

	friend ostream& operator<<(ostream &os, User &other) {
		os << other.getUser() << endl;
		return os;
	}
};

/*
void User::getFileData(){
	string data = "";

	string friendFile = userName + "Friends";
	ifstream readFriends(friendFile);
	friendList->emptyList(); //reset
	while (getline(readFriends, data)){
		friendList->appendData(data);
	}
	readFriends.close();

	string pendingFile = userName + "PendingFriends";
	ifstream readPending(pendingFile);
	pendingFriendList->emptyList();
	while (getline(readPending, data)){
		pendingFriendList->appendData(data);
	}
	readPending.close();

	string requestFile = userName + "FriendRequests";
	ifstream readRequests(requestFile);
	friendRequests->emptyList();
	while (getline(readPending, data)){
		friendRequests->appendData(data);
	}
	readRequests.close();
}*/

void User::write(){
	ofstream userfile(userName);
	userfile << userName << endl
			<< name << endl
			<< employment << endl
			<< school << endl
			<< age << endl
			<< emote << endl;
	userfile.close();
}
/*
void User::writeFriends(){
	string fl = userName + "Friends";
	friendList->FileWrite(fl);

	string pfl = userName + "PendingFriends";
	pendingFriendList->FileWrite(pfl);

	string fr = userName + "FriendRequests";
	friendRequests->FileWrite(fr);
}*/

void User::changeUser(string newUser){
	userName = newUser;
}

void User::changeName(string newName){
	name = newName;
	write();
}

void User::changeAge(string newAge){
	age = newAge;
	write();
}

void User::changeJob(string newJob){
	employment = newJob;
	write();
}

void User::changeSchool(string newSchool){
	school = newSchool;
	write();
}
/*
void User::addFriend(User &other){
	other.getFileData(); //Ensures it is appended to the end of the most recent changes to the files
	other.friendRequests->appendData(userName);
	other.writeFriends();

	getFileData();
	pendingFriendList->appendData(other.getUser());
	writeFriends();
}

void User::acceptFriendRequest(User &other){
	other.getFileData();
	other.pendingFriendList->removeData(userName);
	other.friendList->appendData(userName);
	other.writeFriends();

	getFileData();
	friendRequests->removeData(other.getUser());
	friendList->appendData(other.getUser());
	writeFriends();
}*/

void User::setCurrentStatus(string status)
{
	string statusString = userName + "Status";
	ofstream statusFile;
	statusFile.open(statusString.c_str(), ofstream::app);
	statusFile << status << endl;
	statusFile.close();
}

string User::getCurrentStatus()
{
	string line, stats;
	string statusString = userName + "Status";
	ifstream statusFile;
	statusFile.open(statusString.c_str());

	while (getline(statusFile, line)){
		stats = line;
	}

	statusFile.close();
	return stats;
}

void User::printTimeline(){ 
	string stats; char buffer;
	string statusString = userName + "Status";
	ifstream statusFile(statusString, ios::ate);

	statusFile.seekg(0, ios::beg); //get position of beginning of the file
	ifstream::pos_type posBeg = statusFile.tellg(); //set it to posBeg
	statusFile.seekg(-1, ios::end); //goto the end of file

	while (statusFile.tellg() != posBeg){ //while not at the beginning of file
		buffer = static_cast<char>(statusFile.peek()); //get the last char
		if (buffer != '\n'){ //if not endline
			stats += buffer; //add to stats
		}else{ //otherwise
			reverse(stats.begin(), stats.end()); //reverse, making the line readable
			cout << "\t\t" << stats << endl; //output
			stats.clear(); //clear
		}
		statusFile.seekg(-1, ios::cur); //move up a line
	}

	stats += static_cast<char>(statusFile.peek()); //get beginnng char
	reverse(stats.begin(), stats.end()); //reverse
	cout << "\t\t" << stats << endl; //output

	statusFile.close(); //close
}

#endif