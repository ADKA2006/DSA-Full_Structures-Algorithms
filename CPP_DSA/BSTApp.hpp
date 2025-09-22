#ifndef BSTAPP_HPP
#define BSTAPP_HPP
#include "BST.hpp"
#include <iostream>

namespace Demo
{
    class BSTApp {
    private:
        template <class K, class V>
        static void printPreOrder(TreeNode<K,V> *ptr) {
            if (ptr == nullptr) {
                return;
            }
            std::cout << "(" << ptr->key << "," << ptr->value << ") ";
            printPreOrder(ptr->left);
            printPreOrder(ptr->right);
        }
        
        template <class K, class V>
        static void printInOrder(TreeNode<K,V> *ptr) {
            if (ptr == nullptr) {
                return;
            }
            printInOrder(ptr->left);
            std::cout << "(" << ptr->key << "," << ptr->value << ") ";
            printInOrder(ptr->right);
        }
        
        template <class K, class V>
        static void printPostOrder(TreeNode<K,V> *ptr) {
            if (ptr == nullptr) {
                return;
            }
            printPostOrder(ptr->left);
            printPostOrder(ptr->right);
            std::cout << "(" << ptr->key << "," << ptr->value << ") ";
        }
        
    public:
        static void run() {
            std::cout << "\n=== Binary Search Tree BSTApp ===" << std::endl;
            
            BST<int,std::string> bst;
            // inserting numbers as key and the correspoding english words as values for demo.
            std::cout << "Inserting key-value pairs: (50,'Fifty'), (200,'TwoHundred'), (30,'Thirty'), (70,'Seventy'), (60,'Sixty')" << std::endl;
            bst.insert(50, "Fifty");
            bst.insert(200, "TwoHundred");
            bst.insert(30, "Thirty");
            bst.insert(70, "Seventy");
            bst.insert(60, "Sixty");
            
            TreeNode<int,std::string> *ptr = bst.getRoot();
            
            std::cout << "Pre-order traversal:" << std::endl;
            printPreOrder(ptr); // Root -> Left -> Right
            std::cout << std::endl;
            
            std::cout << "In-order traversal:" << std::endl;   
            printInOrder(ptr); // Left -> Root -> Right
            std::cout << std::endl;
            
            std::cout << "Post-order traversal:" << std::endl;
            printPostOrder(ptr); // Left -> Right -> Root
            std::cout << std::endl;
            
            std::string value;
            std::cout << "Searching for key 70: " << (bst.search(70, value) ? "Found - " + value : "Not Found") << std::endl;
            std::cout << "Searching for key 100: " << (bst.search(100, value) ? "Found - " + value : "Not Found") << std::endl;
            
            std::cout << "Size of BST: " << bst.size() << std::endl;
            std::cout << "Is BST empty? " << (bst.isEmpty() ? "Yes" : "No") << std::endl;
            
            std::cout << "Deleting key 30" << std::endl;
            if (bst.deleteKey(30)) {
                std::cout << "Successfully deleted key 30" << std::endl;
            } else {
                std::cout << "Could not delete key 30 (not found)" << std::endl;
            }
            
            std::cout << "In-order traversal after deletion:" << std::endl;
            printInOrder(ptr);
            std::cout << std::endl;
            
            std::cout << "Size of BST after deletion: " << bst.size() << std::endl;
            
            std::cout << "=== Binary Search Tree Complete ===" << std::endl;
        }
    };
}

#endif
