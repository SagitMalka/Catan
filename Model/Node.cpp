// sagitmalka10@gmail.com

#include "Node.hpp"

namespace model {

    Node::Node(int id) : id(id) {}

    NodeStatus Node::getNodeStatus() {
        return node_status;
    }
    std::string Node::getNodeStatusStr() {
        switch (node_status)
        {
            case NodeStatus::SETTLEMENT:
                return "Settlement";
            case NodeStatus::CITY:
                return "City";
            default:
                return "Empty";
        };
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

    bool Node::isAvailable() {
        return node_status == NodeStatus::AVAILABLE;
    }

    std::ostream &operator<<(std::ostream &os, const Node &node) {
        if(IS_COLOR){
            std::string BG = "";
            if (node.node_status == NodeStatus::CITY){
                BG = WHITE_BACKGROUND;
            }
            os << BG << getColorByID(node.owner_id) << "|"<< node.id << "|"<< RESET;
        }else{
            os << "|"<< node.id<< "|";
        }
        return os;
    }


}
