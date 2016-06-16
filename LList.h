#ifndef LLIST_H
#define LLIST_H
#include "Node.h"
#include <iostream>
#include <vector>

using namespace std;

template<typename T> 
class LList{
	friend class User;
public:
	LList(){}
	/*counts the nuber of nodes in the list
	*/
	int count() const;
	/* adds a node to the end of the linked list
	* @param data for the node to contain
	*/
	void appendData(T data);
	/* inserts a node after node containing givin data
	* @param index to insert the data into
	* @param data to be inserted
	*/
	void insertData(T oldData, T newData);
	/* replaces the node with given data with a new node containing given data
	* @param data of node to replace
	* @param data to be in the new node
	*/
	void replaceData(T oldData, T newData);
	/* removes node with given data
	* @param index of node to remove
	*/
	void removeData(T data);
	/* emties the entire list
	* sets head and tail pointer to nullptr
	*/

	void emptyList();
	virtual ~LList();

	void print() const{
		int i = 1;
		Node<T>* node = headNode;
		while (node){
			cout << "\t\t[" << i << "] " << node->getData() << endl;
			node = node->next();
			i++;
		}
	}

	void FileWrite(string filename) const{
		Node<T>* node = headNode;
		ofstream writeFile(filename);
		while (node){
			writeFile << node->getData() << endl;
			node = node->next();
		}
	}

	vector<T> returnData() const{
		vector<T> data;
		Node<T>* node = headNode;
		while (node){
			data.push_back(node->getData());
			node = node->next();
		}
		return data;
	}

	Node<T>* searchNode(T data);
protected:
	Node<T>* headNode = nullptr;
	Node<T>* tailNode = nullptr;
private:
	/* searches and returns Node that points to node of given data
	*@ param data returned node is to contain
	* if data is not in list, or if data is in headNode, returns nullptr
	*/
	
	/*inserts a new node after the givin node
	*@param node, node that comes before the new node
	*@param newNode, node that will be inserted after the node
	*/
	void insertNode(Node<T>* node, Node<T>* newNode);
};


template<typename T>
int LList<T>::count() const{
	int count = 0;
	if (headNode){
		Node<T>* node = headNode;
		while (node != nullptr){
			++count;
			node = node->next();
		}
	}
	return count;
}

template<typename T>
void LList<T>::appendData(T data){
	if (tailNode){
		//cout << "append started"
		Node<T>* node = new Node<T>;
		tailNode->setLink(node);
		tailNode = node;
		node->setData(data);
	}
	else{
		headNode = new Node<T>;
		headNode->setData(data);
		tailNode = headNode;
	}
}

template<typename T>
void LList<T>::insertData(T oldData, T newData){
	Node<T>* newNode = new Node<T>(newData);
	if (headNode){
		if (headNode->getData() == oldData){
			insertNode(headNode, newNode);
			return;
		}
		Node<T>* oldNode = searchNode(oldData);
		if (oldNode) oldNode = oldNode->next();
		if (oldNode == tailNode)  tailNode = newNode;
		if (oldNode && oldNode->getData() == oldData){
			insertNode(oldNode, newNode);
		}
	}
}

template<typename T>
void LList<T>::replaceData(T oldData, T newData){
	if (headNode){
		if (headNode->getData() == oldData){
			headNode->setData(newData);
		}
		Node<T>* node = searchNode(oldData);
		if (node){
			Node<T>* oldNode = node->next();
			oldNode->setData(newData);
		}
	}
}

template<typename T>
void LList<T>::removeData(T data){
	if (headNode){
		if (headNode->getData() == data){
			if (headNode->next()){
				Node<T>* remNode = headNode;
				headNode = headNode->next();
				delete remNode;
			}
			else{
				delete headNode;
				headNode = nullptr;
				tailNode = nullptr;
			}
		}
		else{
			Node<T>* node = searchNode(data);
			if (node){
				Node<T>* remNode = node->next();
				if (!remNode->next()){
					tailNode = node;
					node->setLink(nullptr);
					delete remNode;
				}
				else{
					node->setLink(remNode->next());
					delete remNode;
				}
			}
		}
	}
}

template<typename T>
LList<T>::~LList(){
	Node<T>* node = headNode;
	Node<T>* nextNode;
	if (headNode){
		while (nextNode = node->next()){
			delete node;
			node = nextNode;
		}
		delete node;
	}
}

template<typename T>
Node<T>* LList<T>::searchNode(T data){
	Node<T>* current = headNode;
	if (current->getData() == data) return nullptr;
	while (current->next() && ((current->next())->getData()) != data){
		current = current->next();
	}
	if (!current->next()) return nullptr;
	return current;
}

template<typename T>
void LList<T>::insertNode(Node<T>* node, Node<T>* newNode){
	newNode->setLink(node->next());
	node->setLink(newNode);
}

template<typename T>
void LList<T>::emptyList(){
	Node<T>* node = headNode;
	Node<T>* nextNode;
	if (headNode){
		while (nextNode = node->next()){
			delete node;
			node = nextNode;
		}
		delete node;
		headNode = nullptr;
		tailNode = nullptr;
	}
}
#endif