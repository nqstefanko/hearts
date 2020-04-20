#ifndef CARD_H // include guard
#define CARD_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "color.hpp"

enum {SPADES, CLUBS, DIAMONDS, HEARTS};

#define PRINT_ERROR(x) std::cout <<	Color::Modifier(Color::FG_RED) << #x << Color::Modifier(Color::FG_DEFAULT) << std::endl

#define U_SPADES "\u2660"
#define U_CLUBS "\u2663"
#define U_DIAMONDS "\u2666"
#define U_HEARTS "\u2665"

inline std::map<int, std::string> FACE_CARD_CONVERSION = {
	{11, "Jack"}, {12, "Queen"}, {13, "King"}, {14, "Ace"}};

inline std::map<int, const char *> SUIT_CONVERSION = {
	{SPADES, U_SPADES}, {CLUBS, U_CLUBS}, {DIAMONDS, U_DIAMONDS}, {HEARTS, U_HEARTS}};

class Card {
public:
	int suit;
	int value;

	Card();
	
	Card(int v, int s);

	const char * getSuitSymbol() const;

	const std::string getCardValue() const;

	bool hasPoints();

};

std::ostream& operator<<(std::ostream& os, const Card& c);

#endif 