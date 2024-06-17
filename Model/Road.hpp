//
// Created by SAGIT on 14/06/2024.
//

#pragma once
#include "Player.hpp"
#include "Tile.hpp"
#include "Node.hpp"
#include <utility>
using std::pair;

namespace model {
    class Road {
    private:
        int id;
        bool available = true;
        Player* owner = nullptr;
//        Tile* tileConnected_1; //might be none
//        Tile* tileConnected_2;
        pair<Node*, Node*> road_nodes;
        Node* settlement_1;
        Node* settlement_2;
    public:
        //Road(int id, pair<Node*, Node*>* nodes);
        void  createNewRoad(Player *owner, Node* settlement_1,  Node* settlement_2);
        static bool isAvailable(Road& road) ;
        [[nodiscard]] Player* getRoadOwner() const;
        void updateOwner(Player* player);
        Node* roadNode(Road& road, int i);

    };
}

