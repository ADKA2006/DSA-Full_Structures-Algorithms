#include <iostream>
#include "StackApp.hpp"
#include "QueueApp.hpp"
#include "BagApp.hpp"
using namespace std;

int main() {
    cout << "=== xxxxxxxxxxxx Data Structure ADSA - 24203 xxxxxxxxxxxxxx ===" << endl;

    Demo::BagApp::run();            //Bag
    Demo::StackApp::run();          //Stack
    Demo::QueueApp::run();          //Queue


    
    cout << "\n=== xxxxxxxxxxxxxxxxxxxxxx ===" << endl;
    
    return 0;
}