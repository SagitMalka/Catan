//
// Created by SAGIT on 22/06/2024.
//

#include "TurnManagement.hpp"
#include "PlayerManagement.hpp"

#include <iostream>


using std::cout, std::cin, std::endl;

namespace model
{
    void TurnManagement::startTurn() {
        auto player = getCurrentPlayer();
        cout << player->getName() << "'s turn" << endl;

        cout << "What would you like to do?" << endl;
        bool resume = true;
        while (resume) {
            resume = chooseWhatToBuild(player);
        }
//
//        switch (option) {
//            case 1:
//                cout << "Chose: 1) Build road" << endl <<
//                     "2) Build settlement" << endl <<
//                     "3) Build City" << endl;
//                sub_option = getUserChoice(3);
//                // TODO create a function that checks where can player build
//                switch (sub_option) {
//                    case 1:  // ROAD
//                        if(player->hasResourcesForRoad()){
//                            cout << "choose your new road" << endl;
//                            edges = availableRoadsToBuild();
//                            printAvailableRoads(edges);
//                            road_index = getUserChoice(edges.size());
//                            player->addRoad(board.getRoad(road_index));
////                            TODO add validation to road_index
//                        }else{
//                            cout << "You do not have enough resources.";
//                        }
//                        break;
//                    case 2: // SETTLEMENT
//                        if(player->hasResourcesForNewSettlement()){
//                            cout << "choose your new settlement" << endl;
//                            vector<shared_ptr<Node>> available_nodes = availableSettlementToBuild();
//                            int node_index = -1;
//                            printAvailableNodes(available_nodes);
//                            node_index = getUserChoice(available_nodes.size());;
//                            player->addSettlement(board.getNode(node_index));
//                        }
//                        break;
//                    case 3:
//                        break;
//                    default:
//                        break;
//                }
//                cout << "choose your new road" << endl;
//                edges = availableRoadsToBuild();
//                printAvailableRoads(edges);
//                cin >> road_index;
//                player->addRoad(board.getRoad(road_index));
//
//                break;
//            case 2:
//                // TODO method to trade
//                break;
//            case 3:
//                //TODO check if player has enough resource cards
//                if(buyDevelopmentCard() != 0){
//                    cout << "Sorry no more development cards or no money" << endl;
//                }
//                break;
//            case 4:
//                //TODO check if it's cards are useful
//                break;
//            default:
//                cout << "can't" << endl;
//        }

    }

    void TurnManagement::endTurn() {
        // Logic to end the current player's turn and move to the next player
        currentPlayerIndex = (currentPlayerIndex + 1) % int(players.size());
    }

    void TurnManagement::rollDice() {
        // Logic to roll the dice and distribute resources
    }


    const std::shared_ptr<Player> &TurnManagement::getCurrentPlayer() const {
        return players[currentPlayerIndex];
    }
}