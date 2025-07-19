#ifndef Stack_hpp
#define Stack_hpp
#include <iostream>
#include "Node.hpp"

template <class T>
class Stack{
    private:
        Node<T>* top;
        int count;
    public:
        Stack();
        void push (T value);
        bool pop(T &value);     //It returns true if the pop was successful, false if the stack is empty.
        bool peek(T &value);    //We cannot use T because if in case the stack is empty we cannot return False cause it expect a T type value. So now if it is not empty we are storing the value in the value variable(reference).
        int size();
        bool isEmpty();
};

template <class T>
Stack<T>::Stack(){
    top = nullptr;
    count = 0;
}

template <class T>
void Stack<T>::push(T value){
    Node<T>* newNode = new Node<T>();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    count++;
}

template <class T>
bool Stack<T>::pop(T &value) {
    if (top != nullptr) {
        Node<T>* temp = top;
        value = top->data;
        top = top->next;
        delete temp;
        count--;
        return true;
    } else{
        return false;
    }
}

template <class T>
bool Stack<T>::peek(T &value){
    if (top != nullptr){
        value = top->data;
        return true;
    }else{
        return false;
    }
}

template <class T>
int Stack<T>::size(){
    return count;
}

template <class T>
bool Stack<T>::isEmpty(){
    return (count == 0)?true:false;
}


#endif