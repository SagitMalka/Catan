
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
        NodeStatus node_status;
    public:
        Node() = default;
        explicit Node(int id);
        [[nodiscard]] int getId() const;

        [[nodiscard]] int getOwnerId() const;
        [[nodiscard]]  NodeStatus getNodeStatus() ;

        void setOwner(int newOwner);
        void setNodeStatus(NodeStatus newType);
        bool isOccupied() ;
    };
}
