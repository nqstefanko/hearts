//
// Created by nick on 4/20/20.
//


#include "game.hpp"


Game::Game(Player & p1, Player & p2, Player & p3, Player & p4): deck() {
    std::cout << "Game Being Initialized" << std::endl;
    order.push_back(p1);
    order.push_back(p2);
    order.push_back(p3);
    order.push_back(p4);
}

std::vector<Card> Game::getPlayableCards(std::vector<Card> Hand) {
    std::vector<Card> toRet;
    for (auto & c : Hand) {
        if(checkCard(c)) {
            toRet.push_back(c);
        }
    }

    return toRet;
}

bool Game::checkCard(Card & c) {
    if(c.hasPoints() && heartsBroken == false) {
        return false;
    }
    if(suitLed == -1 || suitLed == c.suit) {
        return true;
    } else {
        return false;
    }
}
