//
// Created by nick on 4/22/20.
//

#ifndef HEARTS_PROJ_LOW_AI_H
#define HEARTS_PROJ_LOW_AI_H

#include <random>

#include "player.hpp"
#include "game.hpp"

class Low_AI: public Player {
public:
    Low_AI(std::string n);

//    void performAction(Game & g);

    Card playCard(std::vector<std::pair<Card, int>> & goodCards,  int suitLed=-1);
};

#endif //HEARTS_PROJ_LOW_AI_H
