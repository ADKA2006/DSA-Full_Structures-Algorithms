#ifndef TreeNode_hpp
#define TreeNode_hpp

template<class K, class V>
struct TreeNode{
  K key;
  V value;
  TreeNode *left, *right;

  TreeNode(K key, V value,  TreeNode *left, TreeNode *right)
  {
    this->value = value;
    this->key = key;
    this->left = left;
    this->right = right;
  } 
};

template <class T>
class SingleValTreeNode {
    public:
        T data;
        SingleValTreeNode<T>* lnode;
        SingleValTreeNode<T>* rnode;
};


template <class T>
SingleValTreeNode<T> *createTreeNode(T value) {
    SingleValTreeNode<T> *newNode = new SingleValTreeNode<T>();
    newNode->data = value;
    newNode->lnode = nullptr;
    newNode->rnode = nullptr;

    return newNode;
}

template <class T>
SingleValTreeNode<T> *createTreeNode(T value,SingleValTreeNode<T> *lnode,SingleValTreeNode<T> *rnode) {
    SingleValTreeNode<T> *newNode = new SingleValTreeNode<T>();
    newNode->data = value;
    newNode->lnode = lnode;
    newNode->rnode = rnode;
    
    return newNode;
}

#endif