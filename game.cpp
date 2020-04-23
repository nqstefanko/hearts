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
            Card toDeal = deck[(13 * i)  + j];
            if(toDeal.suit == CLUBS && toDeal.value == 2) {
                firstPlayer = i;
            }
            order[i]->recieveHand(toDeal);
        }
        order[i]->sortHand();

    }

    std::cout << "Done Dealing" << std::endl;
}

void Game::playRound() {
    for(; turn < 13; ++turn) {
        std::cout << "TURN " << turn << std::endl;
        for(int j = 0; j <4; ++j) {
            int toPlay = (firstPlayer + j) % 4;
            if(turn == 0 && j == 0) {
                Card playedCard = order[toPlay]->playTwoOfClubs();
                std::cout << order[toPlay]->name << " Played " << playedCard << std::endl;
                suitLed = CLUBS;
            } else {
                std::vector<std::pair<Card, int>> goodCards = getPlayableCards(order[toPlay]->hand);
                Card playedCard = order[toPlay]->playCard(goodCards);
                std::cout << order[toPlay]->name << " Played " << playedCard << std::endl;
                if(j == 0) {
                    suitLed = playedCard.suit;
                }
            }
        }
        suitLed = -1;
    }
}

bool Game::emptyOfSuit(int suitLed, std::vector<Card> & Hand) {
    if(suitLed == -1 && heartsBroken == false) {
        for(auto & c: Hand) {
            if(c.suit != HEARTS) {
                return false;
            }
        }
        return true;

    } else {
        for(auto & c: Hand) {
            if (c.suit == suitLed) {
                return false;
            }
        }
    }

    return true;
}

std::vector<std::pair<Card, int>> Game::getPlayableCards(std::vector<Card> & Hand) {
    std::vector<std::pair<Card, int>> toRet;
    int countFound = 0;
    for (int i = 0; i < Hand.size(); ++i) {
        if(checkCard(Hand[i]) || emptyOfSuit(suitLed, Hand)) {
            toRet.push_back(std::make_pair(Hand[i], i) );
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

