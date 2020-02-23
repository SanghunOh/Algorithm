#include	<iostream>

class Tree{
private:
	int num;

public:
	Tree(int n) : num(n) {}
};

class Node{
private:
	int data;
	Node* leftC;
	Node* rightC;
	Node* parent;

public:
	Node(int data)
		: data(data), leftC(NULL), rightC(NULL), parent(NULL) {}

	int getData() const{
		return data;
	}

	const Node* returnThis() const{
		return this;
	}

	Node* rightChildP() const{
		return rightC;
	}

	Node* leftChildP() const{
		return leftC;
	}

	Node* getParent() const{
		return parent;
	}

	void makeRightC(Node*& n){
		n->parent = this;
		rightC = n;
	}

	void makeLeftC(Node*& n){
		n->parent = this;
		leftC = n;
	}
};

class BSTree : public Tree{
private:
	Node* head;

public:
	BSTree(int n)
		: Tree(n), head(NULL) {}

	Node* getHead(){
		return head;
	}

	void insert(int data){
		Node* n = new Node(data);
		Node* x = head;
		Node* y = NULL;

		while(x != NULL){
			y = x;
			if(data > x->getData())
				x = x->rightChildP();
			else
				x = x->leftChildP();
		}

		if(!y)
			head = n;
		else{
			if(data > y->getData())
				y->makeRightC(n);
			else
				y->makeLeftC(n);
		}
	}

	Node& _search(int data){
		return search(head, data);
	}
	Node& search(Node* N, int data){
		if(!N || data == N->getData())
			return *N;

		if(data > N->getData())
			return search(N->rightChildP(), data);
		else
			return search(N->leftChildP(), data);
	}
	
	const Node* _searchP(int data){
		return searchP(head, data);
	}

	const Node* searchP(const Node* N, int data){
		if(!N || data == N->getData())
			return N;

		if(data <= N->getData())
			return searchP(N->leftChildP(), data);
		else
			return searchP(N->rightChildP(), data);
	}

	Node* iterSearch(int data){
		if(!head)
			return NULL;

		Node* temp1 = head;
		while(temp1 && data != temp1->getData()){
			if(data > temp1->getData())
				temp1 = temp1->rightChildP();
			else
				temp1 = temp1->leftChildP();
		}

		return temp1;
	}

	void delete_node(){

	}

	void inorderTraversal(const Node* n){
		if(!n)
			return;
		inorderTraversal(n->leftChildP());
		std::cout << n->getData() << std::endl;
		inorderTraversal(n->rightChildP());
	}

	void inorderTraverse(){
		inorderTraversal(head);
	}

	Node* findMinimum(Node* N) const{
		while(N->leftChildP())
			N = N->leftChildP();
		return N;
	}

	Node* findMaximum(Node* N) const{
		while(N->rightChildP())
			N = N->rightChildP();
		return N;
	}

	Node* findSuccessor(Node* N) const{
		if(N->rightChildP())
			return findMinimum(N->rightChildP());

		Node* y = N->getParent();
		while(y && N == y->rightChildP()){
			N = y;
			y = y->getParent();
		}
		return y;
	}

	Node* findPredecessor(Node* N) const{
		if(N->leftChildP())
			return findMaximum(N->leftChildP());
		Node* y = N->getParent();
		while(y && N == y->leftChildP()){
			N = y;
			y = y->getParent();
		}
		return y;
	}

};

int main(){
	BSTree bst(100);

	bst.insert(100);
	bst.insert(50);
	bst.insert(80);
	bst.insert(10);
	bst.insert(200);
	bst.insert(150);
	bst.insert(250);
	bst.insert(120);
	bst.insert(130);
	bst.insert(1);
	bst.insert(30);

	bst.inorderTraverse();
	
	Node* a = bst.iterSearch(120);
	std::cout << a << std::endl;
	std::cout << a->getData() << std::endl;
	std::cout << bst.iterSearch(120)->getData() << std::endl;
	std::cout << bst._searchP(120)->getData() << std::endl;
	std::cout << bst._search(120).getData() << std::endl;

	std::cout << std::endl << std::endl;

	Node* t = bst.findMaximum(bst.getHead());
	bst.inorderTraverse();
	std::cout << std::endl << std::endl;
	std::cout << t->getData() << std::endl;

	std::cout << std::endl;

	std::cout << bst.findPredecessor(bst.getHead())->getData() << std::endl;
	std::cout << bst.findSuccessor(bst.getHead())->getData() << std::endl;
	return 0;
}
