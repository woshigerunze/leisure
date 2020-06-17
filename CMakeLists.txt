cmake_minimum_required(VERSION 3.16)
project(practice)

set(CMAKE_CXX_STANDARD 20)

include_directories(/usr/local/Cellar/boost/1.72.0_2/include/)
link_directories(/usr/local/Cellar/boost/1.72.0_2/lib/)

add_executable(practice  main.cpp)

