#pragma once

#include "CardDeck.hpp"
#include "ResourceCard.hpp"
#include "Constants.hpp"

namespace model {
    class ResourceCardDeck : public CardDeck<ResourceCard>{
    public:
        ResourceCardDeck();
        // Public method to reinitialize and shuffle the deck if needed
        void resetDeck();
    protected:
        void initializeDeck() override;
    };

}


