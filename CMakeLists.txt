cmake_minimum_required(VERSION 3.28)
project(Catan)

set(CMAKE_CXX_STANDARD 17)

add_executable(Catan main.cpp
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
        Model/DevelopmentCard.cpp
        Model/DevelopmentCard.hpp
        Model/Constants.hpp
        Model/Card.hpp
        Model/CardDeck.hpp
        Model/DevelopmentCardDeck.cpp
        Model/DevelopmentCardDeck.hpp
        Controler/Game.cpp
        Controler/Game.hpp
        doctest.h
        tests.cpp
)
