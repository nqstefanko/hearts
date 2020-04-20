#include "card.hpp"

Card::Card() {
	value = 0;
}

Card::Card(int v, int s): value(v), suit(s) { }

const char * Card::getSuitSymbol() const {
	return SUIT_CONVERSION[suit];
}

const std::string Card::getCardValue() const {
	if(value > 10) {
		return FACE_CARD_CONVERSION[value];
	} else {
		return std::to_string(value);
	}
}

bool Card::hasPoints() {
    if(suit == HEARTS || (suit == SPADES && value == 12)) {
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Card& c)
{
	Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);

    if(c.suit == HEARTS || c.suit == DIAMONDS) {
    	os << c.getCardValue()  <<  red << c.getSuitSymbol() << def;
    } else {
	    os << c.getCardValue() << c.getSuitSymbol();
    }

    return os;
}

// std::ostream& operator<<(std::ostream& os, const Card& c)
// {
// 	Color::Modifier red(Color::FG_RED);
//     Color::Modifier def(Color::FG_DEFAULT);

//     if(c.suit == "Hearts" || c.suit == "Diamonds") {
//     	os << c.getSuitValue()  <<  red << c.getSuitSymbol() << def;
//     } else {
// 	    os << c.getSuitValue() << c.getSuitSymbol();
//     }

//     return os;
// }
