## ADSA_24203 — Data Structures and Algorithms - 2

Name: Advaith Krishna
Roll No: CB.SC.U4AIE24203
Subject: Data Structures and Algorithm 2 - 22AIE203


## Programming_Language 
1) C++

### Explanation of the repo in detail

A header file **Data Structure Name**.hpp is present which implements the logic for the Data Structure.

Another header file named **Data Structure Name App**.hpp is present where the following is being done:
        • It imports the **Data Structure Name**.hpp and uses the data structure for building the required application making the backend logic separate from the frontend.
        • The application is having namespace named **Demo**
        • All the code in this file is written inside a class named **Data Structure Name App** and inside run method.
        
A ***main.cpp*** is present where the main function will import the header file **Data Structure Name App**.hpp and make call to Demo::**Data Structure Name**::run().


The purpose of this organisation is to prevent the main function to get cluttered with code for different data structures as the library grows.

## Project layout

```
.
├── Bag.hpp
├── BagApp.hpp
├── BinarySearchTreewithTreeNode.cpp
├── BST.hpp
├── BSTApp.hpp
├── CMakeLists.txt
├── FixedSizeStack.hpp
├── FixedSizeStackApp.hpp
├── Heapify.hpp
├── HeapSortBottomUp.hpp
├── HeapSortBottomUpApp.hpp
├── HeapSortTopDown.hpp
├── HeapSortTopDownApp.hpp
├── Node.hpp
├── PriorityQueue.hpp
├── PriorityQueueApp.hpp
├── Queue.hpp
├── QueueApp.hpp
├── Stack.hpp
├── StackApp.hpp
├── TreeNode.hpp
├── main.cpp
├── build/       
└── output/      
```