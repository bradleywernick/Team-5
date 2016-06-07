#ifndef USER_H
#define USER_H
#include "LList.h"
#include "Queue.h"
#include "Stack.h"
#include<fstream>
#include<string>
#include<cstring>
#include<iomanip>
#include<iostream>
class User
{
protected:
	string userName;
	string name;
	string age;
	string employment;
	string school;
	string currentStatus;

	LList<string> *friendList = new LList<string>();
	Stack<string> *timeLine = new Stack<string>();
	Queue<string> *friendRequests = new Queue<string>();
public:
	//mutators
	void changeName(string newName);
	void changeAge(string newAge);
	void changeJob(string newJob);
	void changeSchool(string newSchool);
	void unFriend(string username);
	//general functions
	//void currentStatus(string status);
	//void friendRequests();
	//void acceptFriendRequest(string userame);
	//void addFriend(string username); //sends a friend request
	void write();
    void writeFriends();
	//constructors
	User() {};
	User(string username, string fullname, string job, string education, string age1) //takes 5 parametes and writes them to a file

	{
		userName = username;
		name = fullname;
		employment = job;
		school = education;
		age = age1;

		ofstream userfile;
		userfile.open(userName.c_str());
		userfile << userName << endl
			<< name << endl
			<< employment << endl
			<< school << endl
			<< age << endl;
		userfile.close();
	}
	User(string username)
	{
		ifstream userfile;
		userfile.open(username.c_str());
		if(!userfile.eof())
		{
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
			while (getline(listOfFriends, friends))
			{
				friendList->appendData(friends);
			}
		}
		else
		{
			cout << endl << "No Such User" << endl;
		}
	}
	~User()
	{
		write();
		writeFriends();
	}
};

void User::write()
{
	ofstream userfile;
	userfile.open(userName.c_str());
	userfile << userName << endl
		<< name << endl
		<< employment << endl
		<< school << endl
		<< age << endl;
	userfile.close();
}

void User::writeFriends()
{
	string friendLists = userName + "Friends";
	ofstream userfile;
	userfile.open(friendLists.c_str());

	Node<string>* node = friendList->headNode;

	while (node) 
	{
		userfile << node->getData() << endl;
		node = node->next();
	}
}

void User::changeName(string newName)
{
	name = newName;
	write();
}

void User::changeAge(string newAge)
{
	age = newAge;
	write();
}

void User::changeJob(string newJob)
{
	employment = newJob;
	write();
}

void User::changeSchool(string newSchool)
{
	school = newSchool;
	write();
}

void User::unFriend(string username)
{
	friendList->removeData(username);
	writeFriends();
}


#endif