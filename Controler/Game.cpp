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
        // Logic to start a player's turn
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

    void Game::buildSettlement(int playerId, int tileId, int nodeId) {
        if (canBuildSettlement(playerId, tileId, nodeId)) {
            // Deduct resources from the player
            auto player = players[playerId];
            player->deductResourcesForSettlement();

            // Create and place the settlement
            //model::Node::setNodeStatus(NodeStatus::SETTLEMENT);
            auto settlement = model::Board::getSettlement(nodeId);
            settlement->setNodeStatus(NodeStatus::SETTLEMENT);
            // Update player's settlements
            player->addSettlement(settlement);

            std::cout << "Settlement built successfully!" << std::endl;
        } else {
            std::cerr << "Cannot build settlement at the specified location." << std::endl;
        }
    }

    void Game::buildRoad(int roadId) {
        auto p = getCurrentPlayer();
        p->addRoad(board.getRoad(roadId));
    }

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

    bool Game::canBuildSettlement(int playerId, int tileId, int nodeId) const {
        const auto& tile = model::Board::getTile(tileId);
        const auto& node = model::Board::getSettlement(nodeId);

        // Check if the node is already occupied
        if (node->isOccupied()) {
            return false;
        }

        // Check the proximity rule (no adjacent settlements)
        for (const auto& adjacentNode : model::Board::getAdjacentNodes((const shared_ptr<model::Node> &) node)) {
            if (adjacentNode->isOccupied()) {
                return false;
            }
        }

        // Check if the player has enough resources
        auto player = players[playerId];
        if (!player->hasResoursesForNewSettlement()) {
            return false;
        }

        // Check if the player has an adjacent road (except during initial placement)
        if (!player->hasAdjacentRoad(nodeId) && !isInitialPlacementPhase()) {
            return false;
        }


        return true;
    }

    bool Game::isInitialPlacementPhase() const {
        return InitialPlacementPhase;
    }

    void Game::addPlayer(const std::string& name, int id) {
        shared_ptr<Player> p = std::make_shared<Player>(name, id);
        players.push_back(p);
    }

    void Game::InitialPlacement(int indx) {
        currentPlayerIndex = indx;
        auto p = players[indx];

        std::cout << "Player: " << p->getName() << " choose a node for your settlement" << std::endl;
        int n;
        std::cin >> n;
        // TODO check is available & distance
        auto s = model::Board::getSettlement(n);
        p->addSettlement(s);
        std::cout << board << std::endl;
        auto adj_roads = model::Board::getAvailableAdjacentRoads(s);

        std::cout << "Player: " << p->getName() << " choose a road" << std::endl;
        std::cout << "You can build a new road in: " << std::endl;
        printAvailableRoads(adj_roads);

//        for (int i = 0; i < int(adj_roads.size()); ++i) {
//            std::cout << i + 1 << ") Edge-"<<adj_roads[i]->getId() << std::endl;
//        }
        int length = int(adj_roads.size());
        cout << "Please Enter a number between 1 to " << length << endl;
        std::cin >> n;
        while (n <= 0 || n > length){
            cout << "Invalid choice. Please Enter a number between 1 to " << length << endl;
            printAvailableRoads(adj_roads);
            std::cin >> n;
        }
//        if(n < 0 || n > length){
//            cout << "Invalid choice. Please Enter a number between 1 to " << length << endl;
//            printAvailableRoads(adj_roads);
//        }
        buildRoad(adj_roads[n-1]->getId());
        std::cout << board << std::endl;
    }

    void Game::endOfInitialPlacement() {
        InitialPlacementPhase = false;
    }

    void Game::buildRoadHelper(int r_indx) {
        auto s = model::Board::getSettlement(43);
        auto adj_roads = model::Board::getAdjacentRoads(s);
        std::cout << "You can build a new road in: " << model::Board::roadsListToString(adj_roads) << std::endl;
    }

    void Game::printAvailableRoads(vector<shared_ptr<Road>> &road_list) {
        std::cout << "You can build a new road in: " << std::endl;
        for (int i = 0; i < int(road_list.size()); ++i) {
            std::cout << i + 1 << ") Edge-"<<road_list[i]->getId() << std::endl;
        }
    }


}
