// sagitmalka10@gmail.com

#pragma once

#include <vector>
#include <memory>
#include <array>
#include "Road.hpp"

using std::vector;
using std::shared_ptr;
using std::array;

namespace model{
    const int NUM_NODES = 6;
    class Tile{
    private:
        int id;
        Resource resource_type;
        int diced_number;
        vector<shared_ptr<Node>> nodes = {};
        vector<shared_ptr<Road>> roads = {};

    public:
        Tile()= default;
        Tile(int id, Resource resourceType, int number): id(id), resource_type(resourceType), diced_number(number) {}
        void setResourceType(Resource resource);
        void setDicedNumber(int num);

        [[nodiscard]] int getId() const;
        [[nodiscard]] Resource getResourceType() const;
        [[nodiscard]] int getDicedNumber() const;
        void addNodes(const vector<shared_ptr<Node>> &nodes);
        void addRoads(const vector<shared_ptr<Road>> &roads);
        [[nodiscard]] const vector<shared_ptr<model::Node>> & getNodes() const;
        [[nodiscard]] const vector<shared_ptr<model::Road>> & getRoads() const;

    };

}

