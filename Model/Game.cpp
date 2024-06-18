#include "Game.hpp"

namespace model {

    Game::Game()
            : currentPlayerIndex(0), gameOver(false), winner(nullptr) {
        initializeGame();
    }

    void Game::initializeGame() {
        // Initialize board, decks, and players
        board.initializeBoard();
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
        // Logic to build a settlement for a player
    }

    void Game::buildRoad(int playerId, int tileId, int roadId) {
        // Logic to build a road for a player
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

}
