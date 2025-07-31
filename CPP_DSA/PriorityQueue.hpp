#ifndef PriorityQueue_hpp
#define PriorityQueue_hpp
#include <iostream>
using namespace std;


//Create a struct data structure with the priority value in the app.WJich is the element
template <class T>
class PriorityQueue{
    private:
        int count;      //Number of elements
        int capacity;   //Maximum number of elements
        T *items;   // The elements which is stored as an array
        void fixUp(int k);
        void fixDown(int k);
    public:
        PriorityQueue(int max);
        ~PriorityQueue();
        bool insert(T ele);
        bool remove(T &ele);
        //Swap the first element with the last element and then do fixDown on the root node(first element). And return the last element before calling the fixDown.
};

template <class T>
PriorityQueue<T>::PriorityQueue(int max) {
    count = 0;
    capacity = max;
    items = new T[max];
}

template <class T>
PriorityQueue<T>::~PriorityQueue() {
    delete[] items;
}

template <class T>
void PriorityQueue<T>::fixUp(int k){       // items  is an array which was a heap before the value at k index is inerted.
    int ptr = (k-1)/2;
    while (k > 0){
        if (items[ptr].priority < items[k].priority){
            T temp = items[ptr];
            items[ptr] = items[k];
            items[k] = temp;
            k = ptr;
            ptr = (k-1)/2;
        } else {
            break;
        }
    }
}

template <class T>
void PriorityQueue<T>::fixDown(int p){
    int ptr = p;
    int ptr1, ptr2;
    while (2*p + 1 < count){  
        ptr1 = (2*p + 1);     
        ptr2 = (2*p + 2);     
        
        if (ptr2 < count && items[ptr2].priority > items[ptr1].priority){
            ptr = ptr2;
        } else {
            ptr = ptr1;
        }
        
        if (items[p].priority < items[ptr].priority){
            T temp = items[ptr];
            items[ptr] = items[p];
            items[p] = temp;
            p = ptr;
        } else {
            break;
        }
    }
}

template <class T>
bool PriorityQueue<T>::insert(T ele) {
    if (count == capacity) return false;
    items[count] = ele;
    fixUp(count);
    count++;
    return true;
}

template <class T>
bool PriorityQueue<T>::remove(T &ele) {
    if (count == 0) return false;
    ele = items[0];
    items[0] = items[count - 1];
    count --;
    fixDown(0);
    return true;
}

#endif