cmake_minimum_required(VERSION 3.5)
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")
add_executable (thread_safe_priority_queue TagData.cpp TagData.h Model.cpp Model.h ThreadsafePriorityQueue.hpp main.cpp)
