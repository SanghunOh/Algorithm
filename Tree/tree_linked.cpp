#include	<iostream>
#include	<queue>

int N;
bool* visit;

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

	LinkedTree*& getLeftChildP(){
		return left;
	}

	LinkedTree& getRightChild(){
		return *right;
	}

	LinkedTree*& getRightChildP(){
		return right;
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
		N++;
	}

	void addRight(LinkedTree t){
		*right = t;
		right->parent = this;
		N++;
	}

	void addLeft(int data){
		left = new LinkedTree(data);
		left->parent = this;
		N++;
	}

	void addLeft(LinkedTree t){
		*left = t;
		left->parent = this;
		N++;
	}
};

class Tree{
private:
	LinkedTree* head;
	std::queue<LinkedTree*> q;
public:
	Tree(){
		LinkedTree* n = new LinkedTree();
		head = n;
	}

	LinkedTree& getHead(){
		return *head;
	}

	LinkedTree*& getHeadP(){
		return head;
	}

	void inorderTraversal(LinkedTree*& root){
		if(!root)
			return;

		inorderTraversal(root->getLeftChildP());
		std::cout << root->getData() << std::endl;
		inorderTraversal(root->getRightChildP());
	}

	void preorderTraversal(LinkedTree*& root){
		if(!root)
			return;

		std::cout << root->getData() << std::endl;
		preorderTraversal(root->getLeftChildP());
		preorderTraversal(root->getRightChildP());
	
	}

	void postorderTraversal(LinkedTree*& root){
		if(!root)
			return;

		postorderTraversal(root->getLeftChildP());
		postorderTraversal(root->getRightChildP());
		std::cout << root->getData() << std::endl;
	}

	void levelorderTraversal(){
		visit = new bool[N];
		for(int i=0 ; i<N ; i++)
			visit[i] = false;

		visit[0] = true;
		q.push(head);
	}
};

int main(){
	Tree root;

	root.getHead().addLeft(1);
	root.getHead().addRight(2);

	std::cout << root.getHead().getLeftChild().getData() << std::endl;
	std::cout << root.getHead().getRightChild().getData() << std::endl;
	std::cout << root.getHead().getRightChild(). getParent().getData() << std::endl;
	std::cout << std::endl;

	root.inorderTraversal(root.getHeadP());
	std::cout << std::endl;

	root.getHead().getLeftChild().addLeft(7);
	root.getHead().getLeftChild().getLeftChild().addLeft(9);
	root.getHead().getLeftChild().addRight(8);

	root.inorderTraversal(root.getHeadP());
	std::cout << std::endl;

	root.preorderTraversal(root.getHeadP());
	std::cout << std::endl;

	root.postorderTraversal(root.getHeadP());
	std::cout << std::endl;

	return 0;
}
