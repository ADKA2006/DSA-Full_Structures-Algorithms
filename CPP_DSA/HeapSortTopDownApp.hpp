#ifndef HeapSortTopDownApp_hpp
#define HeapSortTopDownApp_hpp
#include "HeapSortTopDown.hpp"
#include "PriorityQueue.hpp"
using namespace std;

namespace Demo {
    class HeapSortTopDownApp {
        public:
        static void run() {
            cout << "\n=== Sort Array using Priority Queue ===" << endl;

            struct Patient{
                int value;
                string name;
                int priority;
            };

            Patient patient;

            cout << "Enter the maximum number of patients: ";
            int maxPatients;
            cin >> maxPatients;
            if (maxPatients <= 0) {
                cout << "Invalid maximum number of patients. Exiting." << endl;
                return;
            }

            PriorityQueue<Patient> pq(maxPatients);

            for (int i = 0; i < maxPatients; i++) {
                cout << "Enter the name of the Patient and Priority: " << endl;
                cin >> patient.name >> patient.priority;
                patient = {i + 1, patient.name, patient.priority};
                if (pq.insert(patient)) {
                    cout << "Patient " << patient.name << " with priority " << patient.priority << " added successfully." << endl;
                } else {
                    cout << "Failed to add patient. Priority Queue is full." << endl;
                }
            }
            SortArray<Patient> sorter;
            sorter.heapSort(pq);

            cout << "Sorted patients by priority:" << endl;
            for(int i = maxPatients; i>= 0; i--) {
                    cout << "Patient " << pq.getItem(i).name << " with priority " << pq.getItem(i).priority << endl;
            }

            cout << "=== Sort Array Complete ===" << endl;
        }
    };
}

#endif
