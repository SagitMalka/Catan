//
// Created by SAGIT on 22/06/2024.
//

#pragma once

#include "../Model/Player.hpp"
#include <iostream>

namespace model
{
    class GameController {


        [[nodiscard]] const vector<shared_ptr<Player>> &getPlayers() const;

    };

}

