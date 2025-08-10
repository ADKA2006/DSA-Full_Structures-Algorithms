#ifndef Heapify_hpp
#define Heapify_hpp

// Here we are implementing the Heapify process which is used to convert an unordered array into a heap.

template <class T>
class Heapify {
    private:
        void fixDown(T *items,int k,int n);
    public:
        void heapify(T *items, int n);
};

template <class T>
void Heapify<T>::fixDown(T *items,int k,int n){
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
void Heapify<T>::heapify(T *items,int n){
    for (int i = (n - 1) / 2; i >= 0; i--) {
        fixDown(items, i, n);
    }
}

#endif