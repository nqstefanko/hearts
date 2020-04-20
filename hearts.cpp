#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <random>

#include "card.hpp"

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

void printDeckSingleLine(std::vector<Card> & d) {
	for(int i = 0; i < d.size(); ++i) {
		if(i == d.size() -1) {
			std::cout << d[i] <<std::endl;
		} else {
			std::cout << d[i] << ", ";
		}		
	}
}

void printDeckNewLine(std::vector<Card> & d) {
	for(auto & c: d) {
		std::cout << c << std::endl;
	}
}

int main() {
	makeDeck(DECK);
	shuffleDeck(DECK);
	printDeckSingleLine(DECK);
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
