#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp
#include "TreeNode.hpp"

template <class T>
class BST {
    private:
        TreeNode<T> *root;
        int count;
    public:
        BST();
        ~BST();
        void insert(T value);
        bool deleteNode(T value);
        TreeNode<T> *getRoot();  
        bool search(T value);
        int size();
        bool isEmpty();
};

template <class T>
BST<T>::BST() {
    root = nullptr;
    count = 0;
}

template <class T>
BST<T>::~BST() {
    root = nullptr;
}

template <class T>
TreeNode<T>* BST<T>::getRoot() {
    return root;
}

template <class T>
void BST<T>::insert(T elt) {
    TreeNode<T> *node = createTreeNode(elt);
    if (root == nullptr) {
        root = node;
        count++;
    } else {
        TreeNode<T> *ptr = root;
        TreeNode<T> *parent = nullptr;
        while (ptr != nullptr){
            parent = ptr;
            if (elt >= ptr->data){
                ptr = ptr->rnode;
            } else {
                ptr = ptr->lnode;
            }
        }
        if (elt >= parent->data) {
            parent->rnode = node;
        } else {
            parent->lnode = node;
        }
        count++;
    }    
}

template <class T>
bool BST<T>::deleteNode(T value){
    TreeNode<T> *ptr = root;
    TreeNode<T> *par = nullptr;

    // Search for the node to delete
    while (ptr != nullptr && ptr->data != value) {
        par = ptr;
        if (value < ptr->data) ptr = ptr->lnode;
        else ptr = ptr->rnode;
    }

    if (ptr == nullptr) return false; // Not found

    // Case 1: Node to be deleted is having no children (leaf)
    if (ptr->lnode == nullptr && ptr->rnode == nullptr) {
        if (par == nullptr) {
            // Deleting root node
            delete ptr;
            root = nullptr;
        } else {
            if (par->lnode == ptr) par->lnode = nullptr;
            else par->rnode = nullptr;
            delete ptr;
        }
    }
    // Case 2: Node to be deleted is having only left child
    else if (ptr->rnode == nullptr) {
        if (par == nullptr) {
            TreeNode<T>* temp = ptr;
            root = ptr->lnode;
            delete temp;
        } else {
            if (par->lnode == ptr) par->lnode = ptr->lnode;
            else par->rnode = ptr->lnode;
            delete ptr;
        }
    }
    // Case 3: Node to be deleted is having only right child
    else if (ptr->lnode == nullptr) {
        if (par == nullptr) {
            TreeNode<T>* temp = ptr;
            root = ptr->rnode;
            delete temp;
        } else {
            if (par->lnode == ptr) par->lnode = ptr->rnode;
            else par->rnode = ptr->rnode;
            delete ptr;
        }
    }
    // Case 4: Node to be deleted is having two children
    else {
        // Smallest value in the right subtree
        TreeNode<T>* succPar = ptr;
        TreeNode<T>* succ = ptr->rnode;
        while (succ->lnode != nullptr) {
            succPar = succ;
            succ = succ->lnode;
        }
        ptr->data = succ->data;
        if (succPar->lnode == succ) {
            succPar->lnode = succ->rnode;
        } else {
            succPar->rnode = succ->rnode;
        }
        delete succ;
    }
    count--;
    return true;
}

template <class T>
bool BST<T>::search(T value){
    TreeNode<T> *ptr = root;
    while (ptr != nullptr){
        if (ptr->data == value) {
            return true;
        } else if (value < ptr->data) {
            ptr = ptr->lnode;
        } else {
            ptr = ptr->rnode;
        }
    }
    return false;
}

template <class T>
int BST<T>::size(){
    return count;
}

template <class T>
bool BST<T>::isEmpty(){
    return (count == 0) ? true : false;
}

#endif
