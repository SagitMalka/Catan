
#include "Road.hpp"

namespace model {

    void Road::createNewRoad(Player *newOwner, Node* node_a, Node* node_b){
        this->owner = newOwner;
        this->settlement_1 = node_a;
        this->settlement_2 = node_b;
        this->available = false;
    }

    Player *Road::getRoadOwner() const {
        return owner;
    }

    void Road::updateOwner(Player *player) {
        owner = player;
    }

    bool Road::isAvailable(Road &road){
        return road.available;
    }

    Node *Road::roadNode(Road &road, int i) {
        if(i == 1){
            return settlement_1;
        } else if(i == 2){
            return settlement_2;
        }
        return nullptr;
    }

//    Road::Road(int id, pair<Node*, Node*>* nodes) {
//        this->id = id;
//        this->road_nodes = &nodes;
//    }


}