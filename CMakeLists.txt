cmake_minimum_required(VERSION 3.2)
project(Binary_Tree VERSION 1.0.0)

file(GLOB files
        "main.cpp"
        "libraries/*.h"
        "libraries/*.cpp"
        )


add_executable(Binary_Tree ${files})