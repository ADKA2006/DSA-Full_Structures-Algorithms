#ifndef FixedSizeStack_hpp
#define FixedSizeStack_hpp
#include <iostream>
#include "Node.hpp"
using namespace std;

template <class T>
class FixedSizeStack{
    private:
        Node<T>* top;
        int count;
        int limit; // Stack limit to prevent overflow
    public:
        FixedSizeStack(int maxSize);
        void push(T value);
        bool pop(T &value);     
        bool peek(T &value);    
        int size();
        bool isEmpty();
        bool isFull();          
        int getLimit();        
};

template <class T>
FixedSizeStack<T>::FixedSizeStack(int maxSize) {
    top = nullptr;
    count = 0;
    limit = maxSize;
}

template <class T>
void FixedSizeStack<T>::push(T value){
    if (count < limit) {
        Node<T>* newNode = createNode(value);
        newNode->next = top;
        top = newNode;
        count++;
    } else {
        cerr << "Stack overflow occurred: Cannot push " << value << endl;
    }
}

template <class T>
bool FixedSizeStack<T>::pop(T &value) {
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
bool FixedSizeStack<T>::peek(T &value){
    if (top != nullptr){
        value = top->data;
        return true;
    }else{
        return false;
    }
}

template <class T>
int FixedSizeStack<T>::size(){
    return count;
}

template <class T>
bool FixedSizeStack<T>::isEmpty(){
    return (count == 0)?true:false;
}

template <class T>
bool FixedSizeStack<T>::isFull(){
    return (count == limit)?true:false;
}

template <class T>
int FixedSizeStack<T>::getLimit(){
    return limit;
}

#endif