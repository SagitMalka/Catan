#pragma once

#include <vector>
#include <string>
#include "Board.hpp"
#include "Player.hpp"
#include "DevelopmentCardDeck.hpp"
#include "ResourceCardDeck.hpp"

#define NUM_OF_PLAYERS 3
namespace model {

    class Game {
    public:
        Game();

        // Initialization methods
        void initializeGame(int numPlayers);

        // Player actions
        void buildSettlement(int playerId, const Node& location);
        void buildRoad(int playerId, const Road& road);
        void upgradeSettlementToCity(int playerId, const Node& location);
        void drawDevelopmentCard(int playerId);
        void playDevelopmentCard(int playerId, DevelopmentCard card);
        void tradeResources(int playerId1, Resource resource1, int playerId2, Resource resource2);

        // Game state queries
        int getCurrentPlayerId() const;
        Player getCurrentPlayer() const;
        const std::vector<Player>& getPlayers() const;
        const Board& getBoard() const;

        // Game progression
        void nextTurn();
        bool checkWinCondition() const;

    private:
        Board board;
        std::vector<Player> players;
        int currentPlayerIndex;
        DevelopmentCardDeck developmentCardDeck;
        ResourceCardDeck resourceCardDeck;

        // Helper methods
        void distributeResources();
        void initializePlayers();
    };

} // namespace model

