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
        int a_length = int(a.length());
        int b_length = int(b.length());

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


    void Board::initializeBoard() {
        initializeTiles();
        initializeNodes();
        initializeRoads();
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
        std::array<std::string,Board::NUM_TILES> r = {};
        std::array<int,Board::NUM_TILES> ids = {};
        for (int i = 0; i < Board::NUM_TILES; i++) {
            r[i] = Board::getTileResource(i);
            ids[i] = Board::getTileNum(i);
        }

        os<<"                               |0|--0--|1|                                    "<<std::endl;
        os<<"                              /           \\                                  "<<std::endl;
        os<<"                             1      0      2                                  "<<std::endl;
        os << "                            /    " << r[0] << "    \\                                " << std::endl;
        os<<"                  |2|--3--|3|       "<<ids[0]<<"       |4|--4--|5|                       "<<std::endl;
        os<<"                 /           \\              /           \\                   "<<std::endl;
        os<<"                5      1      6            7      2      8                    "<<std::endl;
        os<<"               /     " << r[1] << "    \\          /     "<< r[2] <<"    \\                 "<<std::endl;
        os<<"     |6|--9--|7|       "<<ids[1]<<"        |8|--10-|9|        "<<ids[2]<<"      |10|--11-|11|        "<<std::endl;
        os<<R"(    /           \              /           \              /           \    )"<<std::endl;
        os<<"  12      3     13           14      4     15           16      5     17      "<<std::endl;
        os<<"  /     "<< r[3] <<"    \\          /     "<< r[4] <<"    \\          /     "<< r[5] <<"    \\  "<<std::endl;
        os<<"|12|      "<<ids[3]<<"       |13|--18-|14|      "<<ids[4]<<"      |15|--19-|16|     "<<ids[5]<<"       |17|    "<<std::endl;
        os<<R"(  \              /           \              /           \              /   )"<<std::endl;
        os<<"  20           21      6     22           23      7     24           25       "<<std::endl;
        os<<"    \\          /     "<< r[6] <<"    \\          /     "<< r[7] <<"    \\          /     "<<std::endl;
        os<<"    |18|--26-|19|       "<<ids[6]<<"      |20|--27-|21|        "<<ids[7]<<"      |22|--28-|23|         "<<std::endl;
        os<<R"(    /           \              /           \              /           \    )"<<std::endl;
        os<<"  29      8     30           31     9     32           33     10     34      "<<std::endl;
        os<<"  /     "<< r[8] <<"    \\          /     "<< r[9] <<"    \\          /     "<< r[10] <<"    \\  "<<std::endl;
        os<<"|24|      "<<ids[8]<<"       |25|--35-|26|      "<<ids[9]<<"      |27|--36-|28|     "<<ids[10]<<"       |29|    "<<std::endl;
        os<<R"(  \              /           \              /           \              /   )"<<std::endl;
        os<<"  37           38     11     39           40     12     41           42       "<<std::endl;
        os<<"    \\          /     "<< r[11] <<"    \\          /     "<< r[12] <<"    \\          /     "<<std::endl;
        os<<"    |30|--43-|31|       "<<ids[11]<<"      |32|-44-|33|        "<<ids[12]<<"      |34|--45-|35|         "<<std::endl;
        os<<R"(    /           \              /           \              /           \     )"<<std::endl;
        os<<"  46     13     47           48     14     49           50     15     51      "<<std::endl;
        os<<"  /     "<< r[13] <<"    \\          /     "<< r[14] <<"    \\          /     "<< r[15] <<"    \\  "<<std::endl;
        os<<"|36|      "<<ids[13]<<"       |37|--52-|38|      "<<ids[14]<<"      |39|--53-|40|       "<<ids[15]<<"       |41|    "<<std::endl;
        os<<R"(  \              /           \              /           \              /   )"<<std::endl;
        os<<"  54           55     16     56           57     17     58           59       "<<std::endl;
        os<<"    \\          /     "<< r[16] <<"    \\          /     "<< r[17] <<"    \\          /     "<<std::endl;
        os<<"    |42|--60-|43|       "<<ids[16]<<"      |44|--61-|45|     "<<ids[17]<<"      |46|--62-|47|         "<<std::endl;
        os<<"                \\              /           \\              /                 "<<std::endl;
        os<<"                63           64     18     65           66                    "<<std::endl;
        os<<"                  \\          /     "<< r[18] <<"    \\          /                   "<<std::endl;
        os<<"                  |48|--67-|49|      "<<ids[18]<<"       |50|--68-|51|                       "<<std::endl;
        os<<"                             \\              /                                "<<std::endl;
        os<<"                             69           70                                  "<<std::endl;
        os<<"                               \\          /                                  "<<std::endl;
        os<<"                               |52|--71-|53|                                   "<<std::endl;

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
    bool Board::isValidRoadLocation(int road_index, Player* player) const {
        // Implement logic to check if the road location is valid
        // This might include checking connectivity rules, existing roads, etc.

//        Road road = roads[road_index];
//        if(Road::isAvailable(road)){
//            if(road.roadNode(road, 1)){
//
//            }
//        }
        return true;
    }

    void Board::initializeNodes() {
        for(int i = 0; i < NUM_NODES; i++){
            auto node = std::make_shared<Node>(i);
            nodes.push_back(node);
        }
        tiles[0].addNodes({nodes[0], nodes[1], nodes[4], nodes[9], nodes[8], nodes[3]});
        tiles[1].addNodes({nodes[2], nodes[3], nodes[8], nodes[14], nodes[13], nodes[7]});
        tiles[2].addNodes({nodes[4], nodes[5], nodes[10], nodes[16], nodes[15], nodes[9]});
        tiles[3].addNodes({nodes[6], nodes[7], nodes[13], nodes[19], nodes[18], nodes[12]});
        tiles[4].addNodes({nodes[8], nodes[9], nodes[15], nodes[21], nodes[20], nodes[14]});
        tiles[5].addNodes({nodes[10], nodes[11], nodes[17], nodes[23], nodes[22], nodes[16]});
        tiles[6].addNodes({nodes[13], nodes[14], nodes[20], nodes[26], nodes[25], nodes[19]});
        tiles[7].addNodes({nodes[15], nodes[16], nodes[22], nodes[28], nodes[27], nodes[21]});
        tiles[8].addNodes({nodes[18], nodes[19], nodes[25], nodes[31], nodes[30], nodes[24]});
        tiles[9].addNodes({nodes[20], nodes[21], nodes[27], nodes[33], nodes[32], nodes[26]});
        tiles[10].addNodes({nodes[22], nodes[23], nodes[29], nodes[35], nodes[34], nodes[28]});
        tiles[11].addNodes({nodes[25], nodes[26], nodes[32], nodes[38], nodes[37], nodes[31]});
        tiles[12].addNodes({nodes[27], nodes[28], nodes[34], nodes[40], nodes[39], nodes[33]});
        tiles[13].addNodes({nodes[30], nodes[31], nodes[37], nodes[43], nodes[42], nodes[36]});
        tiles[14].addNodes({nodes[32], nodes[33], nodes[39], nodes[45], nodes[44], nodes[38]});
        tiles[15].addNodes({nodes[34], nodes[35], nodes[41], nodes[47], nodes[46], nodes[40]});
        tiles[16].addNodes({nodes[37], nodes[38], nodes[44], nodes[49], nodes[48], nodes[43]});
        tiles[17].addNodes({nodes[39], nodes[40], nodes[46], nodes[51], nodes[50], nodes[45]});
        tiles[18].addNodes({nodes[44], nodes[45], nodes[50], nodes[53], nodes[52], nodes[49]});
    }

    void Board::initializeRoads() {
        for (int i = 0; i < NUM_ROADS; i++) {
            auto road = std::make_shared<Road>(i);
            roads.push_back(road);
        }
        tiles[0].addRoads({roads[0], roads[2], roads[7], roads[10], roads[6], roads[1]});
        tiles[1].addRoads({roads[3], roads[6], roads[14], roads[18], roads[13], roads[5]});
        tiles[2].addRoads({roads[4], roads[8], roads[16], roads[19], roads[15], roads[7]});
        tiles[3].addRoads({roads[9], roads[13], roads[21], roads[26], roads[28], roads[12]});
        tiles[4].addRoads({roads[10], roads[15], roads[23], roads[27], roads[22], roads[14]});
        tiles[5].addRoads({roads[11], roads[17], roads[25], roads[28], roads[24], roads[16]});
        tiles[6].addRoads({roads[18], roads[22], roads[31], roads[35], roads[30], roads[21]});
        tiles[7].addRoads({roads[19], roads[24], roads[33], roads[36], roads[32], roads[23]});
        tiles[8].addRoads({roads[26], roads[30], roads[38], roads[43], roads[37], roads[29]});
        tiles[9].addRoads({roads[27], roads[32], roads[40], roads[44], roads[39], roads[31]});
        tiles[10].addRoads({roads[28], roads[34], roads[42], roads[45], roads[41], roads[33]});
        tiles[11].addRoads({roads[35], roads[39], roads[48], roads[52], roads[47], roads[38]});
        tiles[12].addRoads({roads[36], roads[41], roads[50], roads[53], roads[49], roads[40]});
        tiles[13].addRoads({roads[43], roads[47], roads[55], roads[60], roads[54], roads[46]});
        tiles[14].addRoads({roads[44], roads[50], roads[58], roads[62], roads[57], roads[49]});
        tiles[15].addRoads({roads[45], roads[51], roads[59], roads[62], roads[58], roads[50]});
        tiles[16].addRoads({roads[52], roads[56], roads[64], roads[67], roads[63], roads[55]});
        tiles[17].addRoads({roads[53], roads[58], roads[66], roads[68], roads[65], roads[57]});
        tiles[18].addRoads({roads[61], roads[65], roads[70], roads[71], roads[69], roads[64]});
    }

    void Board::initializeTiles() {
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

        for(int i = 0, j = 0; i < model::Board::tiles.size(); ++i, ++j)
        {
            auto r = resource_list[i];
            auto n = dice_values[j];

            if (resource_list[i] == Resource::Desert)
            {
                n = 0;
                j--;
            }

            model::Board::tiles[i] = Tile(i, r, n);
        }
    }

    array<Tile, 19> Board::getTiles() {
        return tiles;
    }

    void Board::printTileNodes(int tile_id) {
        if (tile_id < 0 || tile_id >= NUM_TILES) {
            std::cerr << "Invalid tile ID: " << tile_id << std::endl;
            return;
        }

        const Tile& tile = tiles[tile_id];
        const auto& tileNodes = tile.getNodes();

        std::cout << "Nodes for Tile ID " << tile_id << ":" << std::endl;
        for (const auto& node : tileNodes) {
            std::cout << "Node ID: " << node->getId() << std::endl;
        }
    }

    void Board::printTileRoads(int tile_id) {
        if (tile_id < 0 || tile_id >= NUM_TILES) {
            std::cerr << "Invalid tile ID: " << tile_id << std::endl;
            return;
        }

        const Tile& tile = tiles[tile_id];
        const auto& tile_roads = tile.getRoads();

        std::cout << "Roads for Tile ID " << tile_id << ":" << std::endl;
        for (const auto& road : tile_roads) {
            std::cout << "Road ID: " << road->getId() << std::endl;
        }
    }



//


} // namespace model
