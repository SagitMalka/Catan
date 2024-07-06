#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "DevelopmentCard.hpp"
#include "Road.hpp"
#include "Node.hpp"
#include "Constants.hpp"
#include <memory>
#include <unordered_map>

using std::vector, std::unordered_map;

using std::shared_ptr;
namespace model{
    class Player {
    private:
        int id;
        std::string name;
        int score = 0;
        std::string color;
         std::map<Resource, int> resources_cards = {{Resource::Ore, 0}, {Resource::Sheep, 0}, {Resource::Brick, 0}, {Resource::Wheat, 0}, {Resource::Wood, 0}};
        vector<DevelopmentCard> development_cards;
        //vector<shared_ptr<ResourceCard>> resource_cards;
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
        int getNumberOfRoads() const;

        void updateScore(int points);
        void addDevelopmentCard(DevelopmentCard& development_card);

        [[nodiscard]] bool hasResourcesForNewSettlement() const;
        [[nodiscard]] bool hasResourcesForCard() const;
        [[nodiscard]] bool hasResourcesForCity() const;
        [[nodiscard]] bool hasResourcesForRoad() const;
        void payForSettlement();
        void addSettlement(const shared_ptr<Node>& settlement);
        void addCity(const shared_ptr<Node>& node);
        bool hasAdjacentRoad(int node_id);
        void addRoad(const shared_ptr<Road>& road);
        vector<shared_ptr<Node>> getPlayerSettlements();
        const vector<shared_ptr<Road>>& getPlayerRoads() const;

        void addResourceCard(Resource resource, int count=1);
        //void addResourceCard(const shared_ptr<ResourceCard> &resource);
        [[nodiscard]] int getTotalResourceCards() const;
        std::map<Resource, int> chooseCardsToLose(int numOfResourcesToGive);

        void payResources(std::map<Resource, int> price);

        void payForCity();

        void payForCard();

        void payForRoad();

        void showCards() const;

        bool hasEnoughResources(std::map<Resource, int> price) const;

        int chooseCardsToTrade();

        bool canTradeWithDeck();

        int chooseCardsToTrade() const;
    };
}

