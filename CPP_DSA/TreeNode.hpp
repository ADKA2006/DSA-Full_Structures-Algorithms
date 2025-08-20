#ifndef TreeNode_hpp
#define TreeNode_hpp

template <class T>
class TreeNode {
    public:
        T data;
        TreeNode<T>* lnode;
        TreeNode<T>* rnode;

};


template <class T>
TreeNode<T> *createTreeNode(T value) {
    TreeNode<T> *newNode = new TreeNode<T>();
    newNode->data = value;
    newNode->lnode = nullptr;
    newNode->rnode = nullptr;

    return newNode;
}

template <class T>
TreeNode<T> *createTreeNode(T value,TreeNode<T> *lnode,TreeNode<T> *rnode) {
    TreeNode<T> *newNode = new TreeNode<T>();
    newNode->data = value;
    newNode->lnode = lnode;
    newNode->rnode = rnode;
    
    return newNode;
}

#endif