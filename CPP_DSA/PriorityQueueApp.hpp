#ifndef PriorityQueueApp_hpp
#define PriorityQueueApp_hpp
#include "PriorityQueue.hpp"
#include <iostream>
using namespace std;

namespace Demo {
    class PriorityQueueApp {
        public:
        static void run() {
            cout << "\n===Priority Queue===" << endl;

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
            cout << "Example of inserting into the priority queue" << endl;

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

            cout << "\nExample of removing from the priority queue:" << endl;
            Patient removedPatient;
            while (pq.remove(removedPatient)) {
                cout << "Removed patient: " << removedPatient.name << " with priority " << removedPatient.priority << endl;
            }
            cout << "No more patients to remove." << endl;

            cout << "===Priority Queue Complete===" << endl;

        }
    };
}

#endif