#include "Game.hpp"

using std::cout, std::cin, std::endl;
namespace model {

    Game::Game()
            : currentPlayerIndex(0), gameOver(false), winner(nullptr) {
        initializeGame();
    }

    void Game::initializeGame() {
        // Initialize board, decks, and players
        model::Board::initializeBoard();
        resourceCardDeck.resetDeck();
        developmentCardDeck.resetDeck();
    }
/**
 * TO DO:
 * in controller call addPlayer
 * */
    void Game::addPlayer(const std::shared_ptr<Player>& player) {
        players.push_back(player);
    }

    const std::vector<std::shared_ptr<Player>>& Game::getPlayers() const {
        return players;
    }
/**
 *
 *
 * */
    void Game::startTurn() {
//        auto player = getCurrentPlayer();
//        cout << player->getName() << "'s turn" << endl;
//        int option = 0;
//        cout << "What would you like to do?" << endl;
//        cout << "1) "
//        cin >> option;
//        switch (option) {
//            case 1:
//
//        }

    }

    void Game::endTurn() {
        // Logic to end the current player's turn and move to the next player
        currentPlayerIndex = (currentPlayerIndex + 1) % int(players.size());
    }

    const std::shared_ptr<Player>& Game::getCurrentPlayer() const {
        return players[currentPlayerIndex];
    }

    void Game::rollDice() {
        // Logic to roll the dice and distribute resources
    }

//    void Game::buildSettlement(int playerId, int nodeId) {
//        if (canBuildSettlement(playerId, nodeId)) {
//            // Deduct resources from the player
//            auto player = players[playerId];
//            player->deductResourcesForSettlement();
//
//            // Create and place the settlement
//            //model::Node::setNodeStatus(NodeStatus::SETTLEMENT);
//            auto settlement = model::Board::getNode(nodeId);
//            settlement->setNodeStatus(NodeStatus::SETTLEMENT);
//            // Update player's settlements
//            player->addSettlement(settlement);
//
//            std::cout << "Settlement built successfully!" << std::endl;
//        } else {
//            std::cerr << "Cannot build settlement at the specified location." << std::endl;
//        }
//    }

    void Game::tradeResources(int fromPlayerId, int toPlayerId, Resource give, Resource receive) {
        // Logic to trade resources between players
    }

    void Game::buyDevelopmentCard(int playerId) {
        // Logic to allow a player to buy a development card
    }

    bool Game::isGameOver() const {
        return gameOver;
    }

    const std::shared_ptr<Player>& Game::getWinner() const {
        return winner;
    }

    void Game::determineWinner() {
        // Logic to determine the winner based on game rules
    }

    void Game::distributeResources(int rollResult) {
        // Logic to distribute resources based on the roll result
    }

    bool Game::canBuildSettlement(int playerId, int nodeId) const {
        //const auto& tile = model::Board::getTile(tileId);
        const auto& node = model::Board::getNode(nodeId);

        // Check if the node is already occupied
        if (!node->isAvailable()) {
            return false;
        }

        // Check the proximity rule (no adjacent settlements)
//        for (const auto& adjacentNode : model::Board::getAdjacentNodes(node)) {
//            if (!adjacentNode->isAvailable()) {
//                return false;
//            }
//        }

        // Check if the player has enough resources
//        auto player = players[playerId];
//        if (!player->hasResoursesForNewSettlement()) {
//            return false;
//        }
//
//        // Check if the player has an adjacent road (except during initial placement)
//        if (!player->hasAdjacentRoad(nodeId) && !isInitialPlacementPhase()) {
//            return false;
//        }


        return true;
    }

    bool Game::isInitialPlacementPhase() const {
        return InitialPlacementPhase;
    }

    void Game::addPlayer(const std::string& name, int id) {
        shared_ptr<Player> p = std::make_shared<Player>(name, id);
        players.push_back(p);
    }

    void Game::FastInitialPlacement(){
        auto p = players[0];
        auto s = model::Board::getNode(30);
        p->addSettlement(s);
        s = model::Board::getNode(40);
        p->addSettlement(s);
        s = model::Board::getNode(25);
        p->addSettlement(s);

        p->addRoad(board.getRoad(43));
        p->addRoad(board.getRoad(38));
        p->addRoad(board.getRoad(53));


        p = players[1];
        s = model::Board::getNode(37);
        p->addSettlement(s);
        s = model::Board::getNode(33);
        p->addSettlement(s);

        p->addRoad(board.getRoad(52));
        p->addRoad(board.getRoad(49));



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

        p->addRoad(board.getRoad(4));
        p->addRoad(board.getRoad(7));
        p->addRoad(board.getRoad(57));
        p->addRoad(board.getRoad(61));
        p->addRoad(board.getRoad(64));
        p->addRoad(board.getRoad(71));


//        buildRoad(adj_roads[n-1]->getId());
    }

    void Game::InitialPlacement(int indx) {
        currentPlayerIndex = indx;
        auto p = players[indx];

        std::cout << "Player: " << p->getName() << " choose a node for your settlement" << std::endl;
        int n;
        std::cin >> n;
        int a = 1;
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

    void Game::endOfInitialPlacement() {
        InitialPlacementPhase = false;
    }


    void Game::printAvailableRoads(vector<shared_ptr<Road>> &road_list) {
        std::cout << "You can build a new road in: " << std::endl;
        for (int i = 0; i < int(road_list.size()); ++i) {
            std::cout << i + 1 << ") Edge-"<<road_list[i]->getId() << std::endl;
        }
    }

    void Game::blockAdjNodes(shared_ptr<Node>& node) {
        auto adj_nodes = model::Board::getAdjacentNodes(node);
        for(const auto& n : adj_nodes){
            n->setNodeStatus(NodeStatus::BLOCKED);
        }

    }


}
