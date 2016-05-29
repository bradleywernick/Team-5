#ifndef BSTADT_H
#define BSTADT_H

#include "bstNode.h"
#include <iostream>

template<class T> class bstADT{
private:
	bstNode<T>* root; //root node of tree

	void insert(T data, bstNode<T> *leaf); //takes a node and data, move through tree depending on data and provided node
	bstNode<T>* search(T data, bstNode<T> *leaf); //search for the node 
	void destroy(bstNode<T>* leaf); //destroys the tree through recursion
	int countNodes(bstNode<T> *leaf); //count the nodes in the tree
	
	void preorderPrint(bstNode<T> *leaf); //print preorder tree
	void postorderPrint(bstNode<T> *leaf); //print postorder tree
	void inorderPrint(bstNode<T> *leaf); //print inorder tree

	bstNode<T>* rr_rotation(bstNode<T>* leaf); //right-right rotation
	bstNode<T>* ll_rotation(bstNode<T>* leaf); //left-left rotation
	bstNode<T>* lr_rotation(bstNode<T>* leaf); //left-right rotation
	bstNode<T>* rl_rotation(bstNode<T>* leaf); //right-left rotation

public:
	bstADT(); //constructor
	~bstADT(); //destructor

	void insert(T data); //public insert method
	void destroyTree(); //public destroy method
	bstNode<T>* search(T data); //public search method
	int countNodes(); //count the nodes in the tree
	void preorderPrint(); //print preorder tree
	void postorderPrint(); //print postorder tree
	void inorderPrint(); //print inorder tree


	int height(bstNode<T> *leaf); //height of tree
	int difference(bstNode<T> *leaf); //height difference of tree
	bstNode<T>* balanceTree(bstNode<T>* leaf); //balance the tree
};

template<class T> bstADT<T>::bstADT(){
	root = NULL; //set root to null
}

template<class T> bstADT<T>::~bstADT(){
	destroyTree(); //call destroy tree
}

template<class T> int bstADT<T>::countNodes(){
	return countNodes(root);
}

template<class T> int bstADT<T>::countNodes(bstNode<T>* leaf){
	if (leaf == NULL){ return 0; }
	else{
		int count = 1;
		count += countNodes(leaf->left); //Add the number nodes in the left subtree to count
		count += countNodes(leaf->right); //Add the number nodes in the right subtree to count
		return count;
	}
}

template<class T> void bstADT<T>::insert(T data){
	if (root != NULL){ //if root is not NULL
		insertNode(data, root); //insert at root
	}else{ //if root is NULL
		root = new bstNode<T>(); //root is a new node
		root->data = data; //set the data
		root->left = NULL; //nothing on left
		root->right = NULL; //nothing on right
	}
}

template<class T> void bstADT<T>::insert(T data, bstNode<T> *leaf){
	if (data < leaf->data){ //if the data is less than the node's data
		if (leaf->left != NULL){ //if the input node is not null 
			insertNode(data, leaf->left); //try again moved one node to the left
		}else{
			leaf->left = new bstNode<T>(); //make right child node of leaf a node
			leaf->left->data = data; //set the left child node of leaf to the data
			leaf->left->left = NULL; //set left child node of left of leaf to NULL
			leaf->left->right = NULL; //set right child node of left of leaf to NULL
		}
	}else if(data > leaf->data){ //if the data ois greater than the node's data
		if (leaf->right != NULL){ //if the input node is not null, move a node to the right
			insertNode(data, leaf->right); //try again moved one node to the right
		}else{
			leaf->right = new bstNode<T>(); //make right child node of leaf a node
			leaf->right->data = data; //set the right child node of leaf to the data
			leaf->right->left = NULL; //set left child node of right of leaf to NULL
			leaf->right->right = NULL; //set right child node of right of leaf to NULL
		}
	}
}

template<class T> bstNode<T>* bstADT<T>::search(T data){
	return search(data, root); //start the search at root
}

template<class T> bstNode<T>* bstADT<T>::search(T data, bstNode<T> *leaf){
	if (leaf != NULL){ //if there is data
		if (data == leaf->data){ return leaf; } //if equals to, return leaf
		if (data < leaf->data){ return search(data, leaf->left); } //if less than, move a node to the left
		else{ return search(data, leaf->right); } //otherwise, move a node to the right
	}else{ //if null
		return NULL; //return null
	}
}

template<class T> void bstADT<T>::destroyTree(){
	destroy(root);
}

template<class T> void bstADT<T>::destroy(bstNode<T> *leaf){
	if (leaf != NULL){
		destroy(leaf->left);
		destroy(leaf->right);
		delete leaf;
	}
}

template<class T> void bstADT<T>::preorderPrint(){ preorderPrint(root); }
template<class T> void bstADT<T>::postorderPrint(){ postorderPrint(root); }
template<class T> void bstADT<T>::inorderPrint(){ inorderPrint(root); }

template<class T> void bstADT<T>::preorderPrint(bstNode<T>* leaf){
	if (leaf != NULL){ //if root is NULl, noothing to print
		cout << leaf->data << " "; //print data in leaf
		preorderPrint(leaf->left); //print data in leaf left subtree
		preorderPrint(leaf->right); //print data in leaf right subtree
	}
}

template<class T> void bstADT<T>::postorderPrint(bstNode<T>* leaf){
	if (root != NULL){ //if root is NULl, noothing to print
		postorderPrint(leaf->left); //print data in leaf left subtree
		postorderPrint(leaf->right); //print data in leaf right subtree
		cout << leaf->data << " "; //print data in leaf
	}
}

template<class T> void bstADT<T>::inorderPrint(bstNode<T>* leaf){
	if (root != NULL){ //if root is NULl, noothing to print
		inorderPrint(leaf->left); //print data in leaf left subtree
		cout << leaf->data << " "; //print data in leaf
		inorderPrint(leaf->right); //print data in leaf right subtree
	}
}

template<class T> int bstADT<T>::height(bstNode<T>* leaf){
	int h = 0;
	if (leaf != NULL){
		int leftHeight = height(leaf->left); //get height of left subtree
		int rightHeight = height(leaf->right); //get height of right subtree
		int temp = max(leftHeight, rightHeight); //get the largest value
		h = temp + 1; //add 1 for base node
		return h; //return h
	}else{
		return h;
	}
}

template<class T> int bstADT<T>::difference(bstNode<T>* leaf){
	int leftHeight = height(leaf->left); //get height of left subtree
	int rightHeight = height(leaf->right); //get height of right subtree
	int balancing = (leftHeight - rightHeight); //get the difference
	return balancing; //return
}

template<class T> bstNode<T>* bstADT<T>::rr_rotation(bstNode<T>* leaf){
	bstNode<T>* temp; //temp node
	temp = leaf->right; //temp takes leaf->right
	leaf->right = temp->left; //temp->right takes leaf->left
	temp->left = leaf; //temp->left is leaf
	return temp; //temp has all of leaf's values, return temp
}

template<class T> bstNode<T>* bstADT<T>::ll_rotation(bstNode<T>* leaf){
	bstNode<T>* temp; //temp node
	temp = leaf->left; //temp takes leaf->left
	leaf->left = temp->right; //temp->left takes leaf->right
	temp->right = leaf; //temp->right is leaf
	return temp; //temp has all of leaf's values, return temp
}

template<class T> bstNode<T>* bstADT<T>::lr_rotation(bstNode<T>* leaf){
	bstNode<T>* temp; //temp node
	temp = leaf->left; //temp takes leaf->left
	leaf->left = rr_rotation(temp); //leaf->left is a right-right rotation of current temp
	return ll_rotation(leaf); //return a left-left rotation of current leaf
}

template<class T> bstNode<T>* bstADT<T>::rl_rotation(bstNode<T>* leaf){
	bstNode<T>* temp; //temp node
	temp = leaf->right; //temp takes leaf->right
	leaf->right = ll_rotation(temp); //leaf->right is a left-left rotation of current temp
	return rr_rotation(leaf); //return a right-right rotation of current leaf
}

template<class T> bstNode<T>* bstADT<T>::balanceTree(bstNode<T>* leaf){ //leaf should be the root node of tree, just saying 
	int balancer = difference(leaf); //get the weight of both sides of the tree and determine whci his heavier

	if (balancer > 1){ //if left heavy
		if (difference(leaf->left) > 0){ //if left subtree is left heavy
			leaf = ll_rotation(leaf); //do left-left rotation
		}else{ //otherwise
			leaf = lr_rotation(leaf); //do left-right rotation
		}
	}else if (balancer < -1){ //if right heavy
		if (difference(leaf->right) > 0){ //if right subtree is left heavy
			leaf = rl_rotation(leaf); //do right-left rotation
		}else{ //otherwise
			leaf = rr_rotation(leaf); //do right-right rotation
		}
	}

	//if 0, nothing happens, tree is balanced
	return leaf; //return leaf
}

#endif
