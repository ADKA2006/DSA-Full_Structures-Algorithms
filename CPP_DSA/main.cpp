#include <iostream>
#include "StackApp.hpp"
#include "LimitedStackApp.hpp"
#include "QueueApp.hpp"
#include "BagApp.hpp"
using namespace std;
using namespace Demo;  

int main() {
    cout << "=== xxxxxxxxxxxx Data Structure ADSA - 24203 xxxxxxxxxxxxxx ===" << endl;

    BagApp::run();            //Bag
    StackApp::run();          //Stack
    LimitedStackApp::run();   //Limited Stack
    QueueApp::run();          //Queue


    
    cout << "\n=== xxxxxxxxxxxxxxxxxxxxxx ===" << endl;
    
    return 0;
}