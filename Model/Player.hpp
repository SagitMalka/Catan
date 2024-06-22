#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "DevelopmentCard.hpp"
#include "ResourceCard.hpp"
#include "Road.hpp"
#include "Node.hpp"
#include "Constants.hpp"
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

        vector<DevelopmentCard> development_cards;
        vector<shared_ptr<ResourceCard>> resource_cards;
        vector<shared_ptr<Road>> roads = {};
        vector<shared_ptr<Node>> settlements_cities = {};


    private:

        [[nodiscard]] int countResource(Resource resource) const;
    public:
        Player(std::string name, int id);

        // GETTERS
        [[nodiscard]] int getScore() const;
        [[nodiscard]] int getId() const;
        std::string getName();
        string getColor();

        void updateScore(int points);
        void addDevelopmentCard(DevelopmentCard& development_card);
        void addResourceCard(Resource resource);

        [[nodiscard]] bool hasResourcesForNewSettlement() const;
        [[nodiscard]] bool hasResourcesForDevCard() const;
        [[nodiscard]] bool hasResourcesForCity() const;
        [[nodiscard]] bool hasResourcesForRoad() const;
        void deductResourcesForSettlement();
        void addSettlement(const shared_ptr<Node>& settlement);

        bool hasAdjacentRoad(int node_id);
        void addRoad(const shared_ptr<Road>& road);
        vector<shared_ptr<Node>> getPlayerSettlements();
        const vector<shared_ptr<Road>>& getPlayerRoads() const;

    };
}

