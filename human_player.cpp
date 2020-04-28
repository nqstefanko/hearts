//
// Created by nick on 4/28/20.
//

#include "human_player.hpp"

HumanAI::HumanAI(std::string n) : Player(n) {}

void printPlayableCards(std::vector<std::pair<Card, int>> & goodCards) {
    std::cout << "Playable Cards: ";
    for(int i = 0; i < goodCards.size(); ++i) {
        std::cout << i + 1 << ": " << goodCards[i].first << ", ";
    }
    std::cout << std::endl;
}


Card HumanAI::playCard(std::vector<std::pair<Card, int>> & goodCards, int suitLed) {
    printHand();
    printPlayableCards(goodCards);
    int numSelected = -1;
    std::cout << "Enter a Card # please: ";
    while(!(std::cin >> numSelected)) {
        std::cout << "Error: Enter a Valid Number between 1 - " << goodCards.size() << std::endl;
        std::cout << "Enter a Card # please: ";
        std::cin.clear();
        std::cin.ignore(123, '\n');
    }
    Card toPlay = goodCards[numSelected - 1].first;
    hand.erase(hand.begin()+goodCards[numSelected - 1].second);
    return toPlay;
}