#ifndef STACK_H
#define STACK_H
#include "LList.h"
#include<exception>

using namespace std;

template<typename T>
class Stack: private LList<T>{
public:
	Stack(){}
	/* Removes and returns the top element of the stack*/
	T pop();
	/*places data onto the top of the stack
	*@param data to be placed on top of stack
	*/
	void push(T data);
	bool isEmpty(){ return (tailNode == nullptr); }
private:
};

template<typename T>
T Stack<T>::pop(){
	if (tailNode){
		T data = tailNode->getData();
		removeData(tailNode->getData());
		return data;
	}
	throw range_error("misuse of 'pop', this stack is empty");
}

template<typename T>
void Stack<T>::push(T data){
	appendData(data);
}

#endif