#pragma once
#include <string>
#include "Card.hpp"
using std::string;

namespace model {
    enum class CardType{
        KNIGHT,
        VICTORY_POINT,
        ROAD_BUILDING,
        YEAR_OF_PLENTY,
        MONOPOLY
    };


    class DevelopmentCard : public Card{
    private:
        CardType type;
    public:
        DevelopmentCard(CardType card_type);
        CardType getType() const;
        string toString() const override;

    };
}