#ifndef HeapSort_hpp
#define HeapSort_hpp
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

//The above the method has a time complexity of 2*O(nlogn)
// Rather than this we can also do like this. The only possible problem willbe at the root of the array as each node will be root of another node.

/*
for(i = (N-1)/2;i>=0;i--)
fixDown(i); O(N)    because in the penultimate layer it fixdown to a maximum to 1 level the above layer nodes can fixdown to a maximum of two layer and so on.

Number of nodes at given height h in a complete binary heap of size N:
Number of nodes at height h = ceil(N / 2^(h+1))   
*/