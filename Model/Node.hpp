//
// Created by SAGIT on 14/06/2024.
//

#pragma once
//#include "Tile.hpp"
//#include "Player.hpp"

namespace model {
    enum class NodeStatus {
        AVAILABLE,
        SETTLEMENT,
        CITY,
        BLOCKED
    };


    class Node {
    private:

        int id;
        int owner_id;
        NodeStatus node_status = NodeStatus::AVAILABLE;
    public:
        //Node() = default;
        explicit Node(int id);
        [[nodiscard]] int getId() const;

        [[nodiscard]] int getOwnerId() const;
        [[nodiscard]] NodeStatus getNodeStatus() const;

        void setOwner(int newOwner);
        void setSettlementType(NodeStatus newType);
    };
}
