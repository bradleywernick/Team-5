#ifndef NODE_H
#define NODE_H

using namespace std;

template<typename T>
class Node {
	public:
		Node(){}
		Node(T data){
			nodeData = data;
		}
		// accessors
		Node<T>* next(){ return nodePtr; }
		T getData(){ return nodeData; }
		//mutators 
		void setData(T data){ nodeData = data; }
		void setLink(Node<T>* node){ nodePtr = node; }
	private:
		Node<T>* nodePtr = nullptr;
		T nodeData;
};
#endif