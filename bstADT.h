//Bradley Wernick
#ifndef BSTADT_H
#define BSTADT_H

#include "bstNode.h"
#include <iostream>

template<class T> class bstADT{
private:
	//Memeber variable
	bstNode<T>* root; //root node of tree

	//Functionality
	void insertNode(T data, bstNode<T> *leaf); //takes a node and data, move through tree depending on data and provided node
	bool remove(T data, bstNode<T> *leaf); //remove node with matching data

	//For the destructor
	void destroy(bstNode<T>* leaf); //destroys the tree through recursion

	//Searches
	bstNode<T> findSmallest(bstNode<T> *leaf); //find smallest node
	bstNode<T> findLargest(bstNode<T> *leaf); //find largest node
	T searchBST(bstNode<T> *leaf, T targetkey); //search for the data in the node
	
	//Depth-first traversals
	void preorderPrint(bstNode<T> *leaf); //print preorder tree
	void postorderPrint(bstNode<T> *leaf); //print postorder tree
	void inorderPrint(bstNode<T> *leaf); //print inorder tree

public:
	bstADT(); //constructor
	~bstADT(); //destructor

	//Functionality
	void insert(T data); //public insert method, if root has data, calls the insert on root, resolves from there
	bool remove(T data); //remove a node with input data. False if failed, true if success

	//Searches
	bstNode<T> findSmallest(); //find smallest node
	bstNode<T> findLargest(); //find largest node
	T searchBST(T targetkey); //search for node with targetkey

	//Depth-first traversals
	void preorderPrint(); //print preorder tree
	void postorderPrint(); //print postorder tree
	void inorderPrint(); //print inorder tree
};

template<class T> bstADT<T>::bstADT(){
	root = NULL; //set root to null
}

template<class T> bstADT<T>::~bstADT(){
	destroy(root); //call destroy
}

template<class T> void bstADT<T>::destroy(bstNode<T>* leaf){
	if (leaf != NULL){ //if not NULL
		destroy(leaf->left); //destroy the left subtree
		destroy(leaf->right); //destroy the right subtree
		delete leaf; //delete the leaf
	} //else, if NULL, nothing to do since it is destroyed already
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

template<class T> void bstADT<T>::insertNode(T data, bstNode<T> *leaf){
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

template <class T> bool bstADT<T>::remove(T data){
	return remove(data, root);
}

template <class T> bool bstADT<T>::remove(T data, bstNode<T> *leaf){
	if (leaf == NULL){ return false; }
	if (data < leaf->data){ 
		return remove(data, leaf->left); //move to the left
	}else if (data > leaf->data){
		return remove(data, leaf->right); //move to the right
	}else{ //case node found
		if (leaf->left == NULL){ //if left subtree is empty
			leaf = leaf->right; //set right subtree to root
			return true; //success
		}else if (leaf->right == NULL){ //if right subtree is empty
			leaf = leaf->left; //set left subtree to root
			return true; //success
		}else{ //not a leaf, so find largest node on left subtree
			bstNode<T> *deleteNode = leaf; //save root in deleteNode
			bstNode<T> *largest = findLargest(leaf->left); //get the largest node of left subtree and store it
			deleteNode->data = largest->data; //deleteNode data set to largest data
			return remove(largest->data, deleteNode->left); //call remove using largest data and left subtree of deleteNode
		}
	}
}

template<class T> bstNode<T> bstADT<T>::findSmallest(){
	return findSmallest(root); //call the private method
}

template<class T> bstNode<T> bstADT<T>::findSmallest(bstNode<T> *leaf){
	if (leaf->left == NULL){ //if left subtree is empty
		return leaf; //return current node
	}
	return findSmallest(leaf->left); //else, move left a node
}

template<class T> bstNode<T> bstADT<T>::findLargest(){
	return findLargest(root); //call the private method
}

template<class T> bstNode<T> bstADT<T>::findLargest(bstNode<T> *leaf){
	if (leaf->right == NULL){ //if right subtree is empty
		return leaf; //return current node
	}
	return findLargest(leaf->right); //else, move right a node
}

template<class T> T bstADT<T>::searchBST(T targetkey){
	return searchBST(root, targetkey); //call the method starting with root
}

template<class T> T bstADT<T>::searchBST(bstNode<T> *leaf, T targetkey){
	if (leaf == NULL){ return NULL; } //if null, return null
	if (targetkey < leaf->data){
		return searchBST(leaf->left, targetkey); //move one to the left
	}else if (targetkey > leaf->data){
		return searchBST(leaf->right, targetkey); //move one to the right
	}else{ //otherwise
		return leaf->data; //return current node
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
	if (leaf != NULL){ //if root is NULl, noothing to print
		postorderPrint(leaf->left); //print data in leaf left subtree
		postorderPrint(leaf->right); //print data in leaf right subtree
		cout << leaf->data << " "; //print data in leaf
	}
}

template<class T> void bstADT<T>::inorderPrint(bstNode<T>* leaf){
	if (leaf != NULL){ //if root is NULl, noothing to print
		inorderPrint(leaf->left); //print data in leaf left subtree
		cout << leaf->data << " "; //print data in leaf
		inorderPrint(leaf->right); //print data in leaf right subtree
	}
}

#endif
