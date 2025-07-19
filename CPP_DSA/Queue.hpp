#ifndef Queue_hpp
#define Queue_hpp
#include <iostream>
#include "Node.hpp"

template <class T>
class Queue{
    private:
        Node<T>* front;
        Node<T>* back;
        int count;
    public:
        Queue();
        void enqueue(T value);
        bool dequeue(T &value);
        bool peek(T &value);
        int size();
        bool isEmpty();
};

template <class T>
Queue<T>::Queue(){
    front = nullptr;
    back = nullptr;
    count = 0;
}

template <class T>
void Queue<T>::enqueue(T value){
    Node<T>* newNode = createNode(value);
    if (front == nullptr && back == nullptr){
        front = newNode;
        back = newNode;
    }else{
        back->next = newNode;
        back = newNode;
    }
    count++;
}

template <class T>
bool Queue<T>::dequeue(T &value){
    if (front != nullptr){
        Node<T>* temp = front;
        value = front->data;
        front = front->next;
        if (front == nullptr) {
            back = nullptr; 
        }
        delete temp;
        count--;
        return true;
    } else {
        return false;
    }
}

template <class T>
bool Queue<T>::peek(T &value){
    if (front != nullptr){
        value = front->data;
        return true;
    } else {
        return false;
    }
}

template <class T>
int Queue<T>::size(){
    return count;
}

template <class T>
bool Queue<T>::isEmpty(){
    return (count == 0)?true:false;
}

#endif
