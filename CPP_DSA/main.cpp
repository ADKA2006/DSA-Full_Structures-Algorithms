#include <iostream>
#include "StackApp.hpp"
#include "FixedSizeStackApp.hpp"
#include "QueueApp.hpp"
#include "BagApp.hpp"
using namespace std;
using namespace Demo;  

int main() {
    cout << "=== xxxxxxxxxxxx Data Structure ADSA - 24203 xxxxxxxxxxxxxx ===" << endl;

    BagApp::run();            //Bag
    StackApp::run();          //Stack
    FixedSizeStackApp::run();   //Fixed Size Stack
    QueueApp::run();          //Queue


    
    cout << "\n=== xxxxxxxxxxxxxxxxxxxxxx ===" << endl;
    
    return 0;
}