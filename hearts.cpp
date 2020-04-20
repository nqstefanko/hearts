#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <random>

#include "card.hpp"
#include "deck.hpp"

int main() {
	
	Deck d;
	d.shuffleDeck();
	d.printDeckSingleLine();
	
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
