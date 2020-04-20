#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <random>


#include "color.hpp"

#define SPADES "\u2660"
#define CLUBS "\u2663"
#define DIAMONDS "\u2666"
#define HEARTS "\u2665"

std::map<int, std::string> FACE_CARD_CONVERSION = {
	{11, "Jack"}, {12, "Queen"}, {13, "King"}, {14, "Ace"}};

std::map<std::string, const char *> SUIT_CONVERSION = {
	{"Spades", SPADES}, {"Clubs", CLUBS}, {"Diamonds", DIAMONDS}, {"Hearts", HEARTS}};

class Card {
public:
	std::string suit;
	int value;

	Card() {
		value = 0;
	}
	
	Card(int v, std::string s): value(v), suit(s) { }

	const char * getSuitSymbol() const {
		return SUIT_CONVERSION[suit];
	}

	const std::string getSuitValue() const {
		if(value > 10) {
			return FACE_CARD_CONVERSION[value];
		} else {
			return std::to_string(value);
		}
	}

};

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

std::vector<Card> DECK(52);
void makeDeck(std::vector<Card> & d) {
	int cardCount = 0;
	for (auto & m: SUIT_CONVERSION) {
		for(int i = 2; i < 15; ++i) {
			d[cardCount] = Card(i, m.first);
			cardCount++;
		}
	}
}

void shuffleDeck(std::vector<Card> & d) 
{ 
    // Initialize seed randomly 
    srand(time(0)); 
  
    for (int i=0; i<d.size() ;i++) 
    { 
        int r = i + (rand() % (52 - i));   
        std::swap(d[i], d[r]); 
    } 
} 



int main() {
	makeDeck(DECK);
	shuffleDeck(DECK);
	
	return 0;
}



// ♠ U+2660 Black Spade Suit
// ♡ U+2661 White Heart Suit
// ♢ U+2662 White Diamond Suit
// ♣ U+2663 Black Club Suit
// ♤ U+2664 White Spade Suit
// ♥ U+2665 Black Heart Suit
// ♦ U+2666 Black Diamond Suit
// ♧ U+2667 White Club Suit
