#ifndef Node_hpp
#define Node_hpp

// Here we are implementing the code for creating nodes to be used in a linked list.

template <class T>
class Node {
    public:
        T data;
        Node* next;
};

template <class T>
Node<T>* createNode(T value) {
    Node<T>* newNode = new Node<T>();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

#endif


