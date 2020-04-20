#include "deck.hpp"

Deck::Deck(): allCards(52) {
	int cardCount = 0;
	for (auto & m: SUIT_CONVERSION) {
		for(int i = 2; i < 15; ++i) {
			allCards[cardCount] = Card(i, m.first);
			cardCount++;
		}
	}
}

void Deck::shuffleDeck() 
{ 
    // Initialize seed randomly 
    srand(time(0)); 
  
    for (int i=0; i<allCards.size() ;i++) 
    { 
        int r = i + (rand() % (52 - i));   
        std::swap(allCards[i], allCards[r]); 
    } 
} 

void Deck::printDeckSingleLine() {
	for(int i = 0; i < allCards.size(); ++i) {
		if(i == allCards.size() -1) {
			std::cout << allCards[i] <<std::endl;
		} else {
			std::cout << allCards[i] << ", ";
		}		
	}
}

void Deck::printDeckNewLine() {
	for(auto & c: allCards) {
		std::cout << c << std::endl;
	}
}