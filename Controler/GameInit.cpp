//
// Created by SAGIT on 22/06/2024.
//

#include "GameInit.hpp"
#include "../Model/Board.hpp"
#include "GameActions.hpp"


#include <iostream>


using std::cout, std::cin, std::endl;

namespace model
{
    void GameInit::start(model::GameController &game) {
        // Initialize board, decks, and players
        initializePlayers(game);
        model::Board::initializeBoard();
//        resourceCardDeck.resetDeck();
//        developmentCardDeck.resetDeck();
    }
    void GameInit::initializePlayers(model::GameController &game) {
        std::string name;
        cout << "Welcome yo! \n1st player! Enter your name: " << endl;
//    cin >> name;
        cout << "Sagit" << endl;
        name = "Sagit";
        GameInit::addPlayer(name, 1);
        name.clear();

        cout << "2nd player: Enter your name" << endl;
        cout << "Kfir" << endl;
        name = "Kfir";
//    cin >> name;
        GameInit::addPlayer(name, 2);
        name.clear();

        cout << "3rd player: Enter your name" << endl;
        cout << "Mimi" << endl;
        name = "Mimi";
//    cin >> name;
        GameInit::addPlayer(name, 3);
    }

    model::Board initBoard(model::GameController &game){
        cout << "Welcome brave players!" << endl;
        for (auto &p: Board::getPlayers()) {
            cout << "Player" << p->getId() << ": " << p->getName() << "." << endl;
        }
        model::Board board;

        std::cout << board << std::endl;
//    model::Game::buildRoadHelper(31);
        if(model::FAST_START){
            GameInit::FastInitialPlacement();
        }else{
            for (int i = 0; i < 3; ++i) {
                GameInit::InitialPlacement(i);
            }
            for (int i = 2; i >= 0; --i) {
                GameInit::InitialPlacement(i);
            }
        }
        std::cout << board << std::endl;
//        GameInit::endOfInitialPlacement();
        return board;
    }


    void GameInit::FastInitialPlacement()
    {
        auto players = Board::getPlayers();
        auto p = players[0];
        auto s = Board::getNode(30);
        p->addSettlement(s);
        s = model::Board::getNode(40);
        p->addSettlement(s);
        s = model::Board::getNode(25);
        p->addSettlement(s);
        p->addRoad(Board::getRoad(43));
        p->addRoad(Board::getRoad(38));
        p->addRoad(Board::getRoad(53));


        p = players[1];
        s = model::Board::getNode(37);
        p->addSettlement(s);
        s = model::Board::getNode(33);
        p->addSettlement(s);

        p->addRoad(Board::getRoad(52));
        p->addRoad(Board::getRoad(49));



        p = players[2];
        s = model::Board::getNode(45);
        p->addSettlement(s);
        s = model::Board::getNode(52);
        p->addSettlement(s);
        s = model::Board::getNode(28);
        p->addSettlement(s);
        s = model::Board::getNode(9);
        p->addSettlement(s);
        s = model::Board::getNode(16);
        p->addSettlement(s);
        s = model::Board::getNode(5);
        p->addSettlement(s);

        p->addRoad(Board::getRoad(4));
        p->addRoad(Board::getRoad(7));
        p->addRoad(Board::getRoad(57));
        p->addRoad(Board::getRoad(61));
        p->addRoad(Board::getRoad(64));
        p->addRoad(Board::getRoad(71));


//        buildRoad(adj_roads[n-1]->getId());
    }

    void GameInit::InitialPlacement(int indx) {
        currentPlayerIndex = indx;
        auto p = players[indx];
        model::GameController.getCurrentPlayer

        std::cout << "Player: " << p->getName() << " choose a node for your settlement" << std::endl;
        int n;
        std::cin >> n;

        while (n < 0 || n > 53 || !canBuildSettlement(indx, n)){
            if (!canBuildSettlement(indx, n)) {
                cout << "Node " << n << " is occupied or blocked. Try again" << endl;
            }else{
                cout << "Invalid choice. Please Enter a number between 0 to 53" << endl;
            }
            cin >> n;
        }

        // TODO check is available & distance
        auto s = model::Board::getNode(n);
        blockAdjNodes(s);
        p->addSettlement(s);
        std::cout << board << std::endl;
        auto adj_roads = model::Board::getAvailableAdjacentRoads(s);

        std::cout << "Player: " << p->getName() << " choose a road" << std::endl;
        std::cout << "You can build a new road in: " << std::endl;
        printAvailableRoads(adj_roads);


        int length = int(adj_roads.size());
        cout << "Please Enter a number between 1 to " << length << endl;
        std::cin >> n;
        while (n <= 0 || n > length){
            cout << "Invalid choice. Please Enter a number between 1 to " << length << endl;
            printAvailableRoads(adj_roads);
            std::cin >> n;
        }

        p->addRoad(board.getRoad(n));

        std::cout << board << std::endl;
    }

}