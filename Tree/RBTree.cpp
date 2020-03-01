#include    <iostream>

class RBNode{
public:
    RBNode();
    RBNode(RBNode &&) = default;
    RBNode(const RBNode &) = default;
    RBNode &operator=(RBNode &&) = default;
    RBNode &operator=(const RBNode &) = default;
    ~RBNode();

    RBNode(int);

private:
    int key;
    RBNode* left;
    RBNode* right;
    RBNode* parent;
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


    return 0;
}