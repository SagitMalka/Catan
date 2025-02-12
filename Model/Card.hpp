// sagitmalka10@gmail.com

#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;

namespace model{
    class Card{
    public:
        virtual ~Card() = default;
        [[nodiscard]] virtual string toString() const = 0;
        friend ostream& operator<<(ostream& os, const Card& card){
            os << card.toString();
            return os;
        }
    };

}