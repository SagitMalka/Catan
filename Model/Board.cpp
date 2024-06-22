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
    std::array<shared_ptr<Node>, Board::NUM_NODES> Board::board_nodes;
    std::array<shared_ptr<Road>, Board::NUM_ROADS> Board::roads;

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

    void Board::initializeNodes() {
        for(int i = 0; i < NUM_NODES; i++){
            board_nodes[i] = std::make_shared<Node>(i);;
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
            roads[i] = std::make_shared<Road>(i);
        }
        roads[0]->setAdjNodes(board_nodes[0], board_nodes[1]);
        roads[1]->setAdjNodes(board_nodes[0], board_nodes[3]);
        roads[2]->setAdjNodes(board_nodes[0], board_nodes[4]);
        roads[3]->setAdjNodes(board_nodes[2], board_nodes[3]);
        roads[4]->setAdjNodes(board_nodes[4], board_nodes[5]);
        roads[5]->setAdjNodes(board_nodes[2], board_nodes[7]);
        roads[6]->setAdjNodes(board_nodes[3], board_nodes[10]);
        roads[7]->setAdjNodes(board_nodes[4], board_nodes[9]);
        roads[8]->setAdjNodes(board_nodes[5], board_nodes[10]);
        roads[9]->setAdjNodes(board_nodes[6], board_nodes[7]);
        roads[10]->setAdjNodes(board_nodes[8], board_nodes[9]);
        roads[11]->setAdjNodes(board_nodes[10], board_nodes[11]);
        roads[12]->setAdjNodes(board_nodes[6], board_nodes[12]);
        roads[13]->setAdjNodes(board_nodes[7], board_nodes[13]);
        roads[14]->setAdjNodes(board_nodes[8], board_nodes[14]);
        roads[15]->setAdjNodes(board_nodes[9], board_nodes[15]);
        roads[16]->setAdjNodes(board_nodes[10], board_nodes[16]);
        roads[17]->setAdjNodes(board_nodes[11], board_nodes[17]);
        roads[18]->setAdjNodes(board_nodes[13], board_nodes[14]);
        roads[19]->setAdjNodes(board_nodes[15], board_nodes[16]);
        roads[20]->setAdjNodes(board_nodes[12], board_nodes[18]);
        roads[21]->setAdjNodes(board_nodes[13], board_nodes[19]);
        roads[22]->setAdjNodes(board_nodes[14], board_nodes[20]);
        roads[23]->setAdjNodes(board_nodes[15], board_nodes[21]);
        roads[24]->setAdjNodes(board_nodes[16], board_nodes[22]);
        roads[25]->setAdjNodes(board_nodes[17], board_nodes[23]);
        roads[26]->setAdjNodes(board_nodes[18], board_nodes[19]);
        roads[27]->setAdjNodes(board_nodes[20], board_nodes[21]);
        roads[28]->setAdjNodes(board_nodes[22], board_nodes[23]);
        roads[29]->setAdjNodes(board_nodes[18], board_nodes[24]);
        roads[30]->setAdjNodes(board_nodes[19], board_nodes[25]);
        roads[31]->setAdjNodes(board_nodes[20], board_nodes[26]);
        roads[32]->setAdjNodes(board_nodes[21], board_nodes[27]);
        roads[33]->setAdjNodes(board_nodes[22], board_nodes[28]);
        roads[34]->setAdjNodes(board_nodes[23], board_nodes[29]);
        roads[35]->setAdjNodes(board_nodes[25], board_nodes[26]);
        roads[36]->setAdjNodes(board_nodes[27], board_nodes[28]);
        roads[37]->setAdjNodes(board_nodes[24], board_nodes[30]);
        roads[38]->setAdjNodes(board_nodes[25], board_nodes[31]);
        roads[39]->setAdjNodes(board_nodes[26], board_nodes[32]);
        roads[40]->setAdjNodes(board_nodes[27], board_nodes[33]);
        roads[41]->setAdjNodes(board_nodes[28], board_nodes[34]);
        roads[42]->setAdjNodes(board_nodes[29], board_nodes[35]);
        roads[43]->setAdjNodes(board_nodes[30], board_nodes[31]);
        roads[44]->setAdjNodes(board_nodes[32], board_nodes[33]);
        roads[45]->setAdjNodes(board_nodes[34], board_nodes[35]);
        roads[46]->setAdjNodes(board_nodes[30], board_nodes[36]);
        roads[47]->setAdjNodes(board_nodes[31], board_nodes[37]);
        roads[48]->setAdjNodes(board_nodes[32], board_nodes[38]);
        roads[49]->setAdjNodes(board_nodes[33], board_nodes[39]);
        roads[50]->setAdjNodes(board_nodes[34], board_nodes[40]);
        roads[51]->setAdjNodes(board_nodes[35], board_nodes[41]);
        roads[52]->setAdjNodes(board_nodes[37], board_nodes[38]);
        roads[53]->setAdjNodes(board_nodes[39], board_nodes[40]);
        roads[54]->setAdjNodes(board_nodes[36], board_nodes[42]);
        roads[55]->setAdjNodes(board_nodes[37], board_nodes[43]);
        roads[56]->setAdjNodes(board_nodes[38], board_nodes[44]);
        roads[57]->setAdjNodes(board_nodes[39], board_nodes[45]);
        roads[58]->setAdjNodes(board_nodes[40], board_nodes[46]);
        roads[59]->setAdjNodes(board_nodes[41], board_nodes[47]);
        roads[60]->setAdjNodes(board_nodes[42], board_nodes[43]);
        roads[61]->setAdjNodes(board_nodes[44], board_nodes[45]);
        roads[62]->setAdjNodes(board_nodes[46], board_nodes[47]);
        roads[63]->setAdjNodes(board_nodes[43], board_nodes[48]);
        roads[64]->setAdjNodes(board_nodes[44], board_nodes[49]);
        roads[65]->setAdjNodes(board_nodes[45], board_nodes[50]);
        roads[66]->setAdjNodes(board_nodes[46], board_nodes[51]);
        roads[67]->setAdjNodes(board_nodes[48], board_nodes[49]);
        roads[68]->setAdjNodes(board_nodes[50], board_nodes[51]);
        roads[69]->setAdjNodes(board_nodes[49], board_nodes[52]);
        roads[70]->setAdjNodes(board_nodes[50], board_nodes[53]);
        roads[71]->setAdjNodes(board_nodes[52], board_nodes[53]);


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

    shared_ptr<model::Node> Board::getNode(int index) {
        //const shared_ptr<Node> node = board_nodes[index];
        return board_nodes[index];
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
    vector<shared_ptr<Node>> Board::getAvailableAdjacentNodes(const shared_ptr<Node> &node) {
        std::unordered_set<std::shared_ptr<Node>> adjacentNodes;

        for (const auto& road : roads) {
            if (road->getNodeOfRoad(1) == node) {
                auto temp = road->getNodeOfRoad(2);
                if(!temp->isAvailable()){
                    adjacentNodes.insert(temp);
                }
            } else if (road->getNodeOfRoad(2) == node) {
                auto temp = road->getNodeOfRoad(1);
                if(!temp->isAvailable()){
                    adjacentNodes.insert(temp);
                }
            }
        }

        // Convert unordered_set to vector
        std::vector<std::shared_ptr<Node>> result(adjacentNodes.begin(), adjacentNodes.end());
        return result;
    }

    vector<shared_ptr<Road>> Board::getAdjacentRoads(const shared_ptr<Node> &node) {
        vector<shared_ptr<Road>> adj_roads;
        for (const auto& road : roads) {
            if(road->isConnectedToNode(node->getId())){
                adj_roads.push_back(road);
            }
        }
        return adj_roads;
    }

    vector<shared_ptr<Road>> Board::getAvailableAdjacentRoads(const shared_ptr<Node> &node) {
        vector<shared_ptr<Road>> adj_roads;
        for (const auto& road : roads) {
            if(road->isConnectedToNode(node->getId()) && road->isAvailable()){
                adj_roads.push_back(road);
            }
        }
        return adj_roads;
    }
    std::string Board::roadsListToString(vector<shared_ptr<Road>> &roads_list) {
        std::string s;
        for(const auto& r :  roads_list){
            s + std::to_string(r->getId());
            s += " ";
        }
        s.pop_back();
        return s;
    }

    shared_ptr<Road> Board::getRoad(int index) {
        return roads[index];
    }

    const vector<std::shared_ptr<Player>> &Board::getPlayers() {
        return players;
    }

    void Board::addPlayer(const std::string &name, int id) {
        shared_ptr<Player> p = std::make_shared<Player>(name, id);
        players.push_back(p);
    }

    ostream &operator<<(ostream &os, const Board &) {
        std::array<std::string,Board::NUM_TILES> r = {};
        std::array<int,Board::NUM_TILES> ids = {};
        std::array<Node, 54> n = {};
        std::array<Road, 72> e = {};
        for (int i = 0; i < Board::NUM_TILES; i++) {
            r[i] = Board::getTileResource(i);
            ids[i] = Board::getTileNum(i);
        }
        for (int i = 0; i < Board::NUM_NODES; ++i) {
            n[i] = *Board::board_nodes[i].get();
        }
        for (int i = 0; i < Board::NUM_ROADS; ++i) {
            e[i] = *Board::roads[i].get();
        }
        os<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl;
        os<<"                               " << n[0] << "--" << e[0] << "--" << n[1] << "                                    "<<std::endl;
        os<<"                              /           \\                                  "<<std::endl;
        os<<"                             "<< e[1] <<"      0      "<< e[2] <<"                                  "<<std::endl;
        os << "                            /    " << r[0] << "    \\                                " << std::endl;
        os<<"                  " << n[2] << "--" << e[3] << "--" << n[3] << "       "<<ids[0]<<"       " << n[4] << "--" << e[4] << "--" << n[5] << "                       "<<std::endl;
        os<<"                 /           \\              /           \\                   "<<std::endl;
        os<<"                "<< e[5] <<"      1      "<< e[6] <<"            "<< e[7] <<"      2      "<< e[8] <<"                    "<<std::endl;
        os<<"               /     " << r[1] << "    \\          /     "<< r[2] <<"    \\                 "<<std::endl;
        os<<"     " << n[6] << "--" << e[9] << "--" << n[7] << "       "<<ids[1]<<"        " << n[8] << "--" << e[10] << "-" << n[9] << "        "<<ids[2]<<"      " << n[10] << "--" << e[11] << "-" << n[11] << "        "<<std::endl;
        os<<R"(    /           \              /           \              /           \    )"<<std::endl;
        os<<"  "<< e[12] <<"      3     "<< e[13] <<"           "<< e[14] <<"      4     "<< e[15] <<"           "<< e[16] <<"      5     "<< e[17] <<"      "<<std::endl;
        os<<"  /     "<< r[3] <<"    \\          /     "<< r[4] <<"    \\          /     "<< r[5] <<"    \\  "<<std::endl;
        os<<"" << n[12] << "      "<<ids[3]<<"       " << n[13] << "--" << e[18] << "-" << n[14] << "      "<<ids[4]<<"      " << n[15] << "--" << e[19] << "-" << n[16] << "     "<<ids[5]<<"       " << n[17] << "    "<<std::endl;
        os<<R"(  \              /           \              /           \              /   )"<<std::endl;
        os<<"  "<< e[20] <<"           "<< e[21] <<"      6     "<< e[22] <<"           "<< e[23] <<"      7     "<< e[24] <<"           "<< e[25] <<"       "<<std::endl;
        os<<"    \\          /     "<< r[6] <<"    \\          /     "<< r[7] <<"    \\          /     "<<std::endl;
        os<<"    " << n[18] << "--" << e[26] << "-" << n[19] << "       "<<ids[6]<<"      " << n[20] << "--" << e[27] << "-" << n[21] << "        "<<ids[7]<<"      " << n[22] << "--" << e[28] << "-" << n[23] << "         "<<std::endl;
        os<<R"(    /           \              /           \              /           \    )"<<std::endl;
        os<<"  "<< e[29] <<"      8     "<< e[30] <<"           "<< e[31] <<"     9     "<< e[32] <<"           "<< e[33] <<"     10     "<< e[34] <<"      "<<std::endl;
        os<<"  /     "<< r[8] <<"    \\          /     "<< r[9] <<"    \\          /     "<< r[10] <<"    \\  "<<std::endl;
        os<<"" << n[24] << "      "<<ids[8]<<"       " << n[25] << "--" << e[35] << "-" << n[26] << "      "<<ids[9]<<"      " << n[27] << "--" << e[36] << "-" << n[28] << "     "<<ids[10]<<"       " << n[29] << "    "<<std::endl;
        os<<R"(  \              /           \              /           \              /   )"<<std::endl;
        os<<"  "<< e[37] <<"           "<< e[38] <<"     11     "<< e[39] <<"           "<< e[40] <<"     12     "<< e[41] <<"           "<< e[42] <<"       "<<std::endl;
        os<<"    \\          /     "<< r[11] <<"    \\          /     "<< r[12] <<"    \\          /     "<<std::endl;
        os<<"    " << n[30] << "--" << e[43] << "-" << n[31] << "       "<<ids[11]<<"      " << n[32] << "-44-" << n[33] << "        "<<ids[12]<<"      " << n[34] << "--" << e[45] << "-" << n[35] << "         "<<std::endl;
        os<<R"(    /           \              /           \              /           \     )"<<std::endl;
        os<<"  "<< e[46] <<"     13     "<< e[47] <<"           "<< e[48] <<"     14     "<< e[49] <<"           "<< e[50] <<"     15     "<< e[51] <<"      "<<std::endl;
        os<<"  /     "<< r[13] <<"    \\          /     "<< r[14] <<"    \\          /     "<< r[15] <<"    \\  "<<std::endl;
        os<<"" << n[36] << "      "<<ids[13]<<"       " << n[37] << "--" << e[52] << "-" << n[38] << "      "<<ids[14]<<"      " << n[39] << "--" << e[53] << "-" << n[40] << "       "<<ids[15]<<"       " << n[41] << "    "<<std::endl;
        os<<R"(  \              /           \              /           \              /   )"<<std::endl;
        os<<"  "<< e[54] <<"           "<< e[55] <<"     16     "<< e[56] <<"           "<< e[57] <<"     17     "<< e[58] <<"           "<< e[59] <<"       "<<std::endl;
        os<<"    \\          /     "<< r[16] <<"    \\          /     "<< r[17] <<"    \\          /     "<<std::endl;
        os<<"    " << n[42] << "--" << e[60] << "-" << n[43] << "       "<<ids[16]<<"      " << n[44] << "--" << e[61] << "-" << n[45] << "     "<<ids[17]<<"      " << n[46] << "--" << e[62] << "-" << n[47] << "         "<<std::endl;
        os<<"                \\              /           \\              /                 "<<std::endl;
        os<<"                "<< e[63] <<"           "<< e[64] <<"     18     "<< e[65] <<"           "<< e[66] <<"                    "<<std::endl;
        os<<"                  \\          /     "<< r[18] <<"    \\          /                   "<<std::endl;
        os<<"                  " << n[48] << "--" << e[67] << "-" << n[49] << "      "<<ids[18]<<"       " << n[50] << "--" << e[68] << "-" << n[51] << "                       "<<std::endl;
        os<<"                             \\              /                                "<<std::endl;
        os<<"                             "<< e[69] <<"           "<< e[70] <<"                                  "<<std::endl;
        os<<"                               \\          /                                  "<<std::endl;
        os<<"                               " << n[52] << "--" << e[71] << "-" << n[53] << "                                   "<<std::endl;
//        if(DBG)
//        {
//            os<<std::endl;
//            for (auto p: ) {
//
//            }
//        }
        return os;
    }
}
