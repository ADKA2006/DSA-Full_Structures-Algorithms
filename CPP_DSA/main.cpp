#include <iostream>
#include "BagApp.hpp"
#include "StackApp.hpp"
#include "FixedSizeStackApp.hpp"
#include "QueueApp.hpp"
#include "PriorityQueueApp.hpp"
#include "HeapSortBottomUpApp.hpp"
#include "HeapSortTopDownApp.hpp"

using namespace std;
using namespace Demo;  

int main() {
    cout << "=== xxxxxxxxxxxx Data Structure ADSA - 24203 xxxxxxxxxxxxxx ===" << endl;

    BagApp::run();            //Bag
    StackApp::run();          //Stack
    FixedSizeStackApp::run();   //Fixed Size Stack
    QueueApp::run();          //Queue
    PriorityQueueApp::run(); //Priority Queue
    HeapSortBottomUpApp::run(); //Heap Sort using Bottom Up Heapify
    HeapSortTopDownApp::run(); //Heap Sort using Top Down Heapify

    
    cout << "\n=== xxxxxxxxxxxxxxxxxxxxxx ===" << endl;
    
    return 0;
}