
#include "Road.hpp"

namespace model {

//    void Road::createNewRoad(Player *newOwner, Node* node_a, Node* node_b){
//        this->owner = newOwner;
//        this->settlement_1 = node_a;
//        this->settlement_2 = node_b;
//    }

    Player *Road::getRoadOwner() const {
        return owner;
    }

    void Road::updateOwner(Player *player) {
        owner = player;
    }

}