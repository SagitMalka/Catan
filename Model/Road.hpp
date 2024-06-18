//
// Created by SAGIT on 14/06/2024.
//

#pragma once
//#include "Player.hpp"
//#include "Tile.hpp"
//#include "Node.hpp"
#include <utility>

using std::pair;

namespace model {
    class Road {
    private:
        int id;
        bool available = true;
        int owner_id;
//        Tile* tileConnected_1; //might be none
//        Tile* tileConnected_2;
        //pair<Node*, Node*> road_nodes;
//        model::Node* settlement_1;
//        model::Node* settlement_2;
    public:
        Road() = default;
        ~Road() = default;
        explicit Road(int id);
        //Road(int id, pair<Node*, Node*>* nodes);
        [[nodiscard]] int getId() const;
//        void  createNewRoad(int owner_id, Node* settlement_1,  Node* settlement_2);
        static bool isAvailable(Road& road) ;
        [[nodiscard]] int getRoadOwnerId() const;
        void updateOwner(int player_id);
        //Node* roadNode(Road& road, int i);

    };
}

