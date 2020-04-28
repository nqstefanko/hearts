//
// Created by nick on 4/28/20.
//

#ifndef HEARTS_PROJ_HUMAN_PLAYER_HPP
#define HEARTS_PROJ_HUMAN_PLAYER_HPP
#include <iostream>
#include <algorithm>

#include "player.hpp"
#include "game.hpp"

class HumanAI: public Player {
public:
    HumanAI(std::string n);

    void performAction(Game & g);

    Card playCard(std::vector<std::pair<Card, int>> & goodCards, int suitLed=-1);

    void printIt(Game & g);
};

#endif //HEARTS_PROJ_HUMAN_PLAYER_HPP
