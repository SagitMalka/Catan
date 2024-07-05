#include "ResourceCardDeck.hpp"

namespace model {

    ResourceCardDeck::ResourceCardDeck(Resource resourceType)
            : resourceType(resourceType) {
        initializeDeck();
    }

    void ResourceCardDeck::initializeDeck() {
        // Assuming each deck should have a certain number of cards.
        int numCards = 19; // Example number, adjust as necessary
        for (int i = 0; i < numCards; ++i) {
            deck.push_back(std::make_shared<ResourceCard>(resourceType));
        }
        shuffleDeck();
    }

} // namespace model
