cmake_minimum_required(VERSION 3.23)
project(basics)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        basics
        #gate_examples.cpp Perceptron.cpp
        main.cpp MLP.cpp Perceptron.cpp
        MLP.hpp)
