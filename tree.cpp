#include	<iostream>

template<typename T>
class TreeNode{
private:
	T data;
	TreeNode* leftchild;
	TreeNode* rightchild;

public:
	TreeNode(T data = 0, TreeNode* leftchild = NULL, TreeNode* rightchild = NULL)
		: data(data), leftchild(leftchild), rightchild(rightchild) {}
	void addLeft(T item = 0){
		if(leftchild)
			return;

		TreeNode* n = new TreeNode(item, NULL, NULL);
		leftchild = n;
	}

	void addRight(T item = 0){
		if(rightchild)
			return;

		TreeNode* n = new TreeNode<int>(item, NULL, NULL);
		rightchild = n;
	}

	TreeNode<T>*& returnRightChild(){
		return rightchild;
	}
	friend std::ostream& operator<<(std::ostream& o, const TreeNode& node){
		o << "[Data] : " << node.data << std::endl;
		if(node.leftchild)
			o << "[Left] : " << node.leftchild->data << std::endl;
		if(node.rightchild)
			o << "[Right] : " << node.rightchild->data << std::endl;
		
		return o;
	}
};

template<typename T>
class Tree{
private:
	TreeNode<T>* root;

public:
	Tree(T data = 0)
		:root(new TreeNode<T>(data)) {}
};

int main(){
	TreeNode<int> rt(0);
	TreeNode<int>* a;
	a = new TreeNode<int>(1, NULL, NULL);

	a->addRight(3);
	std::cout << (*a->returnRightChild());

	return 0;
}
