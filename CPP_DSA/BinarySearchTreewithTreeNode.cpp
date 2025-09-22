#include <iostream>
using namespace std;

template <class T>
struct TreeNode {
    public:
        T data;
        TreeNode *lnode;
        TreeNode *rnode;

        TreeNode(){
            this->data = T();
            this->lnode = nullptr;
            this->rnode = nullptr;
        }
        TreeNode(T data,TreeNode *lnode,TreeNode *rnode){
            this->data = data;
            this->lnode = lnode;
            this->rnode = rnode;
        }
};

template <class T>
class BST {
    private:
        TreeNode<T> *root;
        int count = 0;
    public:
        BST();
        ~BST();
        void insert(T value);
        bool deleteNode(T value);
        TreeNode<T> *getRoot();  
        bool search(T value);
        void preOrder(TreeNode<T> *ptr);
        void inOrder(TreeNode<T> *ptr);
        void postOrder(TreeNode<T> *ptr);
        bool deleteNode(T elt,TreeNode<T> &node);
};

template <class T>
BST<T>::BST() {
    root = nullptr;
}

template <class T>
BST<T>::~BST() {
    root = nullptr;
}

template <class T>
TreeNode<T>* BST<T>::getRoot() {
    return root;
}
// Make the insert function recursive
template <class T>
void BST<T>::insert(T elt) {
    TreeNode<T> *node = new TreeNode<T>(elt,nullptr,nullptr);
    if (root == nullptr) {
        root = node;
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
void BST<T>::preOrder(TreeNode<T> *ptr){
    if (ptr == nullptr){
        cout<<"nullptr"<<" ";
        return;
    }

    cout<<ptr->data<<" ";
    preOrder(ptr->lnode);
    preOrder(ptr->rnode);
    if (ptr == root) cout << endl;
}

template <class T>
void BST<T>::inOrder(TreeNode<T> *ptr){
    if(ptr==nullptr){
        cout<<"nullptr"<<" ";
        return;
    }
    inOrder(ptr->lnode);
    cout<<ptr->data<<" ";
    inOrder(ptr->rnode);
    if(ptr == root) cout<<endl;
}

template <class T>
void BST<T>::postOrder(TreeNode<T> *ptr){
    if (ptr == nullptr) {
        cout << "nullptr"<<" ";
        return;
    }
    postOrder(ptr->lnode);
    postOrder(ptr->rnode);
    cout<<ptr->data<<" ";
    if(ptr == root) cout << endl;
}

int main() {
    BST<int> bst;
    bst.insert(50);
    bst.insert(200);
    bst.insert(30);
    bst.insert(70);
    bst.insert(60);

    TreeNode<int> *ptr = bst.getRoot();
    cout << "Pre-order: "<<endl;
    bst.preOrder(ptr); // Printing the elements of the tree using the preorder method Root -> Left -> Right
    cout << endl;

    cout << "In-order: "<<endl;   
    bst.inOrder(ptr); // Printing the elements of the tree using the inorder method Left -> Root -> Right
    cout << endl;

    cout << "Post-order: "<<endl;
    bst.postOrder(ptr); // Printing the elements of the tree using the post order method Left -> Right -> Root
    cout << endl;

    cout << bst.search(70) << endl;
    return 0;
}
