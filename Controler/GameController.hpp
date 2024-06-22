#pragma once

#include <vector>
#include <memory>
#include "../Model/Board.hpp"
#include "../Model/Player.hpp"
#include "../Model/ResourceCardDeck.hpp"
#include "../Model/DevelopmentCardDeck.hpp"
using std::vector;
using std::shared_ptr;

namespace model {

    class GameController {
    private:


        bool gameOver;
        shared_ptr<Player> winner;
//        bool InitialPlacementPhase = true;

        // Private helper methods
        void determineWinner();
        void distributeResources(int rollResult);

    public:
        GameController();

        // Game initialization and setup


        // Player management
//        void addPlayer(const std::string& name, int id);
//        [[nodiscard]] const vector<shared_ptr<Player>>& getPlayers() const;

        // Turn management



        // Game actions


        // Game state queries



//        [[nodiscard]] bool isInitialPlacementPhase() const;
//        void endOfInitialPlacement();


//        int getUserChoice(size_t options_size);




    };

}
