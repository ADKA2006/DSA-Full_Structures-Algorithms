## ADSA_24203 — Data Structures and Algorithms in C++  
![C++](https://img.shields.io/badge/C%2B%2B-11-blue) ![Build](https://img.shields.io/badge/build-g%2B%2B%20%7C%20CMake-green) ![Platform](https://img.shields.io/badge/platform-linux%20%7C%20macOS%20%7C%20windows-lightgrey)

Small, self-contained C++ implementations and demos of fundamental data structures and heap-based sorting. Each structure has a header with the implementation and a corresponding “App” header that demonstrates usage, keeping demo code separate from core logic.

## Programming_Language 
C++ [C++](https://img.shields.io/badge/C%2B%2B-11-blue)

### Explanation of the repo in detail

A header file **Data Structure Name**.hpp is present which implements the logic for the Data Structure.

Another header file named **Data Structure Name App**.hpp is present where the following is being done:
        • It imports the **Data Structure Name**.hpp and uses the data structure for building the required application making the backend logic separate from the frontend.
        • The application is having namespace named **Demo**
        • All the code in this file is written inside a class named **Data Structure Name App** and inside run method.
        
A ***main.cpp*** is present where the main function will import the header file **Data Structure Name App**.hpp and make call to Demo::**Data Structure Name**::run().


The purpose of this organisation is to prevent the main function to get cluttered with code for different data structures as the library grows.

### Implemented structures and demos
- Basic node helper (`Node.hpp`)
- Heapify utility (`Heapify.hpp`)
- Bag (`Bag.hpp`, `BagApp.hpp`)
- Stack (`Stack.hpp`, `StackApp.hpp`)
- Fixed-size stack with capacity checks (`FixedSizeStack.hpp`, `FixedSizeStackApp.hpp`)
- Queue (`Queue.hpp`, `QueueApp.hpp`)
- Priority queue (heap-backed) (`PriorityQueue.hpp`, `PriorityQueueApp.hpp`)
- Heap sort (Bottom-Up and Top-Down) (`HeapSortBottomUp.hpp`, `HeapSortBottomUpApp.hpp`, `HeapSortTopDown.hpp`, `HeapSortTopDownApp.hpp`)


The entry point `main.cpp` wires all demos together under the `Demo` namespace.

## Project layout

```
.
├── Bag.hpp
├── BagApp.hpp
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
├── main.cpp
├── build/        # CMake build artifacts (generated)
└── output/       # Convenience binaries from quick g++ builds
```

## Build and run

You can build with a single g++ command (quick start) or via CMake.

### Option 1: Quick build with g++

```bash
# Build and run the combined demo
g++ -std=c++11 -o output/main main.cpp && ./output/main
```

### Option 2: CMake build

```bash
cmake -S . -B build
cmake --build build

# Run from project root
./build/ADSA_24203 (if present)

# OR run from inside the build directory
cd build    
./ADSA_24203   (if present)
```

## Design notes

- Each data structure is implemented in a header: `<Structure>.hpp`.
- A matching demo lives in `<Structure>App.hpp`, under the `Demo` namespace, typically exposing a `run()` method.
- `main.cpp` imports the desired demo headers and calls their `run()` methods, keeping the main small and readable.

### Priority queue and heap recap
- The priority queue demo uses a binary max-heap stored in an array. For a node at index `i`, children are at `2*i + 1` and `2*i + 2`, and the parent is `(i - 1) / 2`.
- Typical complexities (max-heap): insert O(log n), peek O(1), remove-max O(log n).

### Binary tree and BST notes
- A binary tree node has up to two children; a BST maintains `left < parent < right`.
- BST search leverages the ordering to prune to one subtree at each step, similar to binary search.

## Requirements
- Linux, macOS, or Windows with a C++11-capable compiler
- Optional: CMake 3.10+

## Contributing
Small improvements, fixes, and new demos are welcome. If you add a new structure, follow the existing pattern: `<Structure>.hpp` for the implementation and `<Structure>App.hpp` with a `Demo::<Structure>App::run()` showcasing usage.

## License
Licensed under the MIT License. See [`LICENSE`](./LICENSE) for details.

## Acknowledgements
This repository is for learning and demonstration purposes; outputs are printed to the terminal for clarity, with minimal dependencies.


***Notes***
============

'''
Priority Queue Notes
In priority queue we follow a head like structure where the value of node i will be greater the value of the node at 2*i+1 and 2*i+2. Such structres are called heap (while implementing we will be doing this in an array rather than creating a tree like structure.) So as we traverse the nodes will be sorted manner. The parent of a given node (k) is ***(k-1)/2***. 

So in this case the worst case time will be only log(n) for insertion and for removing it will be O(1). In normal insertion using Array or linked list(without this head like behaviour) it will take O(n) for insetion and O(1) for removal (or virse versa depending on whether sorting is done during insertinon oor deletion) 

If the array has n elements then h = floor[log_2(n)].


For basic pratice consider a situtation where the node value is the priority ie this has to maintained to maintain heap like structure then code for the same is given in c++ pratice for now (later the logic will be given as a provate function of the api we are going to implement)
'''

'''
Binary Tree Node Notes
Binary Tree is either empty or has to have node with *two* child node must which (ie from the node it again point (two) to a binary which are distinct..)Check the cpp for the practice node is.


For binary search tree we make use of the binary tree. The left node should be less than the parent node and also the right node has to be greater than the parent. So while searching we are making use of the ideas of binary serch where if the givern value is less than that node we onloy have to search on the lest node and virsr versa.
'''


