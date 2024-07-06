// sagitmalka10@gmail.com

#include "Tile.hpp"

namespace model {
    Resource Tile::getResourceType() const {
        return resource_type;
    }

    int Tile::getDicedNumber() const {
        return diced_number;
    }

    int Tile::getId() const {
        return id;
    }

    void Tile::setResourceType(Resource resource) {
        resource_type = resource;
    }

    void Tile::setDicedNumber(int num) {
        diced_number = num;
    }

    void Tile::addNodes(const vector<shared_ptr<Node>>& nodes_list) {
        nodes = nodes_list;
    }

    void Tile::addRoads(const vector<shared_ptr<Road>>& roads_list) {
        roads = roads_list;
    }

    const vector<shared_ptr<model::Node>> & Tile::getNodes() const {
        return nodes;
    }

    const vector<shared_ptr<model::Road>> & Tile::getRoads() const {
        return roads;
    }
}