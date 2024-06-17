
#include "ResourceCardDeck.hpp"

namespace model{
    ResourceCardDeck::ResourceCardDeck() {
        initializeDeck();
        shuffleDeck();
    }
    void ResourceCardDeck::initializeDeck() {
        for (int i = 0; i < MAX_WOOD_CARDS; ++i) {
            deck.emplace_back(Resource::Wood);
        }
        for (int i = 0; i < MAX_WOOD_CARDS; ++i) {
            deck.emplace_back(Resource::Brick);
        }
        for (int i = 0; i < MAX_WOOD_CARDS; ++i) {
            deck.emplace_back(Resource::Sheep);
        }
        for (int i = 0; i < MAX_WOOD_CARDS; ++i) {
            deck.emplace_back(Resource::Ore);
        }
        for (int i = 0; i < MAX_WOOD_CARDS; ++i) {
            deck.emplace_back(Resource::Wheat);
        }
    }

    void ResourceCardDeck::resetDeck() {
        initializeDeck();
        shuffleDeck();
    }
}