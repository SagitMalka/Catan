//
// Created by SAGIT on 22/06/2024.
//

#include "GameState.hpp"
#include "TurnManagement.hpp"
#include "../Model/Board.hpp"

namespace model {
    vector<shared_ptr<Road>> GameController::availableRoadsToBuild() const {
        auto p = getCurrentPlayer();
        vector<shared_ptr<Road>> can_build;
        for (const auto &node: p->getPlayerSettlements()) {
            auto adj_nodes = model::Board::getAvailableAdjacentRoads(node);
            for (const auto &n: adj_nodes) {
                can_build.push_back(n);
            }
        }
        return can_build;
    }

    vector<shared_ptr<Node>> GameController::availableSettlementToBuild() const {
        auto p = getCurrentPlayer();
        vector<shared_ptr<Node>> can_build;
        for (const auto &road: p->getPlayerRoads()) {
            for (int i = 1; i < 3; ++i) {
                auto node_i = road->getNodeOfRoad(i);
                if (node_i->isAvailable()) {
                    can_build.push_back(node_i);
                }
            }
        }
        return can_build;
    }

    bool GameController::canBuildSettlement(int playerId, int nodeId) const {
        //const auto& tile = model::Board::getTile(tileId);
        const auto &node = model::Board::getNode(nodeId);

        // Check if the node is already occupied
        if (!node->isAvailable()) {
            return false;
        }

        // Check the proximity rule (no adjacent settlements)
//        for (const auto& adjacentNode : model::Board::getAdjacentNodes(node)) {
//            if (!adjacentNode->isAvailable()) {
//                return false;
//            }
//        }

        // Check if the player has enough resources
//        auto player = players[playerId];
//        if (!player->hasResourcesForNewSettlement()) {
//            return false;
//        }
//
//        // Check if the player has an adjacent road (except during initial placement)
//        if (!player->hasAdjacentRoad(nodeId) && !isInitialPlacementPhase()) {
//            return false;
//        }


        return true;
    }

}