#pragma once

#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[41m"      /* Red background */
#define GREEN   "\033[42m"      /* Green background */
#define YELLOW  "\033[43m"      /* Yellow background */
#define BLUE    "\033[44m"      /* Blue background */
#define MAGENTA "\033[45m"      /* Magenta background */
#define CYAN    "\033[46m"      /* Cyan background */

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

