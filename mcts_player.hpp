//
// Created by nick on 4/23/20.
//

#ifndef HEARTS_PROJ_MCTS_PLAYER_H
#define HEARTS_PROJ_MCTS_PLAYER_H

class MTCS_AI: public Player {


};

#endif //HEARTS_PROJ_MCTS_PLAYER_H

/*
 *
 * def rollout:
 *  while true:
 *     if Si is in terminal state:
 *          return val(Si)
 *     Ai = random_available_actions(Si))
 *     S = Simulate(Ai, Si)
 */


/*
 * 1. Tree Traversal (wi(# of wins for node after i simulation)/ni (# of simulations considered) +
 *                  c (exploration param(2**.5) * sqrt(ln(Ni # of total simulatiosn after ith move ran by parent node) /ni
 *
 *                  Exploit + Explore
 * 2. Node Expansion
 * 3. Rollout (Random Simulation)
 * 4. Backpropogation
 */