// sagitmalka10@gmail.com

#pragma once
#include <iostream>
#include "Constants.hpp"



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
        Node() = default;
        explicit Node(int id);
        [[nodiscard]] int getId() const;

        [[nodiscard]] int getOwnerId() const;
        [[nodiscard]]  NodeStatus getNodeStatus() ;
        std::string getNodeStatusStr();
        void setOwner(int newOwner);
        void setNodeStatus(NodeStatus newType);
        bool isAvailable() ;
        friend std::ostream &operator<<(std::ostream &os, const Node &node);
    };
}
