//
// Created by nick on 4/20/20.
//

#ifndef HEARTS_PROJ_RANDOM_AI_H
#define HEARTS_PROJ_RANDOM_AI_H

#include <random>

#include "player.hpp"
#include "game.hpp"

class Random_AI: public Player {
public:
    Random_AI(std::string n);

    void performAction(Game & g);
};


#endif //HEARTS_PROJ_RANDOM_AI_H


//Encap:
//