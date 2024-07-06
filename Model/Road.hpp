// sagitmalka10@gmail.com

#pragma once

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

    public:
        Road() = default;
        ~Road() = default;
        explicit Road(int id);
        [[nodiscard]] int getId() const;
        bool isAvailable() const;
        [[nodiscard]] int getRoadOwnerId() const;
        void setOwner(int player_id);
        std::shared_ptr<Node> getNode(int index);
        friend std::ostream &operator<<(std::ostream &os, const Road &road);
        bool isConnectedToNode(int node_id);
        void setAdjNodes(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2);

        std::shared_ptr<Node> getOtherNode(const std::shared_ptr<Node> &node);

        std::array<std::shared_ptr<Node>, 2> getNodes();
    };
}

