#ifndef HeapSortTopDown_hpp
#define HeapSortTopDown_hpp
#include "PriorityQueue.hpp"
using namespace std;

// Here we are maintaining the heap property as and when we insert elements and remove elements
// Time complexity:
//     |-----> For building the heap: O(log n) for n elements it will be O(n log n)
//     |-----> For each extraction: O(log n), for n elements it will be O(n log n)
//   Overall: O(n log n)
// Space complexity: O(1)

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
        pq.getItem(0) = pq.getItem(i);   // We are getting the reference of the last element
        pq.getItem(i) = temp;
        pq.setCount(i);
        pq.callFixDown(0);   //This will go till the last element which is not sorted.
    }
    
    // Restore original count
    pq.setCount(originalCount);
}

#endif
