

#include <iostream>
#include <string>

#include "Model/Board.hpp"
#include "Controler/GameController.hpp"
#include "Controler/PlayerManagement.hpp"
#include "Controler/GameInit.hpp"
#include "Model/Constants.hpp"

using std::cout;
using std::endl;
using std::cin;

//void welcome(model::GameController &game) {
//    std::string name;
//    cout << "Welcome yo! \n1st player! Enter your name: " << endl;
////    cin >> name;
//    cout << "Sagit" << endl;
//    name = "Sagit";
//    game.addPlayer(name, 1);
//    name.clear();
//
//    cout << "2nd player: Enter your name" << endl;
//    cout << "Kfir" << endl;
//    name = "Kfir";
////    cin >> name;
//    game.addPlayer(name, 2);
//    name.clear();
//
//    cout << "3rd player: Enter your name" << endl;
//    cout << "Mimi" << endl;
//    name = "Mimi";
////    cin >> name;
//    game.addPlayer(name, 3);
//}



int main() {
    model::GameController game;

    model::GameInit::start(game);
    model::Board board =  initBoard(game);
    while (true)
    {
        game.
    }
    game.startTurn();
    std::cout << board << endl;



//    model::Board::printTileNodes(0);
//    model::Board::printTileRoads(0);
    //std::cout << board << std::endl;
    return 0;
}

