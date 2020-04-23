//
// Created by nick on 4/22/20.
//

#include "low_ai.hpp"

Low_AI::Low_AI(std::string n) : Player(n) {}

Card Low_AI::playCard(std::vector<std::pair<Card, int>> & goodCards, int suitLed){
    printHand();
    Card toPlay = goodCards[0].first;
    int i = 0;
    int toSave = 0;
    if(goodCards[0].first.suit != suitLed) {
        for(i = 0; i < goodCards.size(); ++i) {
            if(goodCards[i].first.suit == HEARTS) {
                toPlay = goodCards[i].first;
                toSave = goodCards[i].second;
            }
        }
    }

    if(i == goodCards.size()) {
        i = 0;
    }
//    hand.erase (hand.begin()+goodCards[randomLength].second);
    hand.erase (hand.begin()+goodCards[toSave].second);
    return toPlay;
}
