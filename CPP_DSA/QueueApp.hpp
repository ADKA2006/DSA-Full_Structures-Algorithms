#ifndef QueueApp_hpp
#define QueueApp_hpp
#include "Queue.hpp"
#include <iostream>
using namespace std;

namespace Demo {
    class QueueApp {
    public:
        static void run() {
            cout << "\n=== Queue ===" << endl;

            Queue<int> q;
            
            cout << "Enqueuing values: 10, 20, 30" << endl;
            q.enqueue(10);
            q.enqueue(20);
            q.enqueue(30);
            
            int value;
            if (q.dequeue(value)){
                cout << "Dequeued value is: " << value << endl;
            } else {
                cout << "Queue is empty so cannot dequeue." << endl;
            }
            
            if (q.peek(value)){
                cout << "The element at the front of the queue is: " << value << endl;
            } else {
                cout << "Queue is empty so cannot peek." << endl;
            }
            
            cout << "Size of the queue is: " << q.size() << endl;
            
            if (q.isEmpty()){
                cout << "Queue is empty" << endl;
            } else {
                cout << "Queue is not empty" << endl;
            }
            
            cout << "=== Queue Complete ===" << endl;
        }
    };
}

#endif