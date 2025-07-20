#ifndef BagApp_hpp
#define BagApp_hpp
#include "Bag.hpp"
#include <iostream>
using namespace std;

namespace Demo {
    class BagApp {
    public:
        static void run() {
            cout << "\n=== Bag ===" << endl;

            Bag<int> bag;

            cout << "Adding items: 10, 20, 30, 40, 50" << endl;
            bag.addItem(10);
            bag.addItem(20);
            bag.addItem(30);
            bag.addItem(40);
            bag.addItem(50);
            
            cout << "Size of the bag: " << bag.size() << endl;
            
            if (bag.isEmpty()) {
                cout << "Bag is empty" << endl;
            } else {
                cout << "Bag is not empty" << endl;
            }
            cout << "=== Bag Complete ===" << endl;
        }
    };
}

#endif
