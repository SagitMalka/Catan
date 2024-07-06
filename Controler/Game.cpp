#include "Game.hpp"
#include <cstdlib> // for std::rand and std::srand
#include <ctime> // for std::time
#include <string>

 namespace model{

 
using std::cout, std::cin, std::endl, std::srand, std::string, std::out_of_range,
        std::numeric_limits, std::streamsize, std::map, std::to_string, std::make_shared;

    string ResourceToString(Resource resource) {
        switch (resource) {
            case Resource::Wood:
                return "Wood";
            case Resource::Brick:
                return "Brick";
            case Resource::Sheep:
                return "Sheep";
            case Resource::Wheat:
                return "Wheat";
            case Resource::Ore:
                return "Ore";
            case Resource::Desert:
                return "Desert";
            default:
                return "Unknown Resource";
        }
    }

    void pressAnyKeyToContinue() {
        cout << "Press Enter to continue..." << endl;
        cin.get();
    }

    int displayMenu(const string &msg, const vector<string> &options) {
        int choice = -1;

        // Display menu options
        cout << WHITE_BACKGROUND << BLACK << BOLD_TEXT << msg << ":" << RESET << endl;
        for (size_t i = 0; i < options.size(); ++i) {
            cout << WHITE_BACKGROUND << BLACK << i + 1 << ")" << " " << options[i] << "\n";
        }
        cout << BOLD_TEXT << "Enter your choice (1-" << options.size() << "): " << endl << RESET;
        cin >> choice;

        // Validate user input
        while (choice < 1 || choice > static_cast<int>(options.size())) {
            cout << "Invalid choice. Please enter a number between 1 and " << options.size() << ": ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
        }
        if (choice == options.size())
            return -1;
        else
            return choice - 1;
    }


    Game::Game()
            : currentPlayerIndex(0), gameOver(false), winner(nullptr) {
        initializeGame();
    }

    void Game::initializeGame() {
        // Initialize board, decks, and players
        model::Board::initializeBoard();

        developmentCardDeck.resetDeck();

        srand(static_cast<unsigned int>(time(nullptr)));
    }


    void Game::addPlayer(const shared_ptr<Player> &player) {
        players.push_back(player);
    }

    const vector<shared_ptr<Player>> &Game::getPlayers() const {
        return players;
    }

/**
 *
 *
 * */

    void Game::payForPurchase(map<Resource, int> price, const shared_ptr<Player> &player) {
        player->payResources(price);

        resources_cards[Resource::Wood] += price.at(Resource::Wood);
        resources_cards[Resource::Wheat] += price.at(Resource::Wheat);
        resources_cards[Resource::Ore] += price.at(Resource::Ore);
        resources_cards[Resource::Sheep] += price.at(Resource::Sheep);
        resources_cards[Resource::Brick] += price.at(Resource::Brick);
    }

//    void Game::payForSettlement() { payResources(SETTLEMENT_COST); }

    void Game::roadBuildMenu(const shared_ptr<Player> &player) {
        vector<shared_ptr<Road>> edges;
        if (player->hasResourcesForRoad()) {
            edges = availableRoadsToBuild();

            vector<string> edges_str;
            for (const auto &e: edges) {
                edges_str.push_back("Road-" + to_string(e->getId()));
            }
            edges_str.push_back("Cancel.");

            int user_choice = displayMenu("Which road would you like to build?", edges_str);
            if (user_choice == CANCEL) return;

            auto r = board.getRoad(edges[user_choice]->getId());
            player->addRoad(r);
            std::cout << "Congratulations! You have built road -- " << r->getId() << " -- !." << std::endl;

            payForPurchase(ROAD_COST, player);
        } else {
            cout << "You do not have enough resources." << endl;
        }
    }

    void Game::settlementBuildMenu(const shared_ptr<Player> &player) {
        vector<string> nodes_str;

        if (player->hasResourcesForNewSettlement()) {
            vector<shared_ptr<Node>> available_nodes = availableSettlementToBuild();
            for (const auto &n: available_nodes) {
                nodes_str.push_back("Node-" + to_string(n->getId()));
            }
            nodes_str.emplace_back("Cancel.");
            int user_choice = displayMenu("Which settlement would you like to build?", nodes_str);
            if (user_choice == CANCEL) return;

            auto n = board.getNode(available_nodes[user_choice]->getId());
            player->addSettlement(n);
            std::cout << "Congratulations! You have built a new Settlement -- " << n->getId() << " -- !." << std::endl;

            payForPurchase(SETTLEMENT_COST, player);
        } else {
            cout << "You do not have enough resources." << endl;
        }
    }

    void Game::cityBuildMenu(const shared_ptr<Player> &player) {
        vector<string> nodes_str;
        if (player->hasResourcesForCity()) {
            vector<shared_ptr<Node>> available_nodes = player->getPlayerSettlements();
            for (const auto &n: available_nodes) {
                nodes_str.push_back("Node-" + to_string(n->getId()));
            }
            nodes_str.emplace_back("Cancel.");
            int user_choice = displayMenu("Which settlement would you like to upgrade to a city?", nodes_str);
            if (user_choice == CANCEL) return;

            auto n = board.getNode(available_nodes[user_choice]->getId());
            player->addCity(n);
            std::cout << "Congratulations! You have a new City -- " << n->getId() << " -- !." << std::endl;

            payForPurchase(CITY_COST, player);
        } else {
            cout << "You do not have enough resources." << endl;
        }
    }

    bool Game::canSettlementBeBuilt(const shared_ptr<Node> &node) const {
        if (node->isAvailable()) {
            for (auto &r: board.getAdjacentRoads(node)) {
                if (!r->getOtherNode(node)->isAvailable()) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    vector<shared_ptr<Node>> Game::availableSettlementToBuild() const {
        auto p = getCurrentPlayer();
        std::set<shared_ptr<Node>> candidates = {};
        vector<shared_ptr<Node>> can_build;
        for (const auto &road: p->getPlayerRoads()) {
            for (const auto &node: road->getNodes()) {
                candidates.insert(node);
            }
        }
        for (const auto &node: candidates) {
            if (canSettlementBeBuilt(node)) {
                can_build.push_back(node);
            }
        }
        return can_build;
    }

    void Game::buildMenu(const shared_ptr<Player> &player) {
        int option = displayMenu(
                "⚒\uFE0FWhat grand construction will you undertake?⚒\uFE0F",
                {
                        "Lay down a road!",
                        "Build a new settlement",
                        "Upgrade to a city",
                        "Changed my mind (Cancel)",
                });

        switch (option) {
            case -1:
                cout << "Build canceled.." << endl;
                break;
            case 0:  // ROAD
                roadBuildMenu(player);
                break;
            case 1: // SETTLEMENT
                settlementBuildMenu(player);
                break;
            case 2:
                cityBuildMenu(player);
                break;
            default:
                cout << "Invalid choice. Please select a number between 1 and 3." << endl;
                break;
        }
    }


    void Game::tradeMenu(const shared_ptr<Player> &player){
        vector<string> trade_list;
        vector<shared_ptr<Player>> trade_players;
        trade_list.push_back("Bank");

        for(const auto& p: players){
            if (p->getId() != player->getId()){
                trade_list.push_back(p->getName());
                trade_players.push_back(p);
            }
        }
        Resource resource_give, resource_take;
        int player_choice = displayMenu( "Who would you like to trade with", trade_list);
        if (player_choice == CANCEL) return;
        if (player_choice == 0){
            cout << "You are now trading with bank! the rate is 4 to 1." << endl;
            int take = displayMenu("What resource do you want?", RESOURCES_STR);
            resource_take = RESOURCES[take];

            if (resources_cards[resource_take]< 1){
                cout << "Trade fail, you need more than 4 for that trade but you only have " << player->getResourceCount(resource_take) << "." << endl;
            }else{
                int give = displayMenu("What resource can you give in return?",RESOURCES_STR);
                resource_give = RESOURCES[give];
                if(player->getResourceCount(resource_give) < 4){
                    cout << "Trade fail, Bank dont have this resource left." << endl;
                }else{
                    resources_cards[resource_give] += 4;
                    resources_cards[resource_take] -= 1;
                    player->addResourceCard(resource_take);
                    player->loseResourceCard(resource_give, 4);
                }
            }
        }
        else{
            auto trade_player = trade_players[player_choice-1];

            cout << "Your resources:" <<endl;
            player->showCards();
            cout << trade_player->getName() << " resources:" <<endl;
            trade_player->showCards();

            int take = displayMenu("What resource do you want?", RESOURCES_STR);
            resource_take = RESOURCES[take];
            cout << "How much do you need?" << endl;
            int amount_take;
            cin >> amount_take;
            if (trade_player->getResourceCount(resource_take) < amount_take){
                cout << "Trade fail, " << trade_player->getName() << " dont have this resource left." << endl;

            }else{
                int give = displayMenu("What resource can you give in return?", RESOURCES_STR);
                resource_give = RESOURCES[give];
                cout << "And how much would you give?" << endl;
                int amount_give;
                cin >> amount_give;
                if(resources_cards[resource_give] < amount_give){
                    cout << "Trade fail, you dont have this resource left." << endl;
                }else{
                    player->addResourceCard(resource_take, amount_take);
                    player->loseResourceCard(resource_give, amount_give);
                    trade_player->addResourceCard(resource_give, amount_give);
                    trade_player->loseResourceCard(resource_take, amount_take);
                    cout << "Your resources:" <<endl;
                    player->showCards();
                    cout << trade_player->getName() << " resources:" <<endl;
                    trade_player->showCards();
                }
            }
        }


    }
    bool Game::actionMenu(const shared_ptr<Player> &player) {
        int option = displayMenu(
                "What's your next move, brave settler?",
                {
                        "Show my resources",
                        "Show board",
                        "Build something (road/settlement/city) ⚒\uFE0F",
                        "Trade",
                        "End your turn "
                });
        bool resume = true;
        switch (option) {
            case -1:
                resume = false;
                break;
            case 0:
                player->showCards();
                break;
            case 1:
                cout << board << endl;
                break;
            case 2:
                buildMenu(player);
                break;
            case 3:
                tradeMenu(player);
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
        return resume;
    }

    void Game::startTurn() {
        cout << endl << endl << endl << board << endl;
        auto player = getCurrentPlayer();
        string name = player->getName();
        cout << name << "'s turn" << endl << "This is your cards:" << endl;
        player->showCards();
        pressAnyKeyToContinue();
        rollDice(name);

        bool resume = true;
        while (resume) {
            resume = actionMenu(player);
        }
    }

    void Game::endTurn() {
        currentPlayerIndex = (currentPlayerIndex + 1) % int(players.size());
    }

    int Game::getPlayerWithLongestRoad() const {
        int longest_road = 0;
        shared_ptr<Player> longest_road_player;
        for(const auto& p: players){
            if (p->getNumberOfRoads() > longest_road){
                longest_road_player = p;
                longest_road = p->getNumberOfRoads();
            }
        }
        return longest_road_player->getId();
    }

    const shared_ptr<Player> &Game::getCurrentPlayer() const {
        return players[currentPlayerIndex];
    }

    void Game::rollDice(const string& name) {
        int roll1 = rand() % 6 + 1;
        int roll2 = rand() % 6 + 1;
        int totalRoll = roll1 + roll2;
        cout << endl << "You rolled " << totalRoll << "!" << endl;
        if (totalRoll == 7) {
            ROBBER();
            handleRollOfSeven();
        } else {
            DICE();
            distributeResources(totalRoll);
        }
    }

    int Game::buyDevelopmentCard() {
        if (!developmentCardDeck.isEmpty()) {
            auto p = getCurrentPlayer();
            if (p->hasResourcesForCard()) {
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
        auto p = getCurrentPlayer();
        int points = p->getScore();
        return points >= 10 ? true : false;
    }

    const shared_ptr<Player> &Game::getWinner() const {
        return winner;
    }

    void Game::determineWinner() {
        // Logic to determine the winner based on game rules
    }

    int Game::getCounter(Resource r) const {
        switch (r) {
            case Resource::Wood:
                return resources_cards.at(Resource::Wood);
            case Resource::Wheat:
                return resources_cards.at(Resource::Wheat);
            case Resource::Brick:
                return resources_cards.at(Resource::Brick);
            case Resource::Ore:
                return resources_cards.at(Resource::Ore);
            case Resource::Sheep:
                return resources_cards.at(Resource::Sheep);
            default:
                return 0;
        }
    }

    void Game::changeCounter(Resource r, int amount) {
        switch (r) {
            case Resource::Wood:
                resources_cards[Resource::Wood] += amount;
            case Resource::Wheat:
                resources_cards[Resource::Wheat] += amount;
            case Resource::Brick:
                resources_cards[Resource::Brick] += amount;
            case Resource::Ore:
                resources_cards[Resource::Ore] += amount;
            case Resource::Sheep:
                resources_cards[Resource::Sheep] += amount;
            default:
                return;
        }
    }

    void Game::distributeResources(int rollResult) {
        cout << "Distributing resources for roll: " << rollResult << endl;

        for (const auto &tile: model::Board::getTiles()) {
            if (tile.getDicedNumber() == rollResult) {
                for (const auto &node: tile.getNodes()) {
                    if (!(node->isAvailable())) {
                        int ownerId = node->getOwnerId();
                        auto owner = players[ownerId - 1];
                        auto resource_card_type = tile.getResourceType();

                        if (getCounter(resource_card_type) == 0) throw out_of_range("no more cards on deck");

                        int card_num = node->getNodeStatus() == NodeStatus::SETTLEMENT ? 1 : 2;
                        owner->addResourceCard(resource_card_type, card_num);
                        changeCounter(resource_card_type, -card_num);

                        cout << "Player " << owner->getName()
                             << " receives " << ResourceToString(resource_card_type)
                             << " from tile " << tile.getId() << endl;
                    }
                }
            }
        }
    }

    bool Game::canBuildSettlement(int nodeId) {
        const auto &node = model::Board::getNode(nodeId);

        if (!node->isAvailable()) {
            return false;
        }
        return true;
    }

    bool Game::isInitialPlacementPhase() const {
        return InitialPlacementPhase;
    }

    void Game::addPlayer(const string &name, int id) {
        shared_ptr<Player> p = make_shared<Player>(name, id);
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
        p->addRoad(board.getRoad(50));
        p->addRoad(board.getRoad(45));
        p->addRoad(board.getRoad(42));
        p->addRoad(board.getRoad(38));
        p->addRoad(board.getRoad(53));
        p->addResourceCard(Resource::Wood);
        p->addResourceCard(Resource::Wood);
        p->addResourceCard(Resource::Wood);
        p->addResourceCard(Resource::Brick);
        p->addResourceCard(Resource::Brick);
        p->addResourceCard(Resource::Wheat);
        p->addResourceCard(Resource::Wheat);
        p->addResourceCard(Resource::Ore);
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

        cout << "Player: " << p->getName() << " choose a node for your settlement" << endl;
        int n;
        cin >> n;
        while (n < 0 || n > 53 || !canBuildSettlement(n)) {
            if (!canBuildSettlement(n)) {
                cout << "Node " << n << " is occupied or blocked. Try again" << endl;
            } else {
                cout << "Invalid choice. Please Enter a number between 0 to 53" << endl;
            }
            cin >> n;
        }
        auto s = model::Board::getNode(n);
        blockAdjNodes(s);
        p->addSettlement(s);
        cout << board << endl;
        auto adj_roads = model::Board::getAvailableAdjacentRoads(s);

        cout << "Player: " << p->getName() << " choose a road" << endl;
        cout << "You can chooseWhatToBuild a new road in: " << endl;
        printAvailableRoads(adj_roads);


        int length = int(adj_roads.size());
        cout << "Please Enter a number between 1 to " << length << endl;
        cin >> n;
        while (n <= 0 || n > length) {
            cout << "Invalid choice. Please Enter a number between 1 to " << length << endl;
            printAvailableRoads(adj_roads);
            cin >> n;
        }

        p->addRoad(board.getRoad(n));

        cout << board << endl;
    }

    void Game::endOfInitialPlacement() {
        InitialPlacementPhase = false;
    }


    void Game::printAvailableRoads(vector<shared_ptr<Road>> &road_list) {
        cout << "You can chooseWhatToBuild a new road in: " << endl;
        for (int i = 0; i < int(road_list.size()); ++i) {
            cout << i + 1 << ") Edge-" << road_list[i]->getId() << endl;
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
        std::set<shared_ptr<Road>> can_build;
        for (const auto &road: p->getPlayerRoads()) {
            auto adj_roads = model::Board::getAvailableAdjacentRoads(road);
            for (const auto &n: adj_roads) {
                can_build.insert(n);
            }
        }
        std::vector<shared_ptr<Road>> v(can_build.begin(), can_build.end());
        return v;
    }

    void Game::handleRollOfSeven() {
//        cout << "Handling roll of 7: players with more than 7 resource cards must return half to the stock." << endl;
        cout << "Oh no! The ROBBER strikes! Everyone with more than 7 cards, prepare to pay the toll."
             << endl;


        for (const auto &player: players) {
            int numResourceCards = player->getTotalResourceCards();
            if (numResourceCards > 7) {
                int numCardsToReturn = numResourceCards / 2;
                map<Resource, int> giveUpList = player->chooseCardsToLose(numCardsToReturn);
                for (const auto &pair: giveUpList) {
                    resources_cards[pair.first] -= pair.second;
                }
                cout << "Player " << player->getId() << " returns " << numCardsToReturn << " cards to the stock."
                     << endl;
                cout << "Remember, the ROBBER always gets his share... Muahahaha!" << endl;
            }
        }
    }

 }