cmake_minimum_required(VERSION 3.28)
project(Catan)

set(CMAKE_CXX_STANDARD 17)

add_executable(Catan main.cpp
        Model/Resource.hpp
        Model/Tile.cpp
        Model/Tile.hpp
        Model/Player.cpp
        Model/Player.hpp
        Model/Road.cpp
        Model/Road.hpp
        Model/Node.cpp
        Model/Node.hpp
        Model/Board.cpp
        Model/Board.hpp
)
