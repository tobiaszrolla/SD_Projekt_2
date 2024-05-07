cmake_minimum_required(VERSION 3.10)

#nazwa projektu
project(PriorityQueue)
#szuka h i hpp w include
include_directories(include)
#dodaje plik wykonawczy z zalinkowaniem
add_executable(reserch src/reserch.cpp src/HeapPriorityQueue.cpp src/ListPriorityQueue.cpp)
add_executable(simulator src/simulator.cpp src/HeapPriorityQueue.cpp src/ListPriorityQueue.cpp)

