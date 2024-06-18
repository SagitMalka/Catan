

#include <iostream>

#include "Model/Board.hpp"


int main(){

    model::Board board;
    std::cout << board << std::endl;
    model::Board::printTileNodes(0);
    model::Board::printTileRoads(0);
    //std::cout << board << std::endl;
    return 0;
}

