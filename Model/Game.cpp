#include "Game.hpp"

using std::string;
using std::cout;
using std::endl;
namespace model {

    Game::Game()
            : currentPlayerIndex(0) {}

    void Game::initializeGame(int numPlayers) {
        board.initializeBoard();
        developmentCardDeck.resetDeck();
        resourceCardDeck.resetDeck();
        initializePlayers();
        distributeResources();
    }

    void Game::initializePlayers() {
        players.clear();
        string name;
        for (int i = 0; i < NUM_OF_PLAYERS; i++) {
            cout << "Player " << i << "enter your name: " << endl;
            std::cin >> name;
            players.emplace_back(name, i); // Assuming Player has a constructor that takes an ID
        }
    }

    void Game::buildSettlement(int playerId, const Node& location) {
        // Implementation for building a settlement
    }

    void Game::buildRoad(int playerId, const Road& road) {
        // Implementation for building a road
    }

    void Game::upgradeSettlementToCity(int playerId, const Node& location) {
        // Implementation for upgrading a settlement to a city
    }

    void Game::drawDevelopmentCard(int playerId) {
        if (!developmentCardDeck.isEmpty()) {
            DevelopmentCard card = developmentCardDeck.drawCard();
            players[playerId].addDevelopmentCard(card);
        }
    }

    void Game::playDevelopmentCard(int playerId, DevelopmentCard card) {
        // Implementation for playing a development card
    }

    void Game::tradeResources(int playerId1, Resource resource1, int playerId2, Resource resource2) {
        // Implementation for trading resources between players
    }

    int Game::getCurrentPlayerId() const {
        return players[currentPlayerIndex].getPlayerId();
    }

    Player Game::getCurrentPlayer() const {
        return players[currentPlayerIndex];
    }

    const std::vector<Player>& Game::getPlayers() const {
        return players;
    }

    const Board& Game::getBoard() const {
        return board;
    }

    void Game::nextTurn() {
        currentPlayerIndex = (currentPlayerIndex + 1) % int(players.size());
    }

    bool Game::checkWinCondition() const {
        for (const Player& player : players) {
            if (player.getScore() >= 10) { // Assuming 10 points is the win condition
                return true;
            }
        }
        return false;
    }

    void Game::distributeResources() {
        // Implementation for distributing resources
    }

} // namespace model
