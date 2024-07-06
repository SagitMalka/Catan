#pragma once
#include <map>

namespace model{
    enum class Resource{
        Wood,
        Brick,
        Sheep,
        Wheat,
        Ore,
        Desert
    };

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

    const bool FAST_START = true;

    const int ROADS_PER_PLAYER = 20;
    //colors
    const bool IS_COLOR = true;
    #define RESET   "\033[0m"
    #define BLACK   "\033[30m"
    #define RED     "\033[41m"      /* Red background */
    #define GREEN   "\033[42m"      /* Green background */
    #define YELLOW  "\033[43m"      /* Yellow background */
    #define BLUE    "\033[44m"      /* Blue background */
    #define MAGENTA "\033[45m"      /* Magenta background */
    #define CYAN    "\033[46m"      /* Cyan background */
    #define WHITE_BACKGROUND "\033[47m"
    #define LIGHT_RED_BACKGROUND "\033[101m"
    #define BOLD_TEXT "\033[1m"
    #define ANSI_COLOR_LIGHT_BROWN_BG "\033[48;5;95m"
    #define CANCEL -1
    const std::map<Resource, int> CITY_COST =          {{Resource::Wood, 0}, {Resource::Wheat, 2}, {Resource::Ore, 3}, {Resource::Sheep, 0}, {Resource::Brick, 0}};
    const std::map<Resource, int> SETTLEMENT_COST =    {{Resource::Wood, 1}, {Resource::Wheat, 1}, {Resource::Ore, 0}, {Resource::Sheep, 1}, {Resource::Brick, 1}};
    const std::map<Resource, int> CARD_COST =          {{Resource::Wood, 0}, {Resource::Wheat, 1}, {Resource::Ore, 1}, {Resource::Sheep, 1}, {Resource::Brick, 0}};
    const std::map<Resource, int> ROAD_COST =          {{Resource::Wood, 1}, {Resource::Wheat, 0}, {Resource::Ore, 0}, {Resource::Sheep, 0}, {Resource::Brick, 1}};


    inline std::string getColorByID(int id) {
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
    inline void DICE() {
        std::cout <<"   "<< WHITE_BACKGROUND << BLACK << "_______" << RESET << std::endl;
        std::cout <<"  "<< WHITE_BACKGROUND << BLACK << "/\\ o o o\\" << RESET << std::endl;
        std::cout <<" "<< WHITE_BACKGROUND << BLACK << "/o \\ o o o\\_______" << RESET << std::endl;
        std::cout <<""<< WHITE_BACKGROUND << BLACK << "<    >------>   o /|" << RESET << std::endl;
        std::cout <<" "<< WHITE_BACKGROUND << BLACK << "\\ o/  o   /_____/o|" << RESET << std::endl;
        std::cout <<"  "<< WHITE_BACKGROUND << BLACK << "\\/______/     |oo|" << RESET << std::endl;
        std::cout <<"        "<< WHITE_BACKGROUND << BLACK << "|   o   |o/" << RESET << std::endl;
        std::cout <<"        "<< WHITE_BACKGROUND << BLACK << "|_______|/"<< RESET << std::endl;
    }

    inline void ROBBER() {
        std::cout << LIGHT_RED_BACKGROUND << BOLD_TEXT << BLACK "  / \\                    " << RESET << std::endl;
        std::cout << LIGHT_RED_BACKGROUND << BOLD_TEXT << BLACK "  | |                    " << RESET << std::endl;
        std::cout << LIGHT_RED_BACKGROUND << BOLD_TEXT << BLACK "  |.|                    " << RESET << std::endl;
        std::cout << LIGHT_RED_BACKGROUND << BOLD_TEXT << BLACK "  |.|                    " << RESET << std::endl;
        std::cout << LIGHT_RED_BACKGROUND << BOLD_TEXT << BLACK "  |:|      __            " << RESET << std::endl;
        std::cout << LIGHT_RED_BACKGROUND << BOLD_TEXT << BLACK ",_|:|_,   /  )           " << RESET << std::endl;
        std::cout << LIGHT_RED_BACKGROUND << BOLD_TEXT << BLACK "  (Oo    / _I_           " << RESET << std::endl;
        std::cout << LIGHT_RED_BACKGROUND << BOLD_TEXT << BLACK "   +\\ \\  || __|          " << RESET << std::endl;
        std::cout << LIGHT_RED_BACKGROUND << BOLD_TEXT << BLACK "      \\ \\||___|          " << RESET << std::endl;
        std::cout << LIGHT_RED_BACKGROUND << BOLD_TEXT << BLACK "        \\ /.:.\\-\\        " << RESET << std::endl;
        std::cout << LIGHT_RED_BACKGROUND << BOLD_TEXT << BLACK "         |.:. /-----\\    " << RESET << std::endl;
        std::cout << LIGHT_RED_BACKGROUND << BOLD_TEXT << BLACK "         |___|::oOo::|   " << RESET << std::endl;
        std::cout << LIGHT_RED_BACKGROUND << BOLD_TEXT << BLACK "         /   |:<_T_>:|   " << RESET << std::endl;
        std::cout << LIGHT_RED_BACKGROUND << BOLD_TEXT << BLACK "        |_____\\ ::: /    " << RESET << std::endl;
        std::cout << LIGHT_RED_BACKGROUND << BOLD_TEXT << BLACK "         | |  \\ \\:/      " << RESET << std::endl;
        std::cout << LIGHT_RED_BACKGROUND << BOLD_TEXT << BLACK "         | |   | |       " << RESET << std::endl;
        std::cout << LIGHT_RED_BACKGROUND << BOLD_TEXT << BLACK "         \\ /   | \\___    " << RESET << std::endl;
        std::cout << LIGHT_RED_BACKGROUND << BOLD_TEXT << BLACK "         / |   \\_____\\   " << RESET << std::endl;
        std::cout << LIGHT_RED_BACKGROUND << BOLD_TEXT << BLACK "         `-'             " << RESET << std::endl;
    }

}
