cmake_minimum_required(VERSION 3.10)

project(BigNumberCalculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(calculator
    src/main.cpp
    src/BigNumber.cpp
)