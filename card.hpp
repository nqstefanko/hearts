#ifndef CARD_H // include guard
#define CARD_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "color.hpp"

#define SPADES "\u2660"
#define CLUBS "\u2663"
#define DIAMONDS "\u2666"
#define HEARTS "\u2665"

inline std::map<int, std::string> FACE_CARD_CONVERSION = {
	{11, "Jack"}, {12, "Queen"}, {13, "King"}, {14, "Ace"}};

inline std::map<std::string, const char *> SUIT_CONVERSION = {
	{"Spades", SPADES}, {"Clubs", CLUBS}, {"Diamonds", DIAMONDS}, {"Hearts", HEARTS}};

class Card {
public:
	std::string suit;
	int value;

	Card();
	
	Card(int v, std::string s);

	const char * getSuitSymbol() const;

	const std::string getSuitValue() const;
};

std::ostream& operator<<(std::ostream& os, const Card& c);

#endif 