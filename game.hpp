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
    int cycle = 0;
    bool heartsBroken = false;
    Deck deck;
    std::vector<Card> currentCycleCards;
    int suitLed = -1;

    std::vector<Player *> order;

    Game(Player * p1, Player * p2, Player * p3, Player * p4);

    std::vector<std::pair<Card, int>> getPlayableCards(std::vector<Card> & Hand);

    void addScores();

    void printScores();

    bool emptyOfSuit(int suitLed, std::vector<Card> & Hand);

    void playRound();

    void deal();

    bool checkCard(Card & c);
};


#endif //HEARTS_PROJ_GAME_H

//    std::vector<std::unique_ptr<Player>> order;
//    Game(std::unique_ptr<Player> & p1, std::unique_ptr<Player> & p2, std::unique_ptr<Player> & p3, std::unique_ptr<Player> & p4);
