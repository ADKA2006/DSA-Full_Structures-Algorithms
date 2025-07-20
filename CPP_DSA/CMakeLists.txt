cmake_minimum_required(VERSION 3.10)

# Project name
project(ADSA_24203)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header files
set(HEADERS
    Node.hpp
    Stack.hpp
    StackApp.hpp
    LimitedStack.hpp
    LimitedStackApp.hpp
    Queue.hpp
    QueueApp.hpp
    Bag.hpp
    BagApp.hpp
)

# Source files (main.cpp is the only cpp file)
set(SOURCES
    main.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Include current directory for headers
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build
)
