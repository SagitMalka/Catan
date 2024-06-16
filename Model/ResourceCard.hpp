#pragma once

#include "Card.hpp"
#include "Resource.hpp"
#include <iostream>
#include <string>

using std::string;
using std::ostream;

namespace model {

    class ResourceCard : public Card{
    private:
        Resource resource_type;

    public:
        explicit ResourceCard(Resource resource_type);
        [[nodiscard]] Resource getResourceType() const;
        [[nodiscard]] string toString() const override;
    };

}

