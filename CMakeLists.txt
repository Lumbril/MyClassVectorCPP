cmake_minimum_required(VERSION 3.17)
project(MyClassVectorCPP)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp vector.h)

add_executable(MyClassVectorCPP ${SOURCE_FILES})