//
// Created by SAGIT on 14/06/2024.
//

#include "Player.hpp"
#include <ostream>

#include <utility>

using std::cout, std::endl, std::cin;

namespace model {

    Player::Player(std::string name, int id) : name(std::move(name)), id(id) {
        this->color = getColorByID(id);
    }

    int Player::getScore() const {
        int s = 0;
        for(const auto& n : settlements_cities){
            if(n->getNodeStatus() == NodeStatus::SETTLEMENT){
                s +=1;
            } else{
                s+= 2;
            }
        }
        return s + getNumberOfRoads();
    }

    void Player::updateScore(int points) {
        score += points;
    }

    int Player::getId() const {
        return id;
    }

    void Player::addDevelopmentCard(DevelopmentCard &development_card) {
        development_cards.push_back(development_card);
    }


    bool Player::hasEnoughResources(std::map<Resource, int> price) const {
        return price.at(Resource::Wood) <= resources_cards.at(Resource::Wood) &&
               price.at(Resource::Wheat) <= resources_cards.at(Resource::Wheat) &&
               price.at(Resource::Ore) <= resources_cards.at(Resource::Ore) &&
               price.at(Resource::Sheep) <= resources_cards.at(Resource::Sheep) &&
               price.at(Resource::Brick) <= resources_cards.at(Resource::Brick);
    }

    void Player::payResources(std::map<Resource, int> price) {
        resources_cards[Resource::Wood] -= price.at(Resource::Wood);
        resources_cards[Resource::Wheat] -= price.at(Resource::Wheat);
        resources_cards[Resource::Ore] -= price.at(Resource::Ore);
        resources_cards[Resource::Sheep] -= price.at(Resource::Sheep);
        resources_cards[Resource::Brick] -= price.at(Resource::Brick);
    }

    bool Player::hasResourcesForNewSettlement() const { return hasEnoughResources(SETTLEMENT_COST); }

    void Player::payForSettlement() { payResources(SETTLEMENT_COST); }

    bool Player::hasResourcesForCity() const { return hasEnoughResources(CITY_COST); }

    void Player::payForCity() { payResources(CITY_COST); }

    bool Player::hasResourcesForCard() const { return hasEnoughResources(CARD_COST); }

    void Player::payForCard() { payResources(CARD_COST); }

    bool Player::hasResourcesForRoad() const { return hasEnoughResources(ROAD_COST); }

    void Player::payForRoad() { payResources(ROAD_COST); }


    int Player::countResource(Resource resource) const {

        return resources_cards.at(Resource::Wheat) + resources_cards.at(Resource::Sheep) +
               resources_cards.at(Resource::Brick) + resources_cards.at(Resource::Wood) +
               resources_cards.at(Resource::Ore);
    }

    void Player::addSettlement(const shared_ptr<Node> &settlement) {
        settlements_cities.push_back(settlement);
        settlement->setNodeStatus(NodeStatus::SETTLEMENT);
        updateScore(1);
        settlement->setOwner(id);
    }

    void Player::addCity(const shared_ptr<Node> &node) {
        node->setNodeStatus(NodeStatus::CITY);
        updateScore(2);
    }

#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-use-falloff"

    bool Player::hasAdjacentRoad(int node_id) {
        for (auto &road: roads) {
            if (road->getNode(1)->getId() == node_id) {
                return true;
            } else if (road->getNode(2)->getId() == node_id) {
                return true;
            }
        }
        return false;
    }

#pragma clang diagnostic pop

    std::string Player::getName() {
        if (IS_COLOR) {
            return this->color + this->name + RESET;
        } else {
            return this->name;
        }
    }


    std::string Player::getColor() {
        return this->color;
    }

    void Player::addRoad(const shared_ptr<Road> &road) {
        road->setOwner(this->id);
        this->roads.push_back(road);
//        TODO check for longest road?
    }

    vector<shared_ptr<Node>> Player::getPlayerSettlements() {
        vector<shared_ptr<Node>> settlements;
        for (const auto &s: settlements_cities) {
            if (s->getNodeStatus() == NodeStatus::SETTLEMENT) {
                settlements.push_back(s);
            }
        }
        return settlements;
    }

    const vector<shared_ptr<Road>> &Player::getPlayerRoads() const {
        return roads;
    }

    void Player::addResourceCard(Resource resource, int count) {
        switch (resource) {
            case Resource::Ore:
                resources_cards[Resource::Ore] += count;
                break;
            case Resource::Wood:
                resources_cards[Resource::Wood] += count;
                break;
            case Resource::Brick:
                resources_cards[Resource::Brick] += count;
                break;
            case Resource::Sheep:
                resources_cards[Resource::Sheep] += count;
                break;
            case Resource::Wheat:
                resources_cards[Resource::Wheat] += count;
                break;
            case Resource::Desert:
                break;
        }
    }

    void Player::showCards() const {
        cout << BOLD_TEXT << ANSI_COLOR_LIGHT_BROWN_BG << BLACK << "==========================" << RESET << endl;
        cout << BOLD_TEXT << ANSI_COLOR_LIGHT_BROWN_BG << BLACK << "|| >\t" << resources_cards.at(Resource::Ore)
             << " Ore cards\t\t||" << RESET << endl;
        cout << BOLD_TEXT << ANSI_COLOR_LIGHT_BROWN_BG << BLACK << "|| >\t" << resources_cards.at(Resource::Wheat)
             << " Wheat cards\t||" << RESET << endl;
        cout << BOLD_TEXT << ANSI_COLOR_LIGHT_BROWN_BG << BLACK << "|| >\t" << resources_cards.at(Resource::Wood)
             << " Wood cards\t||" << RESET << endl;
        cout << BOLD_TEXT << ANSI_COLOR_LIGHT_BROWN_BG << BLACK << "|| >\t" << resources_cards.at(Resource::Brick)
             << " Brick cards\t||" << RESET << endl;
        cout << BOLD_TEXT << ANSI_COLOR_LIGHT_BROWN_BG << BLACK << "|| >\t" << resources_cards.at(Resource::Sheep)
             << " Sheep cards\t||" << RESET << endl;
        cout << BOLD_TEXT << ANSI_COLOR_LIGHT_BROWN_BG << BLACK << "==========================" << RESET << endl
             << endl;
    }
    bool Player::canTradeWithDeck(){
        if(resources_cards.at(Resource::Wheat) >= 4 ||
        resources_cards.at(Resource::Sheep) >= 4 ||
        resources_cards.at(Resource::Brick) >= 4 ||

       resources_cards.at(Resource::Wood) >= 4 ||

       resources_cards.at(Resource::Ore) >= 4){
            return true;
        }
        return false;
    }
    int Player::chooseCardsToTrade() const{
        int user_choice = 0;
        while (user_choice < 1 || user_choice >> 5){
            cout << "choose resource: " << endl;
            showCards();
            cout << "1. Ore" << endl << "2. Wheat" << endl << "3. Wood" << endl << "4. Brick" << endl << "5. Sheep"
                 << endl;
            cin >> user_choice;
        }
        return user_choice;

    }
    std::map<Resource, int> Player::chooseCardsToLose(int numOfResourcesToGive) {
        showCards();
        std::map<Resource, int> give_up_list = {{Resource::Wood, 0},
                                                {Resource::Wheat, 0},
                                                {Resource::Ore, 0},
                                                {Resource::Sheep, 0},
                                                {Resource::Brick, 0}};
        std::cout << "Player " << name << ", you have more than 7 cards (" << getTotalResourceCards()
                  << ").\nTime to part with " << numOfResourcesToGive << " of them. Sorry, not sorry!" << std::endl;

        int p_choose_type, p_choose_amount;
        while (numOfResourcesToGive) {
            cout << "this is the cards you have left:" << endl;
            showCards();
            cout << "You have " << numOfResourcesToGive << " more cards to give the ROBBER!. choose type: " << endl;


            cout << "1. Ore" << endl << "2. Wheat" << endl << "3. Wood" << endl << "4. Brick" << endl << "5. Sheep"
                 << endl;
            cin >> p_choose_type;
            cout << "And how many of them can you spare?";
            cin >> p_choose_amount;
            Resource r;
            switch (p_choose_type) {
                case 1:
                    r = Resource::Ore;
                    break;
                case 2:
                    r = Resource::Wheat;
                    break;
                case 3:
                    r = Resource::Wood;
                    break;
                case 4:
                    r = Resource::Brick;
                    break;
                case 5:
                    r = Resource::Sheep;
                    break;
                default:
                    r = Resource::Desert;
            }
            if (r != Resource::Desert) {
                if (p_choose_amount <= 0) cout << "Please choose a positive number." << endl;
                else if (p_choose_amount > numOfResourcesToGive)
                    cout << "You can't give up more cards than needed (" << numOfResourcesToGive << ")." << endl;
                else if (p_choose_amount > resources_cards[r])
                    cout << "You can't give up " << p_choose_amount << " because you only have" << resources_cards[r]
                         << " cards of this type." << endl;
                else {
                    resources_cards[r] -= p_choose_amount;
                    numOfResourcesToGive -= p_choose_amount;
                    give_up_list[r] += p_choose_amount;
                }
            } else {
                cout << "Illegal input. the ROBBER won't give up that easy. try again!  " << endl;
            }
        }
        return give_up_list;
    }

    int Player::getTotalResourceCards() const {
        return resources_cards.at(Resource::Wood) + resources_cards.at(Resource::Wheat) +
               resources_cards.at(Resource::Ore) + resources_cards.at(Resource::Sheep) +
               resources_cards.at(Resource::Brick);
    }

    int Player::getNumberOfRoads() const {
        return int(roads.size());
    }


}
