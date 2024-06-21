// model/Board.cpp

#include "Board.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <random>
#include <unordered_set>
//#include <iterator>

using std::array;


namespace model {
    std::array<Tile, Board::NUM_TILES> Board::tiles;
    vector<shared_ptr<Node>> Board::board_nodes;
    vector<shared_ptr<Road>> Board::roads;

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
    ostream &operator<<(ostream &os, const Board &) {
        std::array<std::string,Board::NUM_TILES> r = {};
        std::array<int,Board::NUM_TILES> ids = {};
        std::array<shared_ptr<Node>, 54> n = {};
        for (int i = 0; i < Board::NUM_TILES; i++) {
            r[i] = Board::getTileResource(i);
            ids[i] = Board::getTileNum(i);
            n[i] = Board::board_nodes[i];
        }

        os<<"                               " << n[0] << "--0--" << n[1] << "                                    "<<std::endl;
        os<<"                              /           \\                                  "<<std::endl;
        os<<"                             1      0      2                                  "<<std::endl;
        os << "                            /    " << r[0] << "    \\                                " << std::endl;
        os<<"                  " << n[2] << "--3--" << n[3] << "       "<<ids[0]<<"       " << n[4] << "--4--" << n[5] << "                       "<<std::endl;
        os<<"                 /           \\              /           \\                   "<<std::endl;
        os<<"                5      1      6            7      2      8                    "<<std::endl;
        os<<"               /     " << r[1] << "    \\          /     "<< r[2] <<"    \\                 "<<std::endl;
        os<<"     " << n[6] << "--9--" << n[7] << "       "<<ids[1]<<"        " << n[8] << "--10-" << n[9] << "        "<<ids[2]<<"      " << n[10] << "--11-" << n[11] << "        "<<std::endl;
        os<<R"(    /           \              /           \              /           \    )"<<std::endl;
        os<<"  12      3     13           14      4     15           16      5     17      "<<std::endl;
        os<<"  /     "<< r[3] <<"    \\          /     "<< r[4] <<"    \\          /     "<< r[5] <<"    \\  "<<std::endl;
        os<<"" << n[12] << "      "<<ids[3]<<"       " << n[13] << "--18-" << n[14] << "      "<<ids[4]<<"      " << n[15] << "--19-" << n[16] << "     "<<ids[5]<<"       " << n[17] << "    "<<std::endl;
        os<<R"(  \              /           \              /           \              /   )"<<std::endl;
        os<<"  20           21      6     22           23      7     24           25       "<<std::endl;
        os<<"    \\          /     "<< r[6] <<"    \\          /     "<< r[7] <<"    \\          /     "<<std::endl;
        os<<"    " << n[18] << "--26-" << n[19] << "       "<<ids[6]<<"      " << n[20] << "--27-" << n[21] << "        "<<ids[7]<<"      " << n[22] << "--28-" << n[23] << "         "<<std::endl;
        os<<R"(    /           \              /           \              /           \    )"<<std::endl;
        os<<"  29      8     30           31     9     32           33     10     34      "<<std::endl;
        os<<"  /     "<< r[8] <<"    \\          /     "<< r[9] <<"    \\          /     "<< r[10] <<"    \\  "<<std::endl;
        os<<"" << n[24] << "      "<<ids[8]<<"       " << n[25] << "--35-" << n[26] << "      "<<ids[9]<<"      " << n[27] << "--36-" << n[28] << "     "<<ids[10]<<"       " << n[29] << "    "<<std::endl;
        os<<R"(  \              /           \              /           \              /   )"<<std::endl;
        os<<"  37           38     11     39           40     12     41           42       "<<std::endl;
        os<<"    \\          /     "<< r[11] <<"    \\          /     "<< r[12] <<"    \\          /     "<<std::endl;
        os<<"    " << n[30] << "--43-" << n[31] << "       "<<ids[11]<<"      " << n[32] << "-44-" << n[33] << "        "<<ids[12]<<"      " << n[34] << "--45-" << n[35] << "         "<<std::endl;
        os<<R"(    /           \              /           \              /           \     )"<<std::endl;
        os<<"  46     13     47           48     14     49           50     15     51      "<<std::endl;
        os<<"  /     "<< r[13] <<"    \\          /     "<< r[14] <<"    \\          /     "<< r[15] <<"    \\  "<<std::endl;
        os<<"" << n[36] << "      "<<ids[13]<<"       " << n[37] << "--52-" << n[38] << "      "<<ids[14]<<"      " << n[39] << "--53-" << n[40] << "       "<<ids[15]<<"       " << n[41] << "    "<<std::endl;
        os<<R"(  \              /           \              /           \              /   )"<<std::endl;
        os<<"  54           55     16     56           57     17     58           59       "<<std::endl;
        os<<"    \\          /     "<< r[16] <<"    \\          /     "<< r[17] <<"    \\          /     "<<std::endl;
        os<<"    " << n[42] << "--60-" << n[43] << "       "<<ids[16]<<"      " << n[44] << "--61-" << n[45] << "     "<<ids[17]<<"      " << n[46] << "--62-" << n[47] << "         "<<std::endl;
        os<<"                \\              /           \\              /                 "<<std::endl;
        os<<"                63           64     18     65           66                    "<<std::endl;
        os<<"                  \\          /     "<< r[18] <<"    \\          /                   "<<std::endl;
        os<<"                  " << n[48] << "--67-" << n[49] << "      "<<ids[18]<<"       " << n[50] << "--68-" << n[51] << "                       "<<std::endl;
        os<<"                             \\              /                                "<<std::endl;
        os<<"                             69           70                                  "<<std::endl;
        os<<"                               \\          /                                  "<<std::endl;
        os<<"                               " << n[52] << "--71-" << n[53] << "                                   "<<std::endl;

        return os;
    }

    void Board::initializeNodes() {
        for(int i = 0; i < NUM_NODES; i++){
            auto node = std::make_shared<Node>(i);
            board_nodes.push_back(node);
        }
        tiles[0].addNodes({board_nodes[0], board_nodes[1], board_nodes[4], board_nodes[9], board_nodes[8], board_nodes[3]});
        tiles[1].addNodes({board_nodes[2], board_nodes[3], board_nodes[8], board_nodes[14], board_nodes[13], board_nodes[7]});
        tiles[2].addNodes({board_nodes[4], board_nodes[5], board_nodes[10], board_nodes[16], board_nodes[15], board_nodes[9]});
        tiles[3].addNodes({board_nodes[6], board_nodes[7], board_nodes[13], board_nodes[19], board_nodes[18], board_nodes[12]});
        tiles[4].addNodes({board_nodes[8], board_nodes[9], board_nodes[15], board_nodes[21], board_nodes[20], board_nodes[14]});
        tiles[5].addNodes({board_nodes[10], board_nodes[11], board_nodes[17], board_nodes[23], board_nodes[22], board_nodes[16]});
        tiles[6].addNodes({board_nodes[13], board_nodes[14], board_nodes[20], board_nodes[26], board_nodes[25], board_nodes[19]});
        tiles[7].addNodes({board_nodes[15], board_nodes[16], board_nodes[22], board_nodes[28], board_nodes[27], board_nodes[21]});
        tiles[8].addNodes({board_nodes[18], board_nodes[19], board_nodes[25], board_nodes[31], board_nodes[30], board_nodes[24]});
        tiles[9].addNodes({board_nodes[20], board_nodes[21], board_nodes[27], board_nodes[33], board_nodes[32], board_nodes[26]});
        tiles[10].addNodes({board_nodes[22], board_nodes[23], board_nodes[29], board_nodes[35], board_nodes[34], board_nodes[28]});
        tiles[11].addNodes({board_nodes[25], board_nodes[26], board_nodes[32], board_nodes[38], board_nodes[37], board_nodes[31]});
        tiles[12].addNodes({board_nodes[27], board_nodes[28], board_nodes[34], board_nodes[40], board_nodes[39], board_nodes[33]});
        tiles[13].addNodes({board_nodes[30], board_nodes[31], board_nodes[37], board_nodes[43], board_nodes[42], board_nodes[36]});
        tiles[14].addNodes({board_nodes[32], board_nodes[33], board_nodes[39], board_nodes[45], board_nodes[44], board_nodes[38]});
        tiles[15].addNodes({board_nodes[34], board_nodes[35], board_nodes[41], board_nodes[47], board_nodes[46], board_nodes[40]});
        tiles[16].addNodes({board_nodes[37], board_nodes[38], board_nodes[44], board_nodes[49], board_nodes[48], board_nodes[43]});
        tiles[17].addNodes({board_nodes[39], board_nodes[40], board_nodes[46], board_nodes[51], board_nodes[50], board_nodes[45]});
        tiles[18].addNodes({board_nodes[44], board_nodes[45], board_nodes[50], board_nodes[53], board_nodes[52], board_nodes[49]});
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

//    void Board::updateNodeStatus(int node_id, NodeStatus status) {
//        for (const auto& node : board_nodes) {
//            if(node->getId() == node_id){
//                Node::setNodeStatus(status);
//            }
//        }
//    }

    Tile* Board::getTile(int index) {
        return &tiles[index];
    }

    shared_ptr<model::Node> Board::getSettlement(int index) {
        const shared_ptr<Node> node = board_nodes[index];
        return node;
    }

    vector<shared_ptr<Node>> Board::getAdjacentNodes(const shared_ptr<Node> &node) {
        std::unordered_set<std::shared_ptr<Node>> adjacentNodes;

        for (const auto& road : roads) {
            if (road->getNodeOfRoad(1) == node) {
                adjacentNodes.insert(road->getNodeOfRoad(2));
            } else if (road->getNodeOfRoad(2) == node) {
                adjacentNodes.insert(road->getNodeOfRoad(1));
            }
        }

        // Convert unordered_set to vector
        std::vector<std::shared_ptr<Node>> result(adjacentNodes.begin(), adjacentNodes.end());
        return result;
    }



//


} // namespace model
