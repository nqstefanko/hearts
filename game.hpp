//
// Created by nick on 4/20/20.
//

#ifndef HEARTS_PROJ_GAME_H
#define HEARTS_PROJ_GAME_H

#include <vector>

#include "deck.hpp"
#include "player.hpp"

class Game {
public:
    int firstPlayer = 0;
    int turn = 0;
    bool heartsBroken = false;
    Deck deck;
    int suitLed = -1;
    std::vector<Player> order;

    Game(Player & p1, Player & p2, Player & p3, Player & p4);

    std::vector<Card> getPlayableCards(std::vector<Card> Hand);

    bool checkCard(Card & c);

};


#endif //HEARTS_PROJ_GAME_H
