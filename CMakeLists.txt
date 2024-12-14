cmake_minimum_required(VERSION 3.29)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(tic_tac_toe
    exp.cpp
    game.cpp
    main.cpp)
