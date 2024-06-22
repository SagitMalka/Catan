//
// Created by SAGIT on 22/06/2024.
//
#pragma once


#include "../Model/Player.hpp"

namespace model {
    class TurnManagement {
        void startTurn();

        void endTurn();

        void rollDice();

        [[nodiscard]] const shared_ptr<Player> &getCurrentPlayer() const;
    };
}

