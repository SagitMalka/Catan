
#include "Tile.hpp"

namespace model {
    Resource Tile::getResourceType() const {
        return resourceType;
    }

    int Tile::getDicedNumber() const {
        return diced_number;
    }

    int Tile::getId() const {
        return id;
    }

    void Tile::setResourceType(Resource resource) {
        resourceType = resource;
    }

    void Tile::setDicedNumber(int num) {
        diced_number = num;
    }

    void Tile::setId(int id) {
        id = id;
    }



}