#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "DevelopmentCard.hpp"
#include "ResourceCard.hpp"
//#include "Road.hpp"
//#include "Node.hpp"
#define RESET   "\033[0m"
#define RED     "\033[41m"      /* Red background */
#define GREEN   "\033[42m"      /* Green background */
#define YELLOW  "\033[43m"      /* Yellow background */
#define BLUE    "\033[44m"      /* Blue background */
#define MAGENTA "\033[45m"      /* Magenta background */
#define CYAN    "\033[46m"      /* Cyan background */

using std::vector;

namespace model{
    class Player {
    private:
        int id;
        std::string name;
        int score = 0;
        vector<DevelopmentCard> development_cards;
        vector<ResourceCard> resource_cards;
//        vector<Road> roads;
//        vector<Node> settlements_cities;
    public:
        Player(std::string name, int id);
        int getScore() const;
        void updateScore(int points);
        int getPlayerId() const;
        void addDevelopmentCard(const DevelopmentCard& development_card);
        void addResourceCard(const ResourceCard& resource_card);

    };
}

