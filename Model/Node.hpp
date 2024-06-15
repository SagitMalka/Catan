//
// Created by SAGIT on 14/06/2024.
//

#pragma once
#include "Tile.hpp"
#include "Player.hpp"

namespace model {
    enum class NodeStatus {
        AVAILABLE,
        SETTLEMENT,
        CITY,
        BLOCKED
    };


    class Node {
    private:

//        Tile *tile_upOrDown;
//        Tile *tile_left;
//        Tile *tile_right;

        Player *owner;
        NodeStatus node_type = NodeStatus::AVAILABLE;
    public:
        Node() = default;
        explicit Node(int id);
        int ID;
        //void createNewNode(Tile *upOrDown, Tile *left, Tile *right, Player *newOwner, NodeStatus type);

        Player* getOwner() const;
        NodeStatus getSettlementType() const;

        void setOwner(Player* newOwner);
        void setSettlementType(NodeStatus newType);
    };
}
