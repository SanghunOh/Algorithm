#include    <iostream>

class RBNode{
private:
    int key;
    RBNode* left;
    RBNode* right;
    RBNode* parent;

public:
    RBNode();
    RBNode(RBNode &&) = default;
    RBNode(const RBNode &) = default;
    RBNode &operator=(RBNode &&) = default;
    RBNode &operator=(const RBNode &) = default;
    ~RBNode();

    RBNode(const int key)
        : key(key), left(nullptr), right(nullptr), parent(nullptr) {}

    int getKey(){
        return this->key;
    }

    RBNode* getLeft(){
        return left;
    }

    RBNode* getRight(){
        return right;
    }

    RBNode* getParent(){
        return parent;
    }

    RBNode* setKey(int _key){
        key = _key;
    }

    RBNode* setLeft(RBNode* _left){
        left = _left;
    }

    RBNode* setRight(RBNode* _right){
        right = _right;
    }

    RBNode* setParent(RBNode* _parent){
        parent = _parent;
    }


    friend class RBTree;
};

class RBTree{
private:
    RBNode* head;

public:
    RBTree(){
        head = NULL;
    }

    RBNode* getHead(){
        return head;
    }

    void insert(int key){
        RBNode* n = new RBNode(key);

        if(!head){
            head = n;
            return;
        }

        RBNode* temp = head;
        while(1){
            if(key > temp->key){
                if(temp->right)
                    temp = temp->right;
                else{
                    temp->right = n;
                    break;
                }
            }
            else{
                if(temp->left)
                    temp = temp->left;
                else{
                    temp->left = n;
                    break;
                }
            }
        }
    }

    void inorderTraverse(RBNode* root){
        if(!root)
            return;
        
        inorderTraverse(root->left);
        std::cout << root->key << std::endl;
        inorderTraverse(root->right);
    }
    
};

/*
RBNode::RBNode()
    : key(0), left(nullptr), right(nullptr), parent(nullptr) {}

RBNode::RBNode(int key)
    : key(key), left(nullptr), right(nullptr), parent(nullptr) {}

RBNode::RBNode(const RBNode& R){
    key = R.key;
    left = R.left;
    right = R.right;
    parent = R.parent;
}

RBNode::RBNode(RBNode&& R){
    key = R.key;
    left = R.left;
    right = R.right;
    parent = R.parent

    R.key = 0;
    R.left = nullptr;
    R.right = nullptr;
    R.parent = nullptr;
}
*/

RBNode::~RBNode(){
    if(left)
        delete left;
    if(right)
        delete right;
    if(parent)
        delete parent;
}

int main() {
    RBTree root;
    root.insert(10);
    root.insert(3);
    root.insert(1);
    root.insert(4);
    root.insert(15);
    root.insert(13);  
    
    root.inorderTraverse(root.getHead()); 
    return 0;
}