#include "GameController.hpp"

using std::cout, std::cin, std::endl;
namespace model {

    GameController::GameController()
            : currentPlayerIndex(0), gameOver(false), winner(nullptr) {
        initializeGame();
    }


/**
 * TO DO:
 * in controller call addPlayer
 * */


/**
 *
 *
 * */







//    void Game::buildSettlement(int playerId, int nodeId) {
//        if (canBuildSettlement(playerId, nodeId)) {
//            // Deduct resources from the player
//            auto player = players[playerId];
//            player->deductResourcesForSettlement();
//
//            // Create and place the settlement
//            //model::Node::setNodeStatus(NodeStatus::SETTLEMENT);
//            auto settlement = model::Board::getNode(nodeId);
//            settlement->setNodeStatus(NodeStatus::SETTLEMENT);
//            // Update player's settlements
//            player->addSettlement(settlement);
//
//            std::cout << "Settlement built successfully!" << std::endl;
//        } else {
//            std::cerr << "Cannot build settlement at the specified location." << std::endl;
//        }
//    }



    void GameController::distributeResources(int rollResult) {
        // Logic to distribute resources based on the roll result
    }


//    bool GameController::isInitialPlacementPhase() const {
//        return InitialPlacementPhase;
//    }



//    void GameController::endOfInitialPlacement() {
//        InitialPlacementPhase = false;
//    }

    void GameController::blockAdjNodes(shared_ptr<Node>& node) {
        auto adj_nodes = model::Board::getAdjacentNodes(node);
        for(const auto& n : adj_nodes){
            n->setNodeStatus(NodeStatus::BLOCKED);
        }

    }



}
