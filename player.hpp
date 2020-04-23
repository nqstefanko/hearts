#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "card.hpp"
//#include "game.hpp"

class Player {
public:
	std::string name;
	int score;
	std::vector<Card> hand;

	Player(std::string n);

    void recieveHand(std::vector<Card> v);

    void recieveHand(Card c);

    void printHand();

    void sortHand();

    bool checkSuit();

    Card playTwoOfClubs();

    virtual Card playCard(std::vector<std::pair<Card, int>> & goodCards, int suitLed=-1);

//    virtual void printIt(Game & g);

    ~Player();
};

#endif