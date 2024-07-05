//
// Created by SAGIT on 14/06/2024.
//

#include "Player.hpp"


#include <utility>

namespace model {

    Player::Player(std::string name, int id) : name(std::move(name)), id(id) {
        this->color = getColorByID(id);
    }

    int Player::getScore() const {
        return score;
    }

    void Player::updateScore(int points) {
        score += points;
    }

    int Player::getId() const {
        return id;
    }

    void Player::addDevelopmentCard(DevelopmentCard &development_card) {
        development_cards.push_back(development_card);
    }

    void Player::addResourceCard(const shared_ptr<ResourceCard>(&resource)) {
        resource_cards.push_back(resource);
    }

    bool Player::hasResourcesForNewSettlement() const {
        const int requiredBrick = 1;
        const int requiredWood = 1;
        const int requiredWheat = 1;
        const int requiredSheep = 1;

        if (countResource(Resource::Brick) < requiredBrick) return false;
        if (countResource(Resource::Wood) < requiredWood) return false;
        if (countResource(Resource::Wheat) < requiredWheat) return false;
        if (countResource(Resource::Sheep) < requiredSheep) return false;

        return true;
    }
    bool Player::hasResourcesForCity() const {
        const int requiredOre = 3;
        const int requiredWheat = 2;

        if (countResource(Resource::Ore) < requiredOre) return false;
        if (countResource(Resource::Wheat) < requiredWheat) return false;
        return true;
    }
    bool Player::hasResourcesForDevCard() const {
        const int requiredOre = 1;
        const int requiredSheep = 1;
        const int requiredWheat = 1;

        if (countResource(Resource::Ore) < requiredOre) return false;
        if (countResource(Resource::Sheep) < requiredSheep) return false;
        if (countResource(Resource::Wheat) < requiredWheat) return false;
        return true;
    }
    bool Player::hasResourcesForRoad() const {
        const int requiredBrick = 1;
        const int requiredWood = 1;
        if (countResource(Resource::Brick) < requiredBrick) return false;
        if (countResource(Resource::Wood) < requiredWood) return false;
        return true;
    }
    int Player::countResource(Resource resource) const {
        int count = 0;
        for (const auto &card: resource_cards) {
            if (card->getResourceType() == resource) {
                ++count;
            }
        }
        return count;
    }

    void Player::deductResourcesForSettlement() {
        int brick = 1, wood = 1, wheat = 1, sheep = 1;
        for (int i = 0; i < int(resource_cards.size()); i++) {
            if (brick && resource_cards[i]->resource_type == Resource::Brick) {
                resource_cards.erase(resource_cards.begin() + i);
                brick = 0;
            } else if (wood && resource_cards[i]->resource_type == Resource::Wood) {
                resource_cards.erase(resource_cards.begin() + i);
                wood = 0;
            } else if (wheat && resource_cards[i]->resource_type == Resource::Wheat) {
                resource_cards.erase(resource_cards.begin() + i);
                wheat = 0;
            } else if (sheep && resource_cards[i]->resource_type == Resource::Sheep) {
                resource_cards.erase(resource_cards.begin() + i);
                sheep = 0;
            }
        }

    }

/**
 * maybe controller should call updateScore & setOwner
 * */
    void Player::addSettlement(const shared_ptr<Node> &settlement) {
        settlements_cities.push_back(settlement);
        settlement->setNodeStatus(NodeStatus::SETTLEMENT);
        updateScore(1);
        settlement->setOwner(id);
    }

    bool Player::hasAdjacentRoad(int node_id) {
        for (auto &road: roads) {
            if (road->getNodeOfRoad(1)->getId() == node_id) {
                return true;
            } else if (road->getNodeOfRoad(2)->getId() == node_id) {
                return true;
            }
        }
        return false;
    }

    std::string Player::getName() {
        if (IS_COLOR) {
            return this->color + this->name + RESET;
        } else {
            return this->name;
        }
    }


    std::string Player::getColor() {
        return this->color;
    }

    void Player::addRoad(const shared_ptr<Road> &road) {
        road->setOwner(this->id);
        this->roads.push_back(road);
//        TODO check for longest road?
    }

    vector<shared_ptr<Node>> Player::getPlayerSettlements() {
        vector<shared_ptr<Node>> settlements;
        for(const auto& s : settlements_cities){
            if(s->getNodeStatus() == NodeStatus::SETTLEMENT){
                settlements.push_back(s);
            }
        }
        return settlements;
    }

    const vector<shared_ptr<Road>>& Player::getPlayerRoads() const {
        return roads;
    }

    void Player::addResourceCard(Resource resource) {
        resource_cards.push_back(std::make_shared<ResourceCard>(resource));
    }


}
