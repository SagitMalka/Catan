
#include "Node.hpp"

namespace model {

    Node::Node(int id) : id(id) {}

    NodeStatus Node::getNodeStatus() {
        return node_status;
    }

    void Node::setNodeStatus(NodeStatus newType) {
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

    bool Node::isOccupied() {
        if (node_status == NodeStatus::AVAILABLE) {
            return false;
        }
        return true;
    }

    std::ostream &operator<<(std::ostream &os, const Node &node) {
        if(IS_COLOR){
            os << getColorByID(node.owner_id) << node.id << RESET;
        }else{
            os << node.id;
        }
        return os;
    }


}
