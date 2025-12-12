cmake_minimum_required(VERSION 3.31)
project(Task1Project)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Task3 Lab2/Task2.cpp
        Methods/diff.h
        Methods/General.h
        Methods/Dihotomia.h
        Methods/Iteration.h
        Methods/Newton.h
        Methods/Complex.h


)

target_include_directories(Task3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Methods)

