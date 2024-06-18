//
// Created by SAGIT on 14/06/2024.
//

#include "Node.hpp"

namespace model {

//    void Node::createNewNode(Tile *upOrDown, Tile *left, Tile *right, Player *newOwner, NodeStatus type){
//        this->tile_upOrDown = upOrDown;
//        this->tile_left = left;
//        this->tile_right = right;
//        this->owner = newOwner;
//        this->node_type = type;
//    }
//
//    Tile *Node::getTileUpOrDown() const {
//        return tile_upOrDown;
//    }
//
//    Tile *Node::getTileLeft() const {
//        return tile_left;
//    }
//
//    Tile *Node::getTileRight() const {
//        return tile_right;
//    }



    NodeStatus Node::getSettlementType() const {
        return node_type;
    }

    void Node::setSettlementType(NodeStatus newType) {
        node_type = newType;
    }

    Node::Node(int id) {
        this->id = id;
    }


    int Node::getId() const {
        return id;
    }

    int Node::getOwnerId() const {
        return owner_id;
    }
}
