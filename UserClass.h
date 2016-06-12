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
#include <vector>

class User{
protected:
	string userName;
	string name;
	string age;
	string employment;
	string school;
	string currentStatus;

	//LList<string> *friendList = new LList<string>();
	Stack<string> *timeLine = new Stack<string>();
public:
    LList<string> *friendList = new LList<string>();
    LList<string> *pendingFriendList = new LList<string>();
    LList<string> *friendRequests = new LList<string>();
	//mutators
	void changeName(string newName);
	void changeAge(string newAge);
	void changeJob(string newJob);
	void changeSchool(string newSchool);
	void changeUser(string);
	void unFriend(string username);
	
	//get methods
	string getName(){ return name; }
	string getAge(){ return age; }
	string getJob(){ return employment; }
	string getEducation(){ return school; }
	
	//general functions
    string getUser(){return userName;}
    string getCurrentStatus();

	void setCurrentStatus(string status);
	//void friendRequests();
	void acceptFriendRequest(User &other);
	void addFriend(User &other); //sends a friend request
	void write();
	void writeFriends();
	void printTimeline();

	//constructors
	User() {};
	User(string username, string fullname, string job, string education, string age1, string status){ //takes 5 parametes and writes them to a file
		userName = username;
		name = fullname;
		employment = job;
		school = education;
		age = age1;

		write();
		setCurrentStatus(status);
        
	}

	User(string username){
		ifstream userfile;
		userfile.open(username.c_str());
		if(!userfile.eof()){
			getline(userfile, userName);
			getline(userfile, name);
			getline(userfile, employment);
			getline(userfile, school);
			getline(userfile, age);

			userfile.close();

			string friendLists = userName + "Friends";
			ifstream listOfFriends;
			listOfFriends.open(friendLists.c_str());
			string friends;
			while (getline(listOfFriends, friends)){
				friendList->appendData(friends);
			}
            
            string pendingFriendLists = userName + "PendingFriends";
            ifstream listOfPendingFriends;
            listOfPendingFriends.open(pendingFriendLists.c_str());
            string pendingFriends;
            while (getline(listOfPendingFriends, pendingFriends)){
                pendingFriendList->appendData(pendingFriends);
            }
            
			currentStatus = getCurrentStatus();

		}else{
			cout << endl << "No Such User" << endl;
		}
	}
	~User(){
		write();
		writeFriends();
    }

	bool operator<(User& b) {
		string op = getUser();
		string opB = b.getUser();
		if (op < opB) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator>(User& b) {
		string op = getUser();
		string opB = b.getUser();
		if (op > opB) {
			return true;
		}
		else {
			return false;
		}
	}
	void operator=(User& other){
		userName = other.userName;
		name = other.name;
		age = other.age;
		employment = other.employment;
		school = other.school;
		currentStatus = other.currentStatus;
	}
	friend ostream& operator<<(ostream &os, User &other) {
		os << other.getUser() << endl;
		return os;
	}
};

void User::write(){
	ofstream userfile;
	userfile.open(userName.c_str());
	userfile << userName << endl
		<< name << endl
		<< employment << endl
		<< school << endl
		<< age << endl;
	userfile.close();
}

void User::writeFriends(){
	string friendLists = userName + "Friends";
	ofstream userfile;
	userfile.open(friendLists.c_str());

	Node<string>* node = friendList->headNode;

	while (node) {
		userfile << node->getData() << endl;
		node = node->next();
	}
    
    string pendingFriendLists = userName + "PendingFriends";
    ofstream otheruserfile;
    otheruserfile.open(pendingFriendLists.c_str());
    
    Node<string>* node2 = friendList->headNode;
    
    while (node){
        otheruserfile << node2->getData() << endl;
        node2 = node2->next();
    }
}

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

void User::unFriend(string username){
	friendList->removeData(username);
	writeFriends();
}

void User::addFriend(User &other){
    other.friendRequests->appendData(userName);
	pendingFriendList->appendData(other.getUser());
    writeFriends();
}

void User::acceptFriendRequest(User &other){
    string username = other.getUser();
    other.friendRequests->removeData(username);
    other.friendList->appendData(username);
    pendingFriendList->removeData(username);
    friendList->appendData(username);
    writeFriends();
}

/*void User::friendRequests()
{
    friendRequests->print();
}
*/
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
	vector<string> timeline;
	string stats;
	string statusString = userName + "Status";
	ifstream statusFile;
	statusFile.open(statusString.c_str());

	while (!statusFile.eof()){
		getline(statusFile, stats);
		timeline.push_back(stats);
	}
	statusFile.close();

	reverse(timeline.begin(), timeline.end());

	for (int i = 0; i < timeline.size(); i++){
		cout << "\t\t"; cout << timeline[i] << endl;
	}
}



#endif