This repo contains the basic Data Structures.

Programming_Language - C++


The repository's structure is as follows

'''
ADS_24203
    |---->main.cpp
            |---->Bag.hpp
                    |---->BagApp.hpp   (for demo purpose - for each data type as and when required)
            |---->Node.hpp
            |---->Stack.hpp
                    |---->StackApp.hpp (for demo purpose - for each data type as and when required)
        
            |---->FixedSizeStack.hpp 
                    |---->FixedSizeStackApp (for demo purpose - for each data type as and when required)
            |---->Queue.hpp
                    |---->QueueApp.hpp  (for demo purpose - for each data type as and when required)
'''

A header file **Data Structure Name**.hpp is present which implements the logic for the Data Structure.

Another header file named **Data Structure Name App**.hpp is present where the following is being done:
        • It imports the **Data Structure Name**.hpp and uses the data structure for building the required application making the backend logic separate from the frontend.
        • The application is having namespace named **Demo**
        • All the code in this file is written inside a class named **Data Structure Name App** and inside run method.
        
A ***main.cpp*** is present where the main function will import the header file **Data Structure Name App**.hpp and make call to Demo::**Data Structure Name**::run().


The purpose of this organize to prevent the main function to get cluttered with code for different data structures as the library grows.

The following is defined based on the array implementation
'''
In priority queue we follow a head like structure where the value of node i will be greater the value of the node at 2*i+1 and 2*i+2. Such structres are called heap (while implementing we will be doing this in an array rather than creating a tree like structure.) So as we traverse the nodes will be sorted manner. The parent of a given node (k) is ***(k-1)/2***. 

So in this case the worst case time will be only log(n) for insertion and for removing it will be O(1). In normal insertion using Array or linked list(without this head like behaviour) it will take O(n) for insetion and O(1) for removal (or virse versa depending on whether sorting is done during insertinon oor deletion) 

If the array has n elements then h = floor[log_2(n)].
'''

For basic pratice consider a situtation where the node value is the priority ie this has to maintained to maintain heap like structure then code for the same is given in c++ pratice for now (later the logic will be given as a provate function of the api we are going to implement)
