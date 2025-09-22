#ifndef BST_HPP
#define BST_HPP
#include "TreeNode.hpp"

/*
 *The tree is meant to be used as the underlying representation
 *for dictionary implementation. Each node therefore holds 
 *a (key,value) pair. * 
 */

template<class K, class V>
class BST{

private:
  TreeNode<K,V> *root;
  int count; 
  void insertrec(K key, V value, TreeNode<K,V> *&t);
  bool remove(K key, TreeNode<K,V> *&node);
  void PrintTree(TreeNode<K,V> *t);
  void DeleteTree(TreeNode<K,V> *t);
  
public:
  BST();
  ~BST();//destructor
  void insert(K key, V value);
  void insertrec(K key, V value);
  bool search(K key, V &value);
  bool deleteKey(K key);
  void PrintTree();
  TreeNode<K,V> *getRoot();
  int size();
  bool isEmpty();
  
};

template<class K, class V>
BST<K,V>::BST()
{
  root = nullptr;
  count = 0; // Initialise count
}

template<class K, class V>
void BST<K,V>::DeleteTree(TreeNode<K,V> *t)
{
  if (t != nullptr)
    {
      DeleteTree(t->left);
      DeleteTree(t->right);
      delete t;
    }
}

template<class K, class V>
BST<K,V>::~BST()
{
  DeleteTree(root);
}

template<class K, class V>
TreeNode<K,V>* BST<K,V>::getRoot() {
    return root;
}

// Normal insertion
template<class K, class V>
void BST<K,V>::insert(K key, V value)
{
  TreeNode<K,V> *node = new TreeNode<K,V>(key, value, nullptr, nullptr);
  if (root == nullptr) {
      root = node;
      count++;
  } else {
      TreeNode<K,V> *ptr = root;
      TreeNode<K,V> *parent = nullptr;
      while (ptr != nullptr){
          parent = ptr;
          if (key >= ptr->key){
              ptr = ptr->right;
          } else {
              ptr = ptr->left;
          }
      }
      if (key >= parent->key) {
          parent->right = node;
      } else {
          parent->left = node;
      }
      count++;
  }    
}

// Recurssive insertion
template<class K, class V>
void BST<K,V>::insertrec(K key, V value, TreeNode<K,V> *&t)
{
  if (t == nullptr) {
      t = new TreeNode<K,V>(key, value, nullptr, nullptr);
      count++;
  } else if (key < t->key) {
      insertrec(key, value, t->left);
  } else if (key >= t->key) {
      insertrec(key, value, t->right);
  }
}

template<class K, class V>
void BST<K,V>::insertrec(K key, V value)
{
  insertrec(key, value, root);
}


template<class K, class V>
bool BST<K,V>::search(K key, V &value)
{
  TreeNode<K,V> *ptr = root;
  while (ptr != nullptr){
      if (ptr->key == key) {
          value = ptr->value; // Store the value in reference parameter
          return true;
      } else if (key < ptr->key) {
          ptr = ptr->left;
      } else {
          ptr = ptr->right;
      }
  }
  return false;
}

template<class K, class V>
int BST<K,V>::size(){
    return count;
}

template<class K, class V>
bool BST<K,V>::isEmpty(){
    return (count == 0) ? true : false;
}

/*
template<class K, class V>
void BST<K,V>::PrintTree()
{
  PrintTree(root);
}

template<class K, class V>
void BST<K,V>::PrintTree(TreeNode<K,V> *t)
{
  if (t != nullptr) {
      PrintTree(t->left);
      std::cout << "(" << t->key << ", " << t->value << ") ";
      PrintTree(t->right);
  }
}
*/


template<class K, class V>
bool BST<K,V>::remove(K key, TreeNode<K,V> *&node)
{
  TreeNode<K,V> *ptr = root;
  TreeNode<K,V> *par = nullptr;

  // Search for the node to delete
  while (ptr != nullptr && ptr->key != key) {
      par = ptr;
      if (key < ptr->key) ptr = ptr->left;
      else ptr = ptr->right;
  }

  if (ptr == nullptr) return false; // Not found

  // Case 1: Node to be deleted is having no children (leaf)
  if (ptr->left == nullptr && ptr->right == nullptr) {
      if (par == nullptr) {
          // Deleting root node
          delete ptr;
          root = nullptr;
      } else {
          if (par->left == ptr) par->left = nullptr;
          else par->right = nullptr;
          delete ptr;
      }
  }
  // Case 2: Node to be deleted is having only left child
  else if (ptr->right == nullptr) {
      if (par == nullptr) {
          TreeNode<K,V>* temp = ptr;
          root = ptr->left;
          delete temp;
      } else {
          if (par->left == ptr) par->left = ptr->left;
          else par->right = ptr->left;
          delete ptr;
      }
  }
  // Case 3: Node to be deleted is having only right child
  else if (ptr->left == nullptr) {
      if (par == nullptr) {
          TreeNode<K,V>* temp = ptr;
          root = ptr->right;
          delete temp;
      } else {
          if (par->left == ptr) par->left = ptr->right;
          else par->right = ptr->right;
          delete ptr;
      }
  }
  // Case 4: Node to be deleted is having two children
  else {
      // Smallest value in the right subtree (inorder successor)
      TreeNode<K,V>* succPar = ptr;
      TreeNode<K,V>* succ = ptr->right;
      while (succ->left != nullptr) {
          succPar = succ;
          succ = succ->left;
      }
      ptr->key = succ->key;
      ptr->value = succ->value;
      if (succPar->left == succ) {
          succPar->left = succ->right;
      } else {
          succPar->right = succ->right;
      }
      delete succ;
  }
  count--;
  return true;
}


template<class K, class V>
bool BST<K,V>::deleteKey(K key)
{
  return remove(key, root);
}

#endif