//
// Created by SAGIT on 14/06/2024.
//

#pragma once
//#include "Player.hpp"
//#include "Tile.hpp"
#include "Node.hpp"
#include <utility>
#include <memory>
#include "Constants.hpp"

using std::pair;

namespace model {
    class Road {
    private:
        int id;
        int owner_id = -1;

        std::shared_ptr<Node> node1;
        std::shared_ptr<Node> node2;
//        Tile* tileConnected_1; //might be none
//        Tile* tileConnected_2;
        //pair<Node*, Node*> road_nodes;
//        model::Node* settlement_1;
//        model::Node* settlement_2;
    public:
        Road() = default;
        ~Road() = default;
        explicit Road(int id);
        //Road(int id, pair<Node*, Node*>* board_nodes);
        [[nodiscard]] int getId() const;
//        void  createNewRoad(int owner_id, Node* settlement_1,  Node* settlement_2);
        bool isAvailable() const;
        [[nodiscard]] int getRoadOwnerId() const;
        void setOwner(int player_id);
        std::shared_ptr<Node> getNode(int index);
        friend std::ostream &operator<<(std::ostream &os, const Road &road);
        //Node* roadNode(Road& road, int i);
        bool isConnectedToNode(int node_id);
        void setAdjNodes(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2);

        std::shared_ptr<Node> getOtherNode(const std::shared_ptr<Node> &node);

        std::array<std::shared_ptr<Node>, 2> getNodes();
    };
}

