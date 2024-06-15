//
// Created by SAGIT on 14/06/2024.
//

#include "Player.hpp"

#include <utility>

namespace model{

    Player::Player(std::string name) : name(std::move(name)) {}

    int Player::getScore() const {
        return score;
    }

    void Player::updateScore(int points) {
        score += points;
    }


}
