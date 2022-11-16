cmake_minimum_required(VERSION 3.23)
project(C867v2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(C867v2
        DegreeType.h
        student.cpp
        student.h
        roster.cpp
        roster.h
        main.cpp)

