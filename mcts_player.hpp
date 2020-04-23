//
// Created by nick on 4/23/20.
//

#ifndef HEARTS_PROJ_MCTS_PLAYER_H
#define HEARTS_PROJ_MCTS_PLAYER_H

class MTCS_AI: public Player {

};

#endif //HEARTS_PROJ_MCTS_PLAYER_H


/*
 * 1. Tree Traversal (wi(# of wins for node after i simulation)/ni (# of simulations considered) +
 *                  c (exploration param(2**.5) * sqrt(ln(Ni # of total simulatiosn after ith move ran by parent node) /ni
 * 2. Node Expansion
 * 3. Rollout (Random Simulation)
 * 4. Backpropogation
 */