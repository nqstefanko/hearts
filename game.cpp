//
// Created by nick on 4/20/20.
//
#include "game.hpp"

Game::Game(Player * p1, Player * p2, Player * p3, Player * p4): deck() {
    std::cout << "Game Being Initialized" << std::endl;
    order.push_back(p1);
    order.push_back(p2);
    order.push_back(p3);
    order.push_back(p4);

    deck.shuffleDeck();
    deal();
}

void Game::deal() {
    for(int i = 0; i < order.size(); ++i) {
        for(int j = 0; j < 13; ++j) {
            if(order[i].suit == CLUBS && order[i].value == 2) {
                firstPlayer = i;
            }
            order[i]->recieveHand(deck[(13 * i)  + j]);
        }
    }
    std::cout << "Done Dealing" << std::endl;
}

void playGame() {
    for(int i = 0; i < 13; ++i) {
        for(int j = 0; j < 4; ++j) {
            std::vector<Card> getPlayableCards(order[i]);
            order[i]->playCard();
        }
    }
}

bool emptyOfSuit(int suitLed, std::vector<Card> & Hand) {
    for(auto & c: Hand) {
        if(c.suit == suitLed) {
            return false;
        }
    }
    return true;
}

std::vector<Card> Game::getPlayableCards(std::vector<Card> Hand) {
    std::vector<Card> toRet;

    for (auto & c : Hand) {
        if(checkCard(c) || emptyOfSuit(suitLed, Hand)) {
            toRet.push_back(c);
        }
    }

    return toRet;
}

bool Game::checkCard(Card & c) {
    if(c.suit == HEARTS && heartsBroken == false) {
        return false;
    }
    if(suitLed == -1 || suitLed == c.suit) {
        return true;
    } else {
        return false;
    }
}

