#ifndef HeapSortClass_hpp
#define HeapSortClass_hpp
#include <iostream>
#include "Heapify.hpp"
using namespace std;

// Here we are taking a bottom-up approach where we take an unordered array and transform it into a heap.
// Time complexity:
//     |-----> For building the heap: O(n)
//     |-----> For each extraction: O(log n), for n elements it will be O(n log n)
//  Overall: O(n log n)
// Space complexity: O(1)

template <class T>
class HeapSortBottomUp {
    private:
        void fixDown(T *items,int k,int n);
        void do_heapify(T *items,int n);
    public:
        HeapSortBottomUp() = default;
        void sort(T *items,int n);
};

template <class T>
void HeapSortBottomUp<T>::fixDown(T *items,int k,int n){
    int ptr = k;
    int ptr1, ptr2;
    while (2*k + 1 < n){  
        ptr1 = (2*k + 1);     
        ptr2 = (2*k + 2);     
        
        if (ptr2 < n && items[ptr2] > items[ptr1]){
            ptr = ptr2;
        } else {
            ptr = ptr1;
        }
        
        if (items[k] < items[ptr]){
            T temp = items[ptr];
            items[ptr] = items[k];
            items[k] = temp;
            k = ptr;
        } else {
            break;
        }
    }
}

template <class T>
void HeapSortBottomUp<T>::do_heapify(T *items,int n){
    Heapify<T> heapify;
    heapify.heapify(items,n);
}

template <class T>
void HeapSortBottomUp<T>::sort(T *items,int n){
    do_heapify(items,n);
    for (int i = n - 1; i > 0; i--) {
        T temp = items[i];
        items[i] = items[0];
        items[0] = temp;
        fixDown(items, 0, i);
    }
}
#endif


//Take the heapify thing from the heapify_hpp and now pending is the sort where we need to swap the first element witih the last  and do the fixdown till after reduing the count(just like we did earlier only differce here we doing heapifying after giveing an unsorted array rather than doing at the time of insertion)