cmake_minimum_required(VERSION 3.27)
project(check)

set(CMAKE_CXX_STANDARD 20)

add_executable(check main.cpp
        labyrinth.cpp
        labyrinth.h
        cell.cpp
        cell.h
        game.cpp
        game.h)
