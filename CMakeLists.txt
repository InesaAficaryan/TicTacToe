cmake_minimum_required(VERSION 3.5)

project(tictactoe)

add_executable(tictactoe main.cpp tictactoe.cpp node.cpp)

target_include_directories(tictactoe PRIVATE "./include")

