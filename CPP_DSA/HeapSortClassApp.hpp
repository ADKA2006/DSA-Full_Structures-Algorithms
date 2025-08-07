#ifndef HeapSortClassApp_hpp
#define HeapSortClassApp_hpp
#include <iostream>
#include "HeapSortClass.hpp"
using namespace std;

namespace Demo {
    class HeapSortClassApp {
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

                HeapSortClass<int> sorter;
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