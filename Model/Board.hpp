#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <array>
#include "Tile.hpp"
#include "Node.hpp"
#include "Road.hpp"
//#include "Constants.hpp"


using std::vector;
using std::ostream;
using std::shared_ptr;
namespace model {

    class Board {

    private:
        // Constants for the board layout
        static const int NUM_TILES = 19;
        static const int NUM_NODES = 54;
        static const int NUM_ROADS = 72;

        // class members
        static std::array<Tile, NUM_TILES> tiles;
        static vector<shared_ptr<Node>> board_nodes;
        static vector<shared_ptr<Road>> roads;

        // Helper methods
//        bool isValidSettlementLocation(int tileIndex, Player* player) const;
        //bool isValidRoadLocation(int road_index, Player* player) const;
        static void initializeTiles();

        static void initializeNodes();

        static void initializeRoads();
//

    public:
        Board();

        [[nodiscard]] static array<Tile, NUM_TILES> getTiles();

//
//        // Methods to initialize and manipulate the board
        static void initializeBoard();

        static void printTileNodes(int tile_id);

        static void printTileRoads(int tile_id);

        friend ostream &operator<<(ostream &os, const Board &board);

        static Tile *getTile(int index);

        [[nodiscard]] static shared_ptr<model::Node> getSettlement(int index);
//        Road* getRoad(int index) const;
//
//        // Methods to place board_nodes and roads
//        bool placeSettlement(int tileIndex, Player* player, NodeStatus type);
//        bool placeRoad(Player* player, int tileIndex1, int tileIndex2);

        static vector<shared_ptr<Node>> getAdjacentNodes(const shared_ptr<Node> &node);

        static std::string getTileResource(int id);

        static int getTileNum(int id);
        //static void updateNodeStatus(int node_id, NodeStatus status);
    };

} // namespace model

#endif // BOARD_H
