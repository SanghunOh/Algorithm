#include	<iostream>

class LinkedTree{
private:
	int data;
	LinkedTree* left;
	LinkedTree* right;
	LinkedTree* parent;

public:
	LinkedTree()
		: data(0), left(NULL), right(NULL), parent(NULL) {}

	LinkedTree(int data)
		: data(data), left(NULL), right(NULL), parent(NULL) {}

	LinkedTree& getLeftChild(){
		return *left;
	}

	LinkedTree& getRightChild(){
		return *right;
	}

	LinkedTree& getParent(){
		return *parent;
	}

	int getData(){
		return data;
	}

	void addRight(int data){
		right = new LinkedTree(data);
		right->parent = this;
	}

	void addRight(LinkedTree t){
		*right = t;
		right->parent = this;
	}

	void addLeft(int data){
		left = new LinkedTree(data);
		left->parent = this;
	}

	void addLeft(LinkedTree t){
		*left = t;
		left->parent = this;
	}
};

class Tree{
private:
	LinkedTree* head;

public:
	Tree(){
		LinkedTree* n = new LinkedTree();
		head = n;
	}

	LinkedTree& getHead(){
		return *head;
	}
};

int main(){
	Tree root;

	root.getHead().addLeft(1);
	root.getHead().addRight(2);

	std::cout << root.getHead().getLeftChild().getData() << std::endl;
	std::cout << root.getHead().getRightChild().getData() << std::endl;
	std::cout << root.getHead().getRightChild(). getParent().getData() << std::endl;

	return 0;
}
