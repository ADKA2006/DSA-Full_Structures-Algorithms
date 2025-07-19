#ifndef Bag_H
#define Bag_H
#include <iostream>
#define N 1000   //Whenever we type N it will be 1000
template <class T>
class Bag{
    private:
        T elts[N];      // Maximum number of elements possible
        int n;          // Number of elements actully present in the class
    public:
        Bag();
        void addItem(T elt);
        bool isEmpty();
        int size();
};

template <class T>
Bag<T>::Bag(){
    n = 0;
}

template <class T>
void Bag<T>::addItem(T elt){
    elts[n] = elt;
    n++;
}

template <class T>
bool Bag<T>::isEmpty(){
    return (n==0)?true:false;
}

template <class T>
int Bag<T>::size(){
    return n;
}

#endif