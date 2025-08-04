#ifndef SortArray_hpp
#define SortArray_hpp
#include "PriorityQueue.hpp"
using namespace std;


template <class T>
class SortArray {
    public:
        void heapSort(PriorityQueue<T>& pq);
};

template <class T>
void SortArray<T>::heapSort(PriorityQueue<T>& pq) {
    int originalCount = pq.getCount();
    for(int i = originalCount - 1; i >= 0; i--) {
        T temp = pq.getItem(0);
        pq.getItem(0) = pq.getItem(i);
        pq.getItem(i) = temp;
        pq.setCount(i);
        pq.callFixDown(0);   //This will go till the last element which is not sorted.
    }
    
    // Restore original count
    pq.setCount(originalCount);
}

#endif