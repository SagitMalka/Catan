#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "DevelopmentCard.hpp"
#include "ResourceCard.hpp"
#include "Road.hpp"
#include "Node.hpp"
#include <memory>

//#define RESET   "\033[0m"
//#define RED     "\033[41m"      /* Red background */
//#define GREEN   "\033[42m"      /* Green background */
//#define YELLOW  "\033[43m"      /* Yellow background */
//#define BLUE    "\033[44m"      /* Blue background */
//#define MAGENTA "\033[45m"      /* Magenta background */
//#define CYAN    "\033[46m"      /* Cyan background */

using std::vector;

using std::shared_ptr;
namespace model{
    class Player {
    private:
        int id;
        std::string name;
        int score = 0;
        vector<shared_ptr<DevelopmentCard>> development_cards;
        vector<shared_ptr<ResourceCard>> resource_cards;
        vector<shared_ptr<Road>> roads = {};
        vector<shared_ptr<Node>> settlements_cities = {};

        int countResource(Resource resource) const;
    public:
        Player(std::string name, int id);
        [[nodiscard]] int getScore() const;
        void updateScore(int points);
        [[nodiscard]] int getPlayerId() const;
        std::string getPlayerName(const Player&);
        void addDevelopmentCard(const shared_ptr<DevelopmentCard>& development_card);
        void addResourceCard(const shared_ptr<ResourceCard>& resource_card);
        [[nodiscard]] bool hasResoursesForNewSettlement() const;
        void deductResourcesForSettlement();
        void addSettlement(const shared_ptr<Node>& settlement);
        bool hasAdjacentRoad(int node_id);

    };
}

