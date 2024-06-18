//
// Created by SAGIT on 14/06/2024.
//

#include "Node.hpp"

namespace model {

    Node::Node(int id) : id(id), owner_id(-1) {}
    NodeStatus Node::getNodeStatus() const {
        return node_status;
    }

    void Node::setSettlementType(NodeStatus newType) {
        node_status = newType;
    }




    int Node::getId() const {
        return id;
    }

    int Node::getOwnerId() const {
        return owner_id;
    }

    void Node::setOwner(int newOwner) {
        owner_id = newOwner;
    }

}
