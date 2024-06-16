#pragma once

#include "CardDeck.hpp"
#include "DevelopmentCard.hpp"
#include "Constants.hpp"
namespace model{
    class DevelopmentCardDeck : public CardDeck<DevelopmentCard>{
    public:
        DevelopmentCardDeck();
    protected:
        void initializeDeck() override;

    };
}




