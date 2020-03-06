#include	<iostream>

class Tree;

class Node{
protected:
	Node* left;
	Node* right;
	int key;

public:
	Node() : left(nullptr), right(nullptr), key(0) {}

	Node(int key) : left(nullptr), right(nullptr), key(key) {}

	void setKey(int _key){
		key = _key;
	}

	int getKey(){
		return key;
	}

	Node* getLeft(){
		return left;
	}

	Node* getRight(){
		return right;
	}

	void makeRight(Node* par, Node* n){
		par->right = n;
	}

	void makeLeft(Node* par, Node* n){
		par->left = n;
	}

	~Node(){
		if(left)
			delete left;
		if(right)
			delete right;
	}

	friend Tree;
};

class Tree{
protected:
	Node* root;

public:
	Tree()
		:root(nullptr) {}

	Tree(Node* rt)
		:root(rt) {}

	Node* getRoot(){
		return root;
	}
};

class BSTree : public Tree{
public:
	BSTree() : Tree(){}

	void insert(int data){
		Node* n = new Node(data);

		if(!root){
			root = n;
			return;
		}

		Node* temp = root;
		while(1){
			if(data > temp->getKey()){
				if(temp->getRight()){
					
				}
				else{
					temp->makeRight(temp, n);
				}
			}
			else{
				if(temp->getLeft()){
				
				}
				else{
					temp->makeLeft(temp, n);
				}
			}
		}
	}

	void del(){
		
	}

	Node* search(int data){
		Node* temp = root;

		while(temp){
			if(temp->getKey() == data)
				return temp;
			if(data > temp->getKey())
				temp = temp->getRight();
			else
				temp = temp->getLeft();
		}
	}
};

class AVLTree : public BSTree{

};

int main(){

	return 0;
}
