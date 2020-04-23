//
// Created by nick on 4/20/20.
//

#include "random_ai.hpp"

Random_AI::Random_AI(std::string n) : Player(n) {}

Card Random_AI::playCard(std::vector<std::pair<Card, int>> & goodCards, int suitLed) {
    printHand();
    int randomLength = rand() % goodCards.size();
    Card toPlay = goodCards[randomLength].first;
    hand.erase (hand.begin()+goodCards[randomLength].second);
    return toPlay;
}

void Random_AI::printIt(Game & g) {
    std::cout << "FUCK ME" <<  g.firstPlayer << std::endl;
}


//void Random_AI::performAction(Game & g) {
//    std::vector<Card> playableCards = g.getPlayableCards();
//
//}

