//
// Created by SAGIT on 22/06/2024.
//

#pragma once

#include "../Model/Player.hpp"

namespace model {
    class GameController {

    public:
        [[nodiscard]] bool isGameOver() const;

        [[nodiscard]] const shared_ptr<Player> &getWinner() const;

        [[nodiscard]] vector<shared_ptr<Road>> availableRoadsToBuild() const;

        vector<shared_ptr<Node>> availableSettlementToBuild() const;

        [[nodiscard]] bool canBuildSettlement(int playerId, int nodeId) const;
    };
}
