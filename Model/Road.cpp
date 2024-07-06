// sagitmalka10@gmail.com

#include "Road.hpp"

#include <utility>
#include <array>

namespace model {
    Road::Road(int id) : id(id), owner_id(-1) {}

    void Road::setOwner(int player_id) {
        owner_id = player_id;
    }

    bool Road::isAvailable() const{
        return this->owner_id == -1;
    }

    int Road::getId() const {
        return id;
    }

    int Road::getRoadOwnerId() const {
        return owner_id;
    }

    std::shared_ptr<Node> Road::getNode(int index) {
        if(index == 2){
            return node2;
        }
        return node1;
    }

    std::array<std::shared_ptr<Node>, 2> Road::getNodes() {
        std::array<std::shared_ptr<Node>, 2> nodes{{node1, node2}};
        return nodes;
    }

    std::shared_ptr<Node> Road::getOtherNode(const std::shared_ptr<Node> &node) {
        if(node->getId() == node1->getId() || node->getId() == node2->getId()) {
            if (node->getId() == node1->getId())
                return node2;
            else if (node->getId() == node2->getId())
                return node1;
        }
        throw std::runtime_error("Tried to get other node of a node that does not belong to road.");
    }

    std::ostream &operator<<(std::ostream &os, const Road &road) {
        if(IS_COLOR){
            os << getColorByID(road.owner_id) << road.id << RESET;
        }else{
            os <<  road.id;
        }
        return os;
    }

    bool Road::isConnectedToNode(int node_id) {
        if(this->node1->getId() == node_id){
            return true;
        } else if( this->node2->getId() == node_id){
            return true;
        }
        return false;
    }

    void Road::setAdjNodes(std::shared_ptr<Node> x, std::shared_ptr<Node> y) {
        this->node1 = std::move(x);
        this->node2 = std::move(y);
    }

}