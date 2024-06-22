//
// Created by SAGIT on 22/06/2024.
//

#pragma once

#include <vector>
#include <memory>

#include "../Model/Resource.hpp"
#include "../Model/Road.hpp"
#include "../Model/Player.hpp"

using std::vector;
using std::shared_ptr;

namespace model {
    class GameActions {
        void tradeResources(int fromPlayerId, int toPlayerId, Resource give, Resource receive);


        int buyDevelopmentCard();

        static void printAvailableRoads(vector <shared_ptr<Road>> &road_list);

        static void printAvailableNodes(vector <shared_ptr<Node>> &node_list);

        void tryBuildRoad(const shared_ptr <Player> &player);

        void tryBuildSettlement(const shared_ptr <Player> &player); // Try build

        void build(const shared_ptr <Player> &player); // Build settlement/road/city
        bool chooseWhatToBuild(const shared_ptr<Player> &player);


    };
}