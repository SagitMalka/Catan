#pragma once

namespace model{
    // dev cards
    const int MAX_KNIGHT_CARDS = 14;
    const int MAX_VICTORY_POINT_CARDS = 5;
    const int MAX_ROAD_BUILDING_CARDS = 2;
    const int MAX_YEAR_OF_PLENTY_CARDS = 2;
    const int MAX_MONOPOLY_CARDS = 2;

    // resource cards
    const int MAX_WOOD_CARDS = 19;
    const int MAX_BRICK_CARDS = 19;
    const int MAX_SHEEP_CARDS = 19;
    const int MAX_WHEAT_CARDS = 19;
    const int MAX_ORE_CARDS = 19;

    const int NODES_PER_TILE = 6;
    const int ROADS_PER_TILE = 6;


    //info for player
    const int SETTLEMENTS_PER_PLAYER = 5;
    const int CITIES_PER_PLAYER = 4;
    const int ROADS_PER_PLAYER = 20;

    //colors
    const bool IS_COLOR = true;
    #define RESET   "\033[0m"
    #define RED     "\033[41m"      /* Red background */
    #define GREEN   "\033[42m"      /* Green background */
    #define YELLOW  "\033[43m"      /* Yellow background */
    #define BLUE    "\033[44m"      /* Blue background */
    #define MAGENTA "\033[45m"      /* Magenta background */
    #define CYAN    "\033[46m"      /* Cyan background */


    std::string getColorByID(int id) {
        switch (id) {
            case 1:
                return "\033[31m";
            case 2:
                return "\033[32m";
            case 3:
                return "\033[34m";
            default:
                return "\033[0m";
        }
    }

}
