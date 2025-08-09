#ifndef HeapSortBottomUpApp_hpp
#define HeapSortBottomUpApp_hpp
#include <iostream>
#include "HeapSortBottomUp.hpp"
using namespace std;

namespace Demo {
    class HeapSortBottomUpApp {
        public: 
            static void run() {
                cout << "\n=== Heap Sort ===\n" << endl;

                int n;
                cout << "Enter the number of elements: ";
                cin >> n;

                if (n <= 0) {
                    cout << "Invalid number of elements. Exiting." << endl;
                    return;
                }

                int *arr = new int[n];
                cout << "Enter " << n << " elements: ";
                for (int i = 0; i < n; i++){
                    cin >> arr[i];
                }

                HeapSortBottomUp<int> sorter;
                sorter.sort(arr, n);

                cout << "Sorted array: ";
                for(int i = 0; i < n; i++){
                    cout << arr[i] << " ";
                }
                cout << endl;

                delete[] arr;
                cout << "=== Heap Sort Complete ===" << endl;
            }
        
    };
}

#endif