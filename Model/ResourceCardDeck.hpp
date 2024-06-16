#pragma once

#include "CardDeck.hpp"
#include "ResourceCard.hpp"
#include "Constants.hpp"

namespace model {
    class ResourceCardDeck : public CardDeck<ResourceCard>{
    public:
        ResourceCardDeck();
    protected:
        void initializeDeck() override;
    };

}


