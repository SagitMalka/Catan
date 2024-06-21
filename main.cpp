

#include <iostream>
#include <string>

#include "Model/Board.hpp"
#include "Model/Game.hpp"


using std::cout;
using std::endl;
using std::cin;

void welcome(model::Game &game){
    std::string name;
    cout << "Welcome yo! \n1st player: Enter your name" << endl;
    cin >> name;
    game.addPlayer(name, 1);
    name.clear();

    cout << "2nd player: Enter your name" <<endl;
    cin >> name;
    game.addPlayer(name, 2);
    name.clear();

    cout << "3rd player: Enter your name" <<endl;
    cin >> name;
    game.addPlayer(name, 3);
}
int main(){
    model::Game game;
    welcome(game);
    auto plyrs = game.getPlayers();
    for(auto &p : plyrs){
        cout << p->getPlayerName(reinterpret_cast<const model::Player &>(p)) << " has joined!" << endl;
    }
//    model::Board board;
//    std::cout << board << std::endl;
//    model::Board::printTileNodes(0);
//    model::Board::printTileRoads(0);
    //std::cout << board << std::endl;
    return 0;
}

