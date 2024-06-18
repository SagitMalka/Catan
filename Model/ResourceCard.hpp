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


    public:
        Resource resource_type;
        explicit ResourceCard(Resource resource_type);
        [[nodiscard]] Resource getResourceType() const;
        [[nodiscard]] string toString() const override;
    };

}

