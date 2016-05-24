//Bradley Wernick
#ifndef BSTNODE_H
#define BSTNODE_H

#include <string>

template<class T> class bstNode{
public:
	//constructors
	bstNode<T>(){ left = NULL; right = NULL; };
	bstNode<T>(const T &d){ left = NULL; right = NULL; data = d; }
	bstNode<T>(const Node<T> &other){ data = other.data; left = other->left; right = other->right; }

	//members
	T data; //The data, type generic.
	bstNode<T>* left; //Points to next node
	bstNode<T>* right; //Points to previous node

	//operator overload
	bstNode<T> &operator=(const bstNode<T>&);
};

#endif