cmake_minimum_required(VERSION 3.21)
project("CPP_Primer")

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Debug)

add_executable(add.cc 1/add.cc)
add_executable(add_item 1/add_item.cc)

add_executable(arrRet 6/arrRet.cc)
add_executable(errMsg_initList 6/errMsg_initList.cc)