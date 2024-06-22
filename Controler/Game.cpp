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
    void Game::addPlayer(const std::shared_ptr<Player> &player) {
        players.push_back(player);
    }

    const std::vector<std::shared_ptr<Player>> &Game::getPlayers() const {
        return players;
    }

/**
 *
 *
 * */

    int getUserChoice(size_t options_size) {
        int choice = 0;

        while (true) {
            std::cout << "Enter the number corresponding to your choice: ";
            std::cin >> choice;

            if (choice > 0 && choice <= options_size) {
                return choice;
            } else {
                std::cout << "Invalid choice. Please select a number between 1 and " << options_size << ".\n";
            }
        }
    }

    void Game::tryBuildRoad(const shared_ptr<Player> &player) {
        vector<shared_ptr<Road>> edges;
        int road_index = -1;
        if (player->hasResourcesForRoad()) {
            cout << "choose your new road" << endl;
            edges = availableRoadsToBuild();
            printAvailableRoads(edges);
            road_index = getUserChoice(edges.size());
            player->addRoad(board.getRoad(road_index));
        } else {
            cout << "You do not have enough resources." << endl;
        }
    }

    void Game::printAvailableNodes(vector<shared_ptr<Node>> &node_list) {
        std::cout << "You can chooseWhatToBuild a new settlement in: " << std::endl;
        for (int i = 0; i < int(node_list.size()); ++i) {
            std::cout << i + 1 << ") Edge-" << node_list[i]->getId() << std::endl;
        }
    }

    void Game::tryBuildSettlement(const shared_ptr<Player> &player) {
        if (player->hasResourcesForNewSettlement()) {
            cout << "choose your new settlement" << endl;
            vector<shared_ptr<Node>> available_nodes = availableSettlementToBuild();
            int node_index = -1;
            printAvailableNodes(available_nodes);
            node_index = getUserChoice(available_nodes.size());;
            player->addSettlement(Board::getNode(node_index));
        } else {
            cout << "You do not have enough resources." << endl;
        }
    }

    vector<shared_ptr<Node>> Game::availableSettlementToBuild() const {
        auto p = getCurrentPlayer();
        vector<shared_ptr<Node>> can_build;
        for (const auto &road: p->getPlayerRoads()) {
            for (int i = 1; i < 3; ++i) {
                auto node_i = road->getNodeOfRoad(i);
                if (node_i->isAvailable()) {
                    can_build.push_back(node_i);
                }
            }
        }
        return can_build;
    }

    void Game::chooseWhatToBuild(const std::shared_ptr<Player> &player) {
        cout <<
             "1) Build road" << endl <<
             "2) Build settlement" << endl <<
             "3) Build City" << endl <<
             "4) cancel" << endl;

        int sub_option = getUserChoice(4);

        switch (sub_option) {
            case 1:  // ROAD
                tryBuildRoad(player);
                break;
            case 2: // SETTLEMENT
                tryBuildSettlement(player);
                break;
            case 3:
                cout << "Implement here" << endl;
                break;
            case 4:
                cout << "Build canceled.." << endl;
                break;
            default:
                cout << "Invalid choice. Please select a number between 1 and 3." << endl;
                break;
        }
    }

    bool Game::chooseWhatToDo(const shared_ptr<Player> &player) {
        int option = 0, sub_option = 0;
        cout <<
             "1) Build (road/settlement/city)" << endl <<
             "2) Trade" << endl <<
             "3) Buy a development card" << endl <<
             "4) Use a development card" << endl <<
             "5) Finish Turn" << endl;

        option = getUserChoice(5);

        switch (option) {
            case 1:
                chooseWhatToBuild(player);
                return true;
            case 2:
                // TODO method to trade
                return true;
            case 3:
                //TODO check if player has enough resource cards
                if (buyDevelopmentCard() != 0) {
                    cout << "Sorry no more development cards or no money" << endl;
                }
                return true;
            case 4:
                //TODO check if it's cards are useful
                return true;
            case 5:
                return false;
            default:
                cout << "Invalid choice." << endl;
                return true;
        }
    }

    void Game::startTurn() {
        auto player = getCurrentPlayer();
        cout << player->getName() << "'s turn" << endl;

        cout << "What would you like to do?" << endl;
        bool resume = true;
        while (resume) {
            resume = chooseWhatToDo(player);
        }
    }

    void Game::endTurn() {
        // Logic to end the current player's turn and move to the next player
        currentPlayerIndex = (currentPlayerIndex + 1) % int(players.size());
    }

    const std::shared_ptr<Player> &Game::getCurrentPlayer() const {
        return players[currentPlayerIndex];
    }

    void Game::rollDice() {
        // Logic to roll the dice and distribute resources
    }


    void Game::tradeResources(int fromPlayerId, int toPlayerId, Resource give, Resource receive) {
        // Logic to trade resources between players
    }

    int Game::buyDevelopmentCard() {
        if (!developmentCardDeck.isEmpty()) {
            auto p = getCurrentPlayer();
            if (p->hasResourcesForDevCard()) {
                auto dev_card = developmentCardDeck.drawCard();
                p->addDevelopmentCard(dev_card);
                cout << "You've got " << dev_card.toString();
                return 0;
            } else {
                return 1;
            }
        }
        return 2;
    }

    bool Game::isGameOver() const {
        return gameOver;
    }

    const std::shared_ptr<Player> &Game::getWinner() const {
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
        const auto &node = model::Board::getNode(nodeId);

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
//        if (!player->hasResourcesForNewSettlement()) {
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

    void Game::addPlayer(const std::string &name, int id) {
        shared_ptr<Player> p = std::make_shared<Player>(name, id);
        players.push_back(p);
    }

    void Game::FastInitialPlacement() {
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
        p->addResourceCard(Resource::Wood);
        p->addResourceCard(Resource::Wood);
        p->addResourceCard(Resource::Wood);
        p->addResourceCard(Resource::Brick);
        p->addResourceCard(Resource::Brick);
        p->addResourceCard(Resource::Ore);
        p->addResourceCard(Resource::Ore);
        p->addResourceCard(Resource::Ore);
        p->addResourceCard(Resource::Sheep);

        p = players[1];
        s = model::Board::getNode(37);
        p->addSettlement(s);
        s = model::Board::getNode(33);
        p->addSettlement(s);

        p->addRoad(board.getRoad(52));
        p->addRoad(board.getRoad(49));
        p->addResourceCard(Resource::Wood);
        p->addResourceCard(Resource::Wood);
        p->addResourceCard(Resource::Wood);
        p->addResourceCard(Resource::Brick);
        p->addResourceCard(Resource::Brick);
        p->addResourceCard(Resource::Ore);
        p->addResourceCard(Resource::Ore);
        p->addResourceCard(Resource::Ore);
        p->addResourceCard(Resource::Sheep);

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
        p->addResourceCard(Resource::Wood);
        p->addResourceCard(Resource::Wood);
        p->addResourceCard(Resource::Wood);
        p->addResourceCard(Resource::Brick);
        p->addResourceCard(Resource::Brick);
        p->addResourceCard(Resource::Ore);
        p->addResourceCard(Resource::Ore);
        p->addResourceCard(Resource::Ore);
        p->addResourceCard(Resource::Sheep);


//        buildRoad(adj_roads[n-1]->getId());
    }

    void Game::InitialPlacement(int indx) {
        currentPlayerIndex = indx;
        auto p = players[indx];

        std::cout << "Player: " << p->getName() << " choose a node for your settlement" << std::endl;
        int n;
        std::cin >> n;
        int a = 1;
        while (n < 0 || n > 53 || !canBuildSettlement(indx, n)) {
            if (!canBuildSettlement(indx, n)) {
                cout << "Node " << n << " is occupied or blocked. Try again" << endl;
            } else {
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
        std::cout << "You can chooseWhatToBuild a new road in: " << std::endl;
        printAvailableRoads(adj_roads);


        int length = int(adj_roads.size());
        cout << "Please Enter a number between 1 to " << length << endl;
        std::cin >> n;
        while (n <= 0 || n > length) {
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
        std::cout << "You can chooseWhatToBuild a new road in: " << std::endl;
        for (int i = 0; i < int(road_list.size()); ++i) {
            std::cout << i + 1 << ") Edge-" << road_list[i]->getId() << std::endl;
        }
    }

    void Game::blockAdjNodes(shared_ptr<Node> &node) {
        auto adj_nodes = model::Board::getAdjacentNodes(node);
        for (const auto &n: adj_nodes) {
            n->setNodeStatus(NodeStatus::BLOCKED);
        }

    }

    vector<shared_ptr<Road>> Game::availableRoadsToBuild() const {
        auto p = getCurrentPlayer();
        vector<shared_ptr<Road>> can_build;
        for (const auto &node: p->getPlayerSettlements()) {
            // TODO get nodes by road and not by node. example if u have edge 22 you can build 14, 18, 31, 27
            auto adj_nodes = model::Board::getAvailableAdjacentRoads(node);
            for (const auto &n: adj_nodes) {
                can_build.push_back(n);
            }
        }
        return can_build;
    }


}
