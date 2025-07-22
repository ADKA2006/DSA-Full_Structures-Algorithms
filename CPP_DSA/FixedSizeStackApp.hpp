#ifndef FixedSizeStackApp_hpp
#define FixedSizeStackApp_hpp
#include "FixedSizeStack.hpp"
#include <iostream>
using namespace std;

namespace Demo {
    class FixedSizeStackApp {
    public:
        static void run() {
            cout << "\n=== Fixed Size Stack ===" << endl;

            FixedSizeStack<int> fs(3);

            cout << "Created stack with limit: " << fs.getLimit() << endl;
            cout << "Initial size: " << fs.size() << endl;

            for (int i = 1; i <= 3; i++) {
                fs.push(i * 10);
            }

            fs.push(40);
            fs.push(50);  
            
            int value;
            if (fs.pop(value)){
                cout << "Popped value is: " << value << endl;
            } else {
                cout << "Stack is empty so cannot pop." << endl;
            }
            
            if (fs.peek(value)){
                cout << "The top of the stack (value) is: " << value << endl;
            } else {
                cout << "Stack is empty so cannot peek." << endl;
            }
            
            cout << "Size of the stack is: " << fs.size() << endl;
            
            if (fs.isEmpty()){
                cout << "Stack is empty" << endl;
            } else {
                cout << "Stack is not empty" << endl;
            }
            
            cout << "Is empty? " << (fs.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
            cout << "Is full? " << (fs.isFull() ? "Stack is full" : "Stack is not full") << endl;

            cout << "=== Fixed Size Stack Complete ===" << endl;

        }
    };
}

#endif
