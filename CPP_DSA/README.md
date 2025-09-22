## ADSA_24203 — Data Structures and Algorithms in C++  
![C++](https://img.shields.io/badge/C%2B%2B-11-blue) ![Build](https://img.shields.io/badge/build-g%2B%2B%20%7C%20CMake-green) ![Platform](https://img.shields.io/badge/platform-linux%20%7C%20macOS%20%7C%20windows-lightgrey)

Small, self-contained C++ implementations and demos of fundamental data structures and heap-based sorting. Each structure has a header with the implementation and a corresponding “App” header that demonstrates usage, keeping demo code separate from core logic.

## Programming_Language 
1) [C++](https://img.shields.io/badge/C%2B%2B-11-blue)

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
- Tree node helper (`TreeNode.hpp`)
- Heapify utility (`Heapify.hpp`)
- Bag (`Bag.hpp`, `BagApp.hpp`)
- Stack (`Stack.hpp`, `StackApp.hpp`)
- Fixed-size stack with capacity checks (`FixedSizeStack.hpp`, `FixedSizeStackApp.hpp`)
- Queue (`Queue.hpp`, `QueueApp.hpp`)
- Priority queue (heap-backed) (`PriorityQueue.hpp`, `PriorityQueueApp.hpp`)
- Binary Search Tree (`BST.hpp`, `BSTApp.hpp`)
- Heap sort (Bottom-Up and Top-Down) (`HeapSortBottomUp.hpp`, `HeapSortBottomUpApp.hpp`, `HeapSortTopDown.hpp`, `HeapSortTopDownApp.hpp`)


The entry point `main.cpp` wires all demos together under the `Demo` namespace.

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
- The BST implementation uses `TreeNode.hpp` for the underlying node structure.
- Common BST operations include:
  - **Insert**: O(log n) average, O(n) worst case (unbalanced tree)
  - **Search**: O(log n) average, O(n) worst case
  - **Delete**: O(log n) average, with three cases:
    1. Leaf node: simply remove the node
    2. Node with one child: replace node with its child
    3. Node with two children: replace with inorder successor/predecessor
- The BST demo (`BSTApp.hpp`) demonstrates insertion, search, traversal, and deletion operations.

## Requirements
- Linux, macOS, or Windows with a C++11-capable compiler
- Optional: CMake 3.10+

## License
Licensed under the MIT License. See the [LICENSE](../LICENSE) at the repository root for details.

## Acknowledgements
This repository is for learning and demonstration purposes; outputs are printed to the terminal for clarity, with minimal dependencies.


***Notes***
============
'''
General Notes
& is the reference operator(memory address) and * is the dereference operator(gives the value).
There is Call by value(T ele) and also Call by Reference(T &value)

Use T* when "no object" is a valid state and for tree children. In this we make use of ->.
Use T& when you require a valid object and want simpler syntax (no ->), but remember references can't be null or reseated.
Use T*& when the function needs to change which node the caller's pointer points to (e.g., deletion that must set root = nullptr).
For ownership safety in larger code, consider smart pointers

or 
Call-by-value (T x): function gets a copy of the whole object. Mutating the parameter doesn't affect the caller's object.
Call-by-pointer (T* p): function gets a copy of the pointer (an address). You can do p->field = ... to change the original object. Doing p = nullptr; only changes the local copy of the pointer.
Call-by-reference (T& r): function gets an alias to the object. Mutations affect the caller directly. References cannot be null and cannot be reseated.
Reference-to-pointer (T*& rp): function gets an alias to the caller's pointer variable. You can both mutate the pointee and reseat the caller's pointer (e.g., set it to nullptr).
ppointer by reference also check.

//We can also use *& (This will be reference to the pointer rather than a copy of the original pointer which happens in *ptr)
'''

'''
Priority Queue Notes
In priority queue we follow a head like structure where the value of node i will be greater the value of the node at 2*i+1 and 2*i+2. Such structres are called heap (while implementing we will be doing this in an array rather than creating a tree like structure.) So as we traverse the nodes will be sorted manner. The parent of a given node (k) is ***(k-1)/2***. 

So in this case the worst case time will be only log(n) for insertion and for removing it will be O(1). In normal insertion using Array or linked list(without this head like behaviour) it will take O(n) for insetion and O(1) for removal (or virse versa depending on whether sorting is done during insertinon oor deletion) 

If the array has n elements then h = floor[log_2(n)].


For basic pratice consider a situtation where the node value is the priority ie this has to maintained to maintain heap like structure then code for the same is given in c++ pratice for now (later the logic will be given as a private function of the api we are going to implement)
'''

'''
Binary Tree Node Notes
Binary Tree is either empty or has to have node with *two* child node must which (ie from the node it again point (two) to a binary which are distinct..)Check the cpp for the practice node is.


For binary search tree we make use of the binary tree. The left node should be less than the parent node and also the right node has to be greater than the parent. So while searching we are making use of the ideas of binary serch where if the givern value is less than that node we onloy have to search on the lest node and virse versa.

Update the readme to include the binary search code details(readme of both)
'''


'''
Binary Search Tree
deleteNode procedure

1) When the node to be deleted is a leaf node -  so here we have to make the parent next(right or left) to the null ptr.
2) If the node to be deleted has one child -  make the child has the parent.
3) If the node to be delete has two childs do the following:
   a) Find the inorder successor (smallest value in the right subtree) OR inorder predecessor (largest value in the left subtree)
   b) Replace the node's value with the successor's/predecessor's value
   c) Delete the successor/predecessor node (which will have at most one child, making it case 1 or 2)
   
   Algorithm for inorder successor approach:
   - Go to the right child of the node to be deleted
   - Keep going left until you find a node with no left child
   - This node is the inorder successor
   - Copy its value to the node to be deleted
   - Delete the successor node using case 1 or 2

Catalinic formula is (2n)!/(n! * (n + 1)!)
'''


''' 
Graphs
It is represented as G = (V,E)
V = Set of nodes/vertices ===> V = {P1,P2,P3,P4...}
E = Set of pair of nodes/vertices ie edges ===> {{P1,P4},{P2,P3}}

In undirected graphs 
  - Pair wise relation is symmetric
  - E : Collection of sets of pairs of vertices

In Directed graphs
  - Pairwise relation may/may not be symmetric
  - E: Collection of ordered pairs of vertices

Adjacency
--------

Two nodes are said to be adjacent to eachother if there is a edge connecting the twoo nodes.
ie Two nodes U and V are said to be adjacent to eachother if an edge connecting between them is present.

Neighbours of a node is the set of its adjacent nodes

Path
-----
It is a sequence of nodes V1,V2,V3.....Vk-1,Vk where {V,Vi+1} \belongs to E \forall i = 1,2.....k-1

Simple Path
-----------
Path in whuich all the nodes are distinct.

Cyclic Path
-----------
The simple path (except the first and last nodes) form a cyclic/ring like structure.  ie V1....Vk-1 are distanct & V1 = Vk

Length of tthe path
--------------------
The number of nodes in the path is the length.


Assumption in our case
----------------------
 - Here we considering uni edge graph ie only one edge between given two nodes / pairs. There are also multi edge graphs.
   In simple terms there is atmost one  edge between a given pair of nodes
 - There are no self loops in the graphs.


Reprsentation of the graph
--------------------------
-> Adjacency matrix
--------------------
 |V| x |V| ie the size of the matrix is V x V. It is also binary. 
[ 1 2 3 4
1 0 1 1 1
2 1 0 0 0
3 1 0 0 0
4 1 0 0 0]

This is the representation for a grpah in which 1 is connected to 2 3 4 and nodes 2 3 4 are not connected to any other nodes ony 1.
Space complexity is |V|**2

For finding the neighbours of a given vertex the time complexity will be theta(V) ie since we need the entire row to find the adjacent nodes where the row size will be V.

Making use of adjacency matrix is not suitable since as the number of nodes increase the time complexity also increases proportionaly.

-> Adjacency List
-----------------
Here each node has a list associated with it to store its neighbours.
Here space complexity of O(|V| + |E|)
This is better than adjacency matrix becaue |E| < |V|**2 (max is V*(v-1)/2 in adj.list which is smaller than (|V|**2)/2)

For finding the neighbours of a given vertex the time complexity will be theta(#number of neighbours(degree of the node)) ie since we need the entire row to find the adjacent nodes where the row size will be V.

Graph Traversal
---------------

A connected graph is a graph in which there is a path from any a given node to any other node in the graph.

Connected component of a graph is the a subgraph which is connected.

1) Given a graph G = (V,E), how many connected componet are there in the graph.
2) Path with the least cost.
3) Given a pair of nodes, what is the distance between the nodes(ie the length of the sortest path.) # Here if the nodes are in different sub graphs then it will be infinity (ie no path exist)

In BFS the runtime is equal to the number of edges(see)
O(|V| + |E|)

L is the visited set.
Find the distancec of a node from teh S ===> Find which L[i] is that and i will be the answer.