#pragma once

#include <vector>
#include <memory>
#include "Board.hpp"
#include "Player.hpp"
#include "ResourceCardDeck.hpp"
#include "DevelopmentCardDeck.hpp"
using std::vector;
using std::shared_ptr;

namespace model {

    class Game {
    private:
        Board board;
        ResourceCardDeck resourceCardDeck;
        DevelopmentCardDeck developmentCardDeck;
        vector<shared_ptr<Player>> players;
        int currentPlayerIndex;
        bool gameOver;
        shared_ptr<Player> winner;
        bool InitialPlacementPhase = true;
        // Private helper methods
        void determineWinner();
        void distributeResources(int rollResult);
        bool canBuildSettlement(int playerId, int tileId, int nodeId) const;
    public:
        Game();

        // Game initialization and setup
        void initializeGame();

        // Player management
        void addPlayer(const shared_ptr<Player>& player);
        [[nodiscard]] const vector<shared_ptr<Player>>& getPlayers() const;

        // Turn management
        void startTurn();
        void endTurn();
        [[nodiscard]] const shared_ptr<Player>& getCurrentPlayer() const;

        // Game actions
        void rollDice();
        void buildSettlement(int playerId, int tileId, int nodeId);
        void buildRoad(int playerId, int tileId, int roadId);
        void tradeResources(int fromPlayerId, int toPlayerId, Resource give, Resource receive);
        void buyDevelopmentCard(int playerId);

        // Game state queries
        [[nodiscard]] bool isGameOver() const;
        [[nodiscard]] const shared_ptr<Player>& getWinner() const;


        bool isInitialPlacementPhase() const;
    };

}

