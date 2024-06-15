#pragma once

#include <iostream>
#include <string>

namespace model{
    class Player {
    private:
        std::string name;
        int score;
    public:
        Player(std::string name);
        int getScore() const;
        void updateScore(int points);


    };
}

