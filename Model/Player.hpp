#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "DevelopmentCard.hpp"
#include "ResourceCard.hpp"
#include "Road.hpp"
#include "Node.hpp"

#include <memory>

using std::vector;

using std::shared_ptr;
namespace model{
    class Player {
    private:
        int id;
        std::string name;
        int score = 0;
        std::string color;

        vector<shared_ptr<DevelopmentCard>> development_cards;
        vector<shared_ptr<ResourceCard>> resource_cards;
        vector<shared_ptr<Road>> roads = {};
        vector<shared_ptr<Node>> settlements_cities = {};

        int countResource(Resource resource) const;
    public:
        Player(std::string name, int id);

        // GETTERS
        [[nodiscard]] int getScore() const;
        [[nodiscard]] int getId() const;
        std::string getName();
        string getColor();

        void updateScore(int points);
        void addDevelopmentCard(const shared_ptr<DevelopmentCard>& development_card);
        void addResourceCard(const shared_ptr<ResourceCard>& resource_card);
        [[nodiscard]] bool hasResoursesForNewSettlement() const;
        void deductResourcesForSettlement();
        void addSettlement(const shared_ptr<Node>& settlement);

        bool hasAdjacentRoad(int node_id);
    };
}

