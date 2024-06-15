//
// Created by SAGIT on 14/06/2024.
//

#ifndef CATAN_ROAD_HPP
#define CATAN_ROAD_HPP
#include "Player.hpp"
#include "Tile.hpp"
#include "Node.hpp"

namespace model {
    class Road {
    private:
        Player* owner = nullptr;
//        Tile* tileConnected_1; //might be none
//        Tile* tileConnected_2;
        Node* settlement_1;
        Node* settlement_2;
    public:
        void  createNewRoad(Player *owner, Node* settlement_1,  Node* settlement_2);

        [[nodiscard]] Player* getRoadOwner() const;
        void updateOwner(Player* player);

    };
}

#endif //CATAN_ROAD_HPP
