#pragma once

#include <memory>
#include "CardDeck.hpp"
#include "ResourceCard.hpp"
#include "Resource.hpp"

namespace model {

    class ResourceCardDeck : public CardDeck<std::shared_ptr<ResourceCard>> {
    public:
        explicit ResourceCardDeck(Resource resourceType);

    protected:
        void initializeDeck() override;

    private:
        Resource resourceType;
    };

} // namespace model
