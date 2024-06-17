#pragma once

#include "CardDeck.hpp"
#include "DevelopmentCard.hpp"
#include "Constants.hpp"
namespace model{
    class DevelopmentCardDeck : public CardDeck<DevelopmentCard>{
    public:
        DevelopmentCardDeck();
        // Public method to reinitialize and shuffle the deck if needed
        void resetDeck();
    protected:
        void initializeDeck() override;
    };
}




