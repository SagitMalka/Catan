// sagitmalka10@gmail.com

#pragma once

#include <vector>
#include <algorithm>
#include <random>
#include "Card.hpp"

using std::vector;

namespace model {

    template <typename CardType>
    class CardDeck {
    public:
        CardDeck() = default;
        virtual ~CardDeck() = default;

        CardType drawCard();
        bool isEmpty() const;
        void shuffleDeck();  // Declaring shuffleDeck here

    protected:
        std::vector<CardType> deck;
        virtual void initializeDeck() = 0;  // Still protected

    };

    template <typename CardType>
    CardType CardDeck<CardType>::drawCard() {
        if (deck.empty()) {
            throw std::out_of_range("No more cards in the deck");
        }
        CardType card = deck.back();
        deck.pop_back();
        return card;
    }

    template <typename CardType>
    bool CardDeck<CardType>::isEmpty() const {
        return deck.empty();
    }

    template <typename CardType>
    void CardDeck<CardType>::shuffleDeck() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(deck.begin(), deck.end(), g);
    }

}