cmake_minimum_required(VERSION 3.10)
project(Tetris)
 
file(GLOB SOURCES 
    "*.h"
    "*.c"
)
 
add_executable(Tetris ${SOURCES})