//
// Created by nick on 4/20/20.
//

#ifndef HEARTS_PROJ_GAME_H
#define HEARTS_PROJ_GAME_H

#include <vector>
#include <memory>

#include "deck.hpp"
#include "player.hpp"

class Game {
public:
    int firstPlayer = 0;
    int turn = 0;
    bool heartsBroken = false;
    Deck deck;
    int suitLed = -1;
//    std::vector<std::unique_ptr<Player>> order;
    std::vector<Player *> order;

//    Game(std::unique_ptr<Player> & p1, std::unique_ptr<Player> & p2, std::unique_ptr<Player> & p3, std::unique_ptr<Player> & p4);
    Game(Player * p1, Player * p2, Player * p3, Player * p4);

    std::vector<Card> getPlayableCards(std::vector<Card> Hand);

    void playRound();

    void deal();

    bool checkCard(Card & c);
};


#endif //HEARTS_PROJ_GAME_H
