#include "ResourceCard.hpp"

namespace model {

    ResourceCard::ResourceCard(Resource resourceType)
            : resource_type(resourceType) {}

    Resource ResourceCard::getResourceType() const {
        return resource_type;
    }

    std::string ResourceCard::toString() const {
        switch (resource_type) {
            case Resource::Wood:
                return "Wood";
            case Resource::Brick:
                return "Brick";
            case Resource::Sheep:
                return "Sheep";
            case Resource::Wheat:
                return "Wheat";
            case Resource::Ore:
                return "Ore";
            default:
                return "Unknown";
        }
    }

}
