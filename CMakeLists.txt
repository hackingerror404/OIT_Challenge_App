cmake_minimum_required(VERSION 3.24)
project(OIT_Challenge)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(OIT_Challenge main.cpp TicTacToeBoard.cpp TicTacToeBoard.h TicTacDisplay.cpp TicTacDisplay.h)


