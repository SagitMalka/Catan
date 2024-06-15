#pragma once

#include <array>
#include "Resource.hpp"
#include "Node.hpp"
#include "Road.hpp"

using std::array;
namespace model{

    class Tile{
    private:
        int id{};
        Resource resourceType;
        int diced_number{};
//        array<Node*, 6> tile_nodes{};
//        array<Road*, 6> tile_roads{};

    public:
        Tile()= default;
        Tile(int id, Resource resourceType, int number): id(id), resourceType(resourceType), diced_number(number) {}
        void setResourceType(Resource resource);
        void setDicedNumber(int num);
        static void setId(int id);

        [[nodiscard]] int getId() const;
        [[nodiscard]] Resource getResourceType() const;
        [[nodiscard]] int getDicedNumber() const;
        void setNodeOfTile(int index, int id_of_node);
        void setNodesList();

    };

}

