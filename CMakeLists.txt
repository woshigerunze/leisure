cmake_minimum_required(VERSION 3.16)
project(practice)

set(CMAKE_CXX_STANDARD 20)
set(boost_header /usr/local/Cellar/boost/1.72.0_2/include/)
set(boost_lib /usr/local/Cellar/boost/1.72.0_2/lib/)
include_directories(${boost_header})
link_directories(${boost_lib})

add_executable(practice  main.cpp)
