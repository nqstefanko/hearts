#include "card.hpp"


Card::Card() {
	value = 0;
}

Card::Card(int v, std::string s): value(v), suit(s) { }

const char * Card::getSuitSymbol() const {
	return SUIT_CONVERSION[suit];
}

const std::string Card::getSuitValue() const {
	if(value > 10) {
		return FACE_CARD_CONVERSION[value];
	} else {
		return std::to_string(value);
	}
}


std::ostream& operator<<(std::ostream& os, const Card& c)
{
	Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);

    if(c.suit == "Hearts" || c.suit == "Diamonds") {
    	os << c.getSuitValue()  <<  red << c.getSuitSymbol() << def;
    } else {
	    os << c.getSuitValue() << c.getSuitSymbol();
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
