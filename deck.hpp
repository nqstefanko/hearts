#ifndef DECK_H // include guard
#define DECK_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "card.hpp"

class Deck {
public:
	std::vector<Card> allCards;

	Deck();

	void shuffleDeck();

	void printDeckSingleLine();

	void printDeckNewLine();
};


#endif