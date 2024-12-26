cmake_minimum_required(VERSION 3.10)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
add_library(tic-tac-toe_lib game.cpp exception.cpp)
target_include_directories(tic-tac-toe_lib PUBLIC ${CMAKE_SOURCE_DIR})

add_executable(tic_tac_toe main.cpp)
add_executable(tests test.cpp)

target_link_libraries(tic_tac_toe PRIVATE tic-tac-toe_lib)
target_link_libraries(tests PRIVATE tic-tac-toe_lib)