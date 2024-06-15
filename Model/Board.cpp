// model/Board.cpp

#include "Board.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <random>
#include <iterator>

using std::array;
#define RESET   "\033[0m"
#define RED     "\033[41m"      /* Red background */
#define GREEN   "\033[42m"      /* Green background */
#define YELLOW  "\033[43m"      /* Yellow background */
#define BLUE    "\033[44m"      /* Blue background */
#define MAGENTA "\033[45m"      /* Magenta background */
#define CYAN    "\033[46m"      /* Cyan background */

namespace model {
    std::array<Tile, Board::NUM_TILES> Board::tiles;

    std::string insertInMiddle(std::string a, std::string b) {
        int a_length = a.length();
        int b_length = b.length();

        // Calculate the start position for b in a
        int start_pos = (a_length - b_length) / 2;

        // Replace part of a with b
        for (int i = 0; i < b_length; ++i) {
            a[start_pos + i] = b[i];
        }

        return a;
    }

    Board::Board() {
        initializeBoard();
    }

    void Board::initializeNodeList(){
        array<Node, NUM_NODES> nodes_list = {};
        for (int i = 0; i < NUM_NODES; i++){
            nodes_list[i] = Node(i);
        }
        this->nodes = nodes_list;

    }

    void Board::initializeBoard() {
        initializeNodeList();
        std::array<Resource, NUM_TILES> resource_list = {Resource::Wood, Resource::Wood, Resource::Wood,
                                                         Resource::Brick, Resource::Brick, Resource::Brick,
                                                         Resource::Ore, Resource::Ore, Resource::Ore,
                                                         Resource::Sheep, Resource::Sheep, Resource::Sheep, Resource::Sheep,
                                                         Resource::Wheat, Resource::Wheat, Resource::Wheat, Resource::Wheat,
                                                         Resource::Desert
                                                        };
        std::array<int, NUM_TILES -1> dice_values = {2, 3, 3, 4, 4, 5, 5, 6, 6, 8, 8, 9, 9, 10, 10, 11, 11, 12};

        //std::random_device rd_1;
        unsigned int rd_1 = 2;
        std::mt19937 g_1(rd_1);

        std::shuffle(std::begin(resource_list), std::end(resource_list), g_1);

        //std::random_device rd_2;
        std::mt19937 g_2(rd_1);

        std::shuffle(std::begin(dice_values), std::end(dice_values), g_2);

        for(int i = 0, j = 0; i < this->tiles.size(); ++i, ++j)
        {
            auto r = resource_list[i];
            auto n = dice_values[j];

            if (resource_list[i] == Resource::Desert)
            {
                n = 0;
                j--;
            }

            this->tiles[i] = Tile(i, r, n);
        }

    }
    std::string Board::getTileResource(int id) {
        Resource r = model::Board::tiles[id].getResourceType();
        switch (r) {
            case Resource::Wood:   return " Wood ";
            case Resource::Brick:  return "Brick ";
            case Resource::Sheep:  return "Sheep ";
            case Resource::Wheat:  return "Wheat ";
            case Resource::Ore:    return " Ore  ";
            case Resource::Desert: return "Desert";
            default:               return "Unknown";
        }
    }
    int Board::getTileNum(int id) {
       return model::Board::tiles[id].getDicedNumber();
    }
    ostream &operator<<(ostream &os, const Board &board) {
        std::array<std::string,Board::NUM_TILES+1> r = {};
        std::array<int,Board::NUM_TILES+1> ids = {};
        for (int i = 0; i < Board::NUM_TILES+1; ++i) {
            r[i+1] = Board::getTileResource(i);
            ids[i+1] = Board::getTileNum(i);
        }

        os<<"                               |0|--0--|1|                                    "<<std::endl;
        os<<"                              /           \\                                  "<<std::endl;
        os<<"                             0      1      0                                  "<<std::endl;
        os << "                            /    " << r[1] << "    \\                                " << std::endl;
        os<<"                  |2|--0--|3|       "<<ids[1]<<"       |4|--0--|5|                       "<<std::endl;
        os<<"                 /           \\              /           \\                   "<<std::endl;
        os<<"                0      2      0            0      3      0                    "<<std::endl;
        os<<"               /     " << r[2] << "    \\          /     "<< r[3] <<"    \\                 "<<std::endl;
        os<<"     |6|--0--|7|       "<<ids[2]<<"        |8|--0--|9|        "<<ids[3]<<"      |10|--0--|11|        "<<std::endl;
        os<<"    /           \\              /           \\              /           \\    "<<std::endl;
        os<<"   0      4      0            0      5      0            0      6      0      "<<std::endl;
        os<<"  /     "<< r[4] <<"    \\          /     "<< r[5] <<"    \\          /     "<< r[6] <<"    \\  "<<std::endl;
        os<<"|12|      "<<ids[4]<<"       |13|--0--|14|      "<<ids[5]<<"      |15|--0--|16|     "<<ids[6]<<"       |17|    "<<std::endl;
        os<<"  \\              /           \\              /           \\              /   "<<std::endl;
        os<<"   0            0      7      0            0      8      0            0       "<<std::endl;
        os<<"    \\          /     "<< r[7] <<"    \\          /     "<< r[8] <<"    \\          /     "<<std::endl;
        os<<"    |18|--0--|19|       "<<ids[7]<<"      |20|--0--|21|        "<<ids[8]<<"      |22|--0--|23|         "<<std::endl;
        os<<"    /           \\              /           \\              /           \\    "<<std::endl;
        os<<"   0      9      0            0     10      0            0     11      0      "<<std::endl;
        os<<"  /     "<< r[9] <<"    \\          /     "<< r[10] <<"    \\          /     "<< r[11] <<"    \\  "<<std::endl;
        os<<"|24|      "<<ids[9]<<"       |25|--0--|26|      "<<ids[10]<<"      |27|--0--|28|     "<<ids[11]<<"       |29|    "<<std::endl;
        os<<"  \\              /           \\              /           \\              /   "<<std::endl;
        os<<"   0            0     12      0            0     13      0            0       "<<std::endl;
        os<<"    \\          /     "<< r[12] <<"    \\          /     "<< r[13] <<"    \\          /     "<<std::endl;
        os<<"    |30|--0--|31|       "<<ids[12]<<"      |32|--0--|33|        "<<ids[13]<<"      |34|--0--|35|         "<<std::endl;
        os<<"    /           \\              /           \\              /           \\     "<<std::endl;
        os<<"   0     14      0            0     15      0            0     16      0      "<<std::endl;
        os<<"  /     "<< r[14] <<"    \\          /     "<< r[15] <<"    \\          /     "<< r[16] <<"    \\  "<<std::endl;
        os<<"|36|      "<<ids[14]<<"       |37|--0--|38|      "<<ids[15]<<"      |39|--0--|40|       "<<ids[16]<<"       |41|    "<<std::endl;
        os<<"  \\              /           \\              /           \\              /   "<<std::endl;
        os<<"   0            0     17      0            0     18      0            0       "<<std::endl;
        os<<"    \\          /     "<< r[17] <<"    \\          /     "<< r[18] <<"    \\          /     "<<std::endl;
        os<<"    |42|--0--|43|       "<<ids[17]<<"      |44|--0--|45|     "<<ids[18]<<"      |46|--0--|47|         "<<std::endl;
        os<<"                \\              /           \\              /                 "<<std::endl;
        os<<"                 0            0     19      0            0                    "<<std::endl;
        os<<"                  \\          /     "<< r[19] <<"    \\          /                   "<<std::endl;
        os<<"                  |48|--0--|49|      "<<ids[19]<<"       |50|--0--|51|                       "<<std::endl;
        os<<"                             \\              /                                "<<std::endl;
        os<<"                              0            0                                  "<<std::endl;
        os<<"                               \\          /                                  "<<std::endl;
        os<<"                               |52|--0--|53|                                   "<<std::endl;
//        auto t = board.tiles[0];
//        os << insertInMiddle(a1,  std::to_string(t.getDicedNumber())) << std::endl;
//        os << a2;
        return os;
    }

//    Tile* Board::getTile(int index) const {
//        if (index < 0 || index >= NUM_TILES) {
//            throw std::out_of_range("Invalid tile index");
//        }
//        return const_cast<Tile*>(&tiles[index]);
//    }
//
//    Node* Board::getSettlement(int index) const {
//        if (index < 0 || index >= NUM_NODES) {
//            throw std::out_of_range("Invalid settlement index");
//        }
//        return const_cast<Node*>(&nodes[index]);
//    }
//
//    Road* Board::getRoad(int index) const {
//        if (index < 0 || index >= NUM_ROADS) {
//            throw std::out_of_range("Invalid road index");
//        }
//        return const_cast<Road*>(&roads[index]);
//    }
//
//    bool Board::placeSettlement(int tileIndex, Player* player, NodeStatus type) {
//        if (!isValidSettlementLocation(tileIndex, player)) {
//            return false;
//        }
//        // Find an empty settlement slot
//        for (Node& settlement : nodes) {
//            if (settlement.getOwner() == nullptr) {
//                createNewSettlement(getTile(tileIndex), nullptr, nullptr, player, type);
////                void createNewNode(Tile *upOrDown, Tile *left, Tile *right, Player *newOwner, NodeStatus type);
////                void createNewNode(Tile *upOrDown, void *pVoid, void *pVoid1, Player *pPlayer, NodeStatus type)
//                return true;
//            }
//        }
//        return false;
//    }
//
//    bool Board::placeRoad(Player* player, int tileIndex1, int tileIndex2) {
//        if (!isValidRoadLocation(tileIndex1, tileIndex2, player)) {
//            return false;
//        }
//        // Find an empty road slot
//        for (Road& road : roads) {
//            if (road.getRoadOwner() == nullptr) {
//                road = Road(player, getTile(tileIndex1), getTile(tileIndex2));
//                return true;
//            }
//        }
//        return false;
//    }
//
//    bool Board::isValidSettlementLocation(int tileIndex, Player* player) const {
//        // Implement logic to check if the settlement location is valid
//        // This might include checking adjacency rules, existing nodes, etc.
//        return true;
//    }
//
//    bool Board::isValidRoadLocation(int tileIndex1, int tileIndex2, Player* player) const {
//        // Implement logic to check if the road location is valid
//        // This might include checking connectivity rules, existing roads, etc.
//        return true;
//    }
//


} // namespace model
