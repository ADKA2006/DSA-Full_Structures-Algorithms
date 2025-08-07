cmake_minimum_required(VERSION 3.10)


project(ADSA_24203)   # Project name

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS
    Node.hpp
    Heapify.hpp
    Stack.hpp
    StackApp.hpp
    FixedSizeStack.hpp
    FixedSizeStackApp.hpp
    Queue.hpp
    QueueApp.hpp
    PriorityQueue.hpp
    PriorityQueueApp.hpp
    Bag.hpp
    BagApp.hpp
    HeapSort.hpp
    HeapSortApp.hpp
    HeapSortClass.hpp
    HeapSortClassApp.hpp
)

set(SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build
)
