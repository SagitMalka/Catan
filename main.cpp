// sagitmalka10@gmail.com


#include <iostream>
#include <string>

#include "Model/Board.hpp"
#include "Controler/Game.hpp"
#include "Model/Constants.hpp"

using std::cout;
using std::endl;
using std::cin;

void welcome(model::Game &game) {
    std::string name;
    cout << "Welcome yo! \n1st player! Enter your name: " << endl;
//    cin >> name;
    cout << "Sagit" << endl;
    name = "Sagit";
    game.addPlayer(name, 1);
    name.clear();

    cout << "2nd player: Enter your name" << endl;
    cout << "Kfir" << endl;
    name = "Kfir";
//    cin >> name;
    game.addPlayer(name, 2);
    name.clear();

    cout << "3rd player: Enter your name" << endl;
    cout << "Mimi" << endl;
    name = "Mimi";
//    cin >> name;
    game.addPlayer(name, 3);
}

model::Board initBoard(model::Game &game){
    cout << "Welcome brave players!" << endl;
    for (auto &p: game.getPlayers()) {
        cout << "Player" << p->getId() << ": " << p->getName() << "." << endl;
    }
    model::Board board;

    std::cout << board << std::endl;
//    model::Game::buildRoadHelper(31);
    if(model::FAST_START){
        game.FastInitialPlacement();
    }else{
        for (int i = 0; i < 3; ++i) {
            game.InitialPlacement(i);
        }
        for (int i = 2; i >= 0; --i) {
            game.InitialPlacement(i);
        }
    }
    std::cout << board << std::endl;
    game.endOfInitialPlacement();
    return board;
}

int main() {
    model::Game game;
    welcome(game);
    model::Board board =  initBoard(game);

    while(true)
    {
        game.startTurn();

        shared_ptr<model::Player> winner = nullptr;
        int player_with_longest_road = game.getPlayerWithLongestRoad();
        for(const auto& p: game.getPlayers()){
            int score = p->getScore();
            if(p->getId() == player_with_longest_road){
                score += 2;
            }
            cout << p->getName() << " has " << score << "Points" << endl;
            if (score >= WINNING_SCORE){
                winner = p;
            }
        }
        if (winner != nullptr){
            cout << winner->getName() << " Has Won The Game!!" << endl;
            return 0;
        }
        game.endTurn();
    }

}

