//
// Created by SAGIT on 14/06/2024.
//

#include "Player.hpp"

#include <utility>

namespace model{

    Player::Player(std::string name, int id) : name(std::move(name)), id(id) {}

    int Player::getScore() const {
        return score;
    }

    void Player::updateScore(int points) {
        score += points;
    }

    int Player::getPlayerId() const {
        return id;
    }

    void Player::addDevelopmentCard(const DevelopmentCard& development_card) {
        development_cards.emplace_back(development_card);
    }

    void Player::addResourceCard(const ResourceCard& resource_card) {
        resource_cards.emplace_back(resource_card);
    }


}
