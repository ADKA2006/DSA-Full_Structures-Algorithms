#ifndef StackApp_hpp
#define StackApp_hpp
#include "Stack.hpp"
#include <iostream>
using namespace std;   

namespace Demo {
    class StackApp {
    public:
        static void run() {
            cout << "\n=== Stack ===" << endl;
            
            Stack<int> s;
            
            cout << "Pushing values: 10, 20, 30" << endl;
            s.push(10);
            s.push(20);
            s.push(30);
            
            int value;
            if (s.pop(value)){
                cout << "Popped value is: " << value << endl;
            } else {
                cout << "Stack is empty so cannot pop." << endl;
            }
            
            if (s.peek(value)){
                cout << "The top of the stack (value) is: " << value << endl;
            } else {
                cout << "Stack is empty so cannot peek." << endl;
            }
            
            cout << "Size of the stack is: " << s.size() << endl;
            
            if (s.isEmpty()){
                cout << "Stack is empty" << endl;
            } else {
                cout << "Stack is not empty" << endl;
            }
            
            cout << "=== Stack Complete ===" << endl;
        }
    };
}

#endif

