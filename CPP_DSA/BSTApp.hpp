#ifndef BSTApp_hpp
#define BSTApp_hpp
#include "BST.hpp"
#include <iostream>
using namespace std;

namespace Demo {
    class BSTApp {
    private:
        template <class T>
        static void printPreOrder(TreeNode<T> *ptr) {
            if (ptr == nullptr) {
                cout << "nullptr ";
                return;
            }
            cout << ptr->data << " ";
            printPreOrder(ptr->lnode);
            printPreOrder(ptr->rnode);
        }
        
        template <class T>
        static void printInOrder(TreeNode<T> *ptr) {
            if (ptr == nullptr) {
                cout << "nullptr ";
                return;
            }
            printInOrder(ptr->lnode);
            cout << ptr->data << " ";
            printInOrder(ptr->rnode);
        }
        
        template <class T>
        static void printPostOrder(TreeNode<T> *ptr) {
            if (ptr == nullptr) {
                cout << "nullptr ";
                return;
            }
            printPostOrder(ptr->lnode);
            printPostOrder(ptr->rnode);
            cout << ptr->data << " ";
        }
        
    public:
        static void run() {
            cout << "\n=== Binary Search Tree ===" << endl;
            
            BST<int> bst;
            
            cout << "Inserting values: 50, 200, 30, 70, 60" << endl;
            bst.insert(50);
            bst.insert(200);
            bst.insert(30);
            bst.insert(70);
            bst.insert(60);
            
            TreeNode<int> *ptr = bst.getRoot();
            
            cout << "Pre-order traversal:" << endl;
            printPreOrder(ptr); // Root -> Left -> Right
            cout << endl;
            
            cout << "In-order traversal:" << endl;   
            printInOrder(ptr); // Left -> Root -> Right
            cout << endl;
            
            cout << "Post-order traversal:" << endl;
            printPostOrder(ptr); // Left -> Right -> Root
            cout << endl;
            
            cout << "Searching for value 70: " << (bst.search(70) ? "Found" : "Not Found") << endl;
            cout << "Searching for value 100: " << (bst.search(100) ? "Found" : "Not Found") << endl;
            
            cout << "Size of BST: " << bst.size() << endl;
            cout << "Is BST empty? " << (bst.isEmpty() ? "Yes" : "No") << endl;
            
            cout << "Deleting value 30" << endl;
            if (bst.deleteNode(30)) {
                cout << "Successfully deleted 30" << endl;
            } else {
                cout << "Could not delete 30 (not found)" << endl;
            }
            
            cout << "In-order traversal after deletion:" << endl;
            printInOrder(ptr);
            cout << endl;
            
            cout << "Size of BST after deletion: " << bst.size() << endl;
            
            cout << "=== Binary Search Tree Complete ===" << endl;
        }
    };
}

#endif
