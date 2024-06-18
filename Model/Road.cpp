
#include "Road.hpp"

namespace model {
    Road::Road(int id) : id(id), owner_id(-1) {}
//    void Road::createNewRoad(Player *newOwner, Node* node_a, Node* node_b){
////        this->owner = newOwner;
////        this->settlement_1 = node_a;
////        this->settlement_2 = node_b;
//        this->available = false;
//    }


    void Road::updateOwner(int player_id) {
        owner_id = player_id;
    }

    bool Road::isAvailable(Road &road){
        return road.available;
    }

//    Node *Road::roadNode(Road &road, int i) {
//        if(i == 1){
//            return settlement_1;
//        } else if(i == 2){
//            return settlement_2;
//        }
//        return nullptr;
//    }

    int Road::getId() const {
        return id;
    }



    int Road::getRoadOwnerId() const {
        return owner_id;
    }

//    Road::Road(int id, pair<Node*, Node*>* nodes) {
//        this->id = id;
//        this->road_nodes = &nodes;
//    }


}