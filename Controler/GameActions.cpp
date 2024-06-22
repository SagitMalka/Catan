//
// Created by SAGIT on 22/06/2024.
//
#include "Utils.hpp"
#include "GameActions.hpp"
#include "../Model/Player.hpp"
#include "GameController.hpp"
#include "TurnManagement.hpp"

#include <iostream>

using std::cout, std::cin, std::endl;

namespace model
{
    void GameActions::tradeResources(int fromPlayerId, int toPlayerId, Resource give, Resource receive) {
        // Logic to trade resources between players
    }

    int GameActions::buyDevelopmentCard() {
        if(!developmentCardDeck.isEmpty()){
            auto p = getCurrentPlayer();
            if(p->hasResourcesForDevCard()){
                auto dev_card = developmentCardDeck.drawCard();
                p->addDevelopmentCard(dev_card);
                cout << "You've got " << dev_card.toString();
                return 0;
            } else{
                return 1;
            }
        }
        return 2;
    }

    void GameActions::printAvailableRoads(vector<shared_ptr<Road>> &road_list) {
        std::cout << "You can build a new road in: " << std::endl;
        for (int i = 0; i < int(road_list.size()); ++i) {
            std::cout << i + 1 << ") Edge-"<<road_list[i]->getId() << std::endl;
        }
    }

    void GameActions::printAvailableNodes(vector<shared_ptr<Node>> &node_list) {
        std::cout << "You can build a new settlement in: " << std::endl;
        for (int i = 0; i < int(node_list.size()); ++i) {
            std::cout << i + 1 << ") Edge-"<<node_list[i]->getId() << std::endl;
        }
    }


    void GameActions::tryBuildRoad(const shared_ptr<Player> &player)
    {
        vector<shared_ptr<Road>> edges;
        int road_index = -1;
        if(player->hasResourcesForRoad()){
            cout << "choose your new road" << endl;
            edges = availableRoadsToBuild();
            printAvailableRoads(edges);
            road_index = getUserChoice(edges.size());
            player->addRoad(board.getRoad(road_index));
        }else{
            cout << "You do not have enough resources."<<endl;
        }
    }

    void GameActions::tryBuildSettlement(const shared_ptr<Player> &player)
    {
        if(player->hasResourcesForNewSettlement()){
            cout << "choose your new settlement" << endl;
            vector<shared_ptr<Node>> available_nodes = availableSettlementToBuild();
            int node_index = -1;
            printAvailableNodes(available_nodes);
            node_index = getUserChoice(available_nodes.size());;
            player->addSettlement(Board::getNode(node_index));
        }else{
            cout << "You do not have enough resources." <<endl;
        }
    }

    void GameActions::build(const std::shared_ptr<Player>& player)
    {
        cout << "Chose: 1) Build road" << endl <<
             "2) Build settlement" << endl <<
             "3) Build City" << endl <<
             "4) Finish Turn" << endl;

        int sub_option = getUserChoice(4);
        // TODO create a function that checks where can player build
        switch (sub_option) {
            case 1:  // ROAD
                tryBuildRoad(player);
                break;
            case 2: // SETTLEMENT
                tryBuildSettlement(player);
                break;
            case 3:

                break;
            default:
                cout << "Invalid choice. Please select a number between 1 and 3." << endl;
                break;
        }
    }

    bool GameActions::chooseWhatToBuild(const shared_ptr<Player> &player){
        int option = 0, sub_option = 0;
        cout << "1) Build (road/settlement/city)" << endl <<
             "2) Trade" << endl <<
             "3) Buy a development card" << endl <<
             "4) Use a development card" <<endl;
        option = getUserChoice(4);

        int road_index;
        switch (option) {
            case 1:
                build(player);
                break;
            case 2:
                // TODO method to trade
                break;
            case 3:
                //TODO check if player has enough resource cards
                if(buyDevelopmentCard() != 0){
                    cout << "Sorry no more development cards or no money" << endl;
                }
                break;
            case 4:
                //TODO check if it's cards are useful
                break;
            default:
                cout << "can't" << endl;
        }
    }
}