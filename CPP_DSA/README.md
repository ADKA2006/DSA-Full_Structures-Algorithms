This repo contains the basic Data Structures.

Programming_Language - C++


The repository's structure is as follows

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


A header file **Data Structure Name**.hpp is present which implements the logic for the Data Structure.

Another header file named **Data Structure Name App**.hpp is present where the following is being done:
        • It imports the **Data Structure Name**.hpp and uses the data structure for building the required application making the backend logic separate from the frontend.
        • The application is having namespace named **Demo**
        • All the code in this file is written inside a class named **Data Structure Name App** and inside run method.
        
A ***main.cpp*** is present where the main function will import the header file **Data Structure Name App**.hpp and make call to Demo::**Data Structure Name**::run()


The purpose of this organize to prevent the main function to get cluttered with code for different data structures as the library grows.
