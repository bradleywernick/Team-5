//Bradley Wernick
//Sehej Sohal

#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include <iostream>

template<class T> class Queue{
private:
	Node<T>* head; //front of the queue
	Node<T>* tail; //back of the queue
	int count; //size of queue

public:
	Queue(); //constructor, default
	Queue(Node<T>*); //constructor, takes a node
	Queue(const Queue&); //constructor, takes another queue
	~Queue();

	void Enqueue(T); //takes data in to queue 
	void Dequeue(T&); //removes first item from queue
	void Front(T&); //gets the front of the  queue, passes back by reference.
	void Rear(T&); //gets the back of the  queue, passes back by reference.
	int Size(); //returns count
	bool Empty(); //checks if the queue is empty
	void printQueue(); //print the queue

	void DestroyQueue(); //destroy the queue
};

template<class T> Queue<T>::Queue(){
	head = NULL; //to NULL
	tail = NULL; //to NULL
	count = 0; //no items = count is 0
}

template<class T> Queue<T>::Queue(Node<T>* newNode){
	head = tail = newNode; //all to newNode
	head->next = newNode->next; //head's next item is newNode's next item
	tail->next = NULL; //after tail is NULL
	count = 1; //since 1 node, count is 1
}

template<class T> Queue<T>::Queue(const Queue& other){
	head = other.head; //set head to other's tail
	tail = other.tail; //set tail to other's tail
	head->next = other.head->next; //head's next is other's head's next
	tail->next = NULL; //after tail is NULL
	count = other.count; //set to other queue count
}

template<class T> Queue<T>::~Queue(){
	while (head != NULL){
		head = head->next;
	}
}

template<class T> int Queue<T>::Size(){
	return count; //return count, which is size of queue
}

template<class T> void Queue<T>::Enqueue(T info){
	Node<T>* enqueueNode = new Node<T>(); //to hold info
	enqueueNode->data = info; //take info
	enqueueNode->next = NULL; //set next to NULL

	if (head == NULL){ //if nothing
		head = tail = enqueueNode; //all equals newNode
		tail->next = NULL;
	}else{ //otherwise
		tail->next = enqueueNode; //item after last is newNode
		tail = enqueueNode; //move to newNode
		tail->next = NULL; //item after last is now NULL, as nothing follows last
	}
	count++; //increment number of items in queue
}

template<class T> void Queue<T>::Dequeue(T& dataOut){
	
	if (head == NULL){ return; } //if nothing, return
	else{
		count--; //decrement number of items in queue
		Node<T>* dequeueNode = head; //set dequeue node to head
		dataOut = dequeueNode->data; //get the data
		head = head->next; //head moves to next item in queue
		delete(dequeueNode); //delete the old head
		cout << "Removed " << dataOut << " from Queue." << endl;
		return;
	}
	return; //code should never reach here
}

template<class T> void Queue<T>::Front(T& dataOut){
	if (head != NULL){ //if head is not NULL
		dataOut = head->data; //get the data
		return;
	}
	return;
}

template<class T> void Queue<T>::Rear(T& dataOut){
	if (tail != NULL){ //if tail is not NULL
		dataOut = tail->data; //get the data
		return;
	}
	return;
}

template<class T> bool Queue<T>::Empty(){
	if (head == NULL){ //if head is empty, return true
		return true;
	}else{ //otherwise, false
		return false;
	}
}

template<class T> void Queue<T>::printQueue(){
	Node<T> *tempHead = new Node<T>();  //tempHead
	tempHead = head; //set to head

	if (head == NULL){ //if NULL
		cout << "Empty Queue." << endl; //Queue is empty
	}else{
		while (tempHead != NULL){ //while not NULL
			cout << tempHead->data << endl; //output data
			tempHead = tempHead->next; //move to next
		}
	}

	delete tempHead;
}

template<class T> void Queue<T>::DestroyQueue(){
	T temp; 
	while (head != NULL){
		Dequeue(temp);
	}
	cout << endl;
	return;
}

#endif