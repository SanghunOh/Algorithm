#include	<iostream>

class Tree;

class Node{
protected:
	Node* left;
	Node* right;
	Node* parent;
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

	Node* getParent(){
		return parent;
	}

	void makeRight(Node* n){
		n->parent = this;
		right = n;
	}

	void makeLeft(Node* n){
		n->parent = this;
		left = n;
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
					temp->makeRight(n);
				}
			}
			else{
				if(temp->getLeft()){
				
				}
				else{
					temp->makeLeft(n);
				}
			}
		}
	}

	void del(int data){
		Node* del_node = search(data);

		if(!del_node->getLeft() && !del_node->getRight()){
			if(data > del_node->getParent()->getKey())
				del_node->getParent()->makeRight(nullptr);
			else
				del_node->getParent()->makeLeft(nullptr);
			delete del_node;
		}
		else if(!del_node->getLeft() || !del_node->getRight()){
			Node* n = del_node->getLeft() ? del_node->getLeft() : del_node->getRight();

			if(data > del_node->getParent()->getKey())
				del_node->getParent()->makeRight(n);
			else
				del_node->getParent()->makeLeft(n);
			delete del_node;
		}
		else{
			Node* par = del_node->getParent();
			Node* min = findMinimum(del_node);

			min->getParent()->makeLeft(nullptr);

			del_node->setKey(min->getKey());
			
			del(min->getKey());
		}
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

	Node* findMinimum(Node* n) {
		while(n->getLeft())
			 n = n->getLeft();
		return n;
	}

	Node* findMaximum(Node* n){
		while(n->getRight())
			n = n->getRight();
		return n;
	}

	Node* findSuccessor(Node* N){
		if(N->getRight())
			return findMinimum(N->getRight());
	
		Node* y = N->getParent();
	while(y && N == y->getRight()){
			N = y;
			y = y->getParent();
		}
		return y;
	}
};

class AVLTree : public BSTree{

};

int main(){

	return 0;
}
