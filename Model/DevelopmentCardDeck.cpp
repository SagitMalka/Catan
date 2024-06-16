#include "DevelopmentCardDeck.hpp"

namespace model {

    DevelopmentCardDeck::DevelopmentCardDeck() {
        initializeDeck();
        shuffleDeck();
    }

    void DevelopmentCardDeck::initializeDeck() {
        // Add Knight Cards
        for (int i = 0; i < MAX_KNIGHT_CARDS; ++i) {
            deck.emplace_back(CardType::KNIGHT);
        }

        // Add Victory Point Cards
        for (int i = 0; i < MAX_VICTORY_POINT_CARDS; ++i) {
            deck.emplace_back(CardType::VICTORY_POINT);
        }

        // Add Road Building Cards
        for (int i = 0; i < MAX_ROAD_BUILDING_CARDS; ++i) {
            deck.emplace_back(CardType::ROAD_BUILDING);
        }

        // Add Year of Plenty Cards
        for (int i = 0; i < MAX_YEAR_OF_PLENTY_CARDS; ++i) {
            deck.emplace_back(CardType::YEAR_OF_PLENTY);
        }

        // Add Monopoly Cards
        for (int i = 0; i < MAX_MONOPOLY_CARDS; ++i) {
            deck.emplace_back(CardType::MONOPOLY);
        }
    }

} // namespace model
