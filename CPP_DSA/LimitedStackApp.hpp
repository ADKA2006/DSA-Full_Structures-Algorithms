#ifndef LimitedStackApp_hpp
#define LimitedStackApp_hpp
#include "LimitedStack.hpp"
#include <iostream>
using namespace std;

namespace Demo {
    class LimitedStackApp {
    public:
        static void run() {
            cout << "\n=== Limited Stack ===" << endl;

            LimitedStack<int> ls(3);
            
            cout << "Created stack with limit: " << ls.getLimit() << endl;
            cout << "Initial size: " << ls.size() << endl;
            
            for (int i = 1; i <= 3; i++) {
                ls.push(i * 10);
            }

            ls.push(40);  
            ls.push(50);  
            
            int value;
            if (ls.pop(value)){
                cout << "Popped value is: " << value << endl;
            } else {
                cout << "Stack is empty so cannot pop." << endl;
            }
            
            if (ls.peek(value)){
                cout << "The top of the stack (value) is: " << value << endl;
            } else {
                cout << "Stack is empty so cannot peek." << endl;
            }
            
            cout << "Size of the stack is: " << ls.size() << endl;
            
            if (ls.isEmpty()){
                cout << "Stack is empty" << endl;
            } else {
                cout << "Stack is not empty" << endl;
            }
            
            cout << "Is empty? " << (ls.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
            cout << "Is full? " << (ls.isFull() ? "Stack is full" : "Stack is not full") << endl;

            cout << "=== Limited Stack Complete ===" << endl;

        }
    };
}

#endif
