#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <array>
#include "Tile.hpp"
#include "Node.hpp"
#include "Road.hpp"
#include "Player.hpp"

using std::vector;
using std::ostream;

namespace model {

    class Board {

    private:
        // Constants for the board layout
        static const int NUM_TILES = 19;
        static const int NUM_NODES = 54;
        static const int NUM_ROADS = 72;

        // class members
        static std::array<Tile, NUM_TILES> tiles;
        std::array<Node, NUM_NODES> nodes;
        std::array<Road, NUM_ROADS> roads;



        // Helper methods
//        bool isValidSettlementLocation(int tileIndex, Player* player) const;
//        bool isValidRoadLocation(int tileIndex1, int tileIndex2, Player* player) const;
//

    public:
        Board();

//
//        // Methods to initialize and manipulate the board
        void initializeBoard();

        friend ostream &operator<<(ostream &os, const Board &board);
//        Tile* getTile(int index) const;
//        Node* getSettlement(int index) const;
//        Road* getRoad(int index) const;
//
//        // Methods to place nodes and roads
//        bool placeSettlement(int tileIndex, Player* player, NodeStatus type);
//        bool placeRoad(Player* player, int tileIndex1, int tileIndex2);

        void initializeNodeList();

        static std::string getTileResource(int id);

        static int getTileNum(int id);
    };

} // namespace model

#endif // BOARD_H
