//
// Created by SAGIT on 22/06/2024.
//

#pragma once

#include <iostream>
#include "GameController.hpp"

namespace model
{
    class GameInit {
    public:
        static void start(model::GameController &game);
        static void initializePlayers(model::GameController &game);
        static void InitialPlacement(int i);
        static void FastInitialPlacement();
        static void addPlayer(const std::string &name, int id);
    };
}


