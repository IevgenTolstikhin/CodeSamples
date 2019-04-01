cmake_minimum_required(VERSION 3.5)
set (CMAKE_CXX_STANDARD 17)
include_directories (../includes)
add_executable (Bowling 
                        ../includes/Utils.h
                        ../includes/Lane.h
                        ../includes/Player.h
                        ../includes/Game.h
                        ../includes/Frame.h
                        Utils.cpp
                        Player.cpp
                        Lane.cpp
                        Game.cpp
                        Frame.cpp
                        Bowling.cpp)
