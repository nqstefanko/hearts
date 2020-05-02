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
    for(int i = 0; i < order.size(); ++i) { //For each Player
        for(int j = 0; j < 13; ++j) { //Deal 13 Cards
            Card toDeal = deck[(13 * i)  + j];
            if(toDeal.suit == CLUBS && toDeal.value == 2) {
                firstPlayer = i; //Get first player
            }
            order[i]->recieveHand(toDeal);
        }
        order[i]->sortHand();
    }
    std::cout << "Done Dealing" << std::endl;
}

void Game::playRound() {
//    order[0]->printThis(this);
    for(; cycle < 13; ++cycle) {
        std::cout << "CYCLE " << cycle << std::endl;
        currentCycleCards.clear();
        for(int j = 0; j <4; ++j) {
            int toPlay = (firstPlayer + j) % 4;
            if(cycle == 0 && j == 0) {
                Card playedCard = order[toPlay]->playTwoOfClubs();
                std::cout << order[toPlay]->name << " Played " << playedCard << std::endl;
                suitLed = CLUBS;
                currentCycleCards.push_back(playedCard);
            } else {
                std::vector<std::pair<Card, int>> goodCards = getPlayableCards(order[toPlay]->hand);
                Card playedCard = order[toPlay]->playCard(goodCards);
                std::cout << order[toPlay]->name << " Played " << playedCard << std::endl;
                if(j == 0) {
                    suitLed = playedCard.suit;
                }
                currentCycleCards.push_back(playedCard);
            }
        }
        addScores();
        suitLed = -1;
        printScores();
    }
}

void Game::addScores() {
    int maxCardIndex = -1;
    int totalScore = 0;
    int maxValue = 0;
    for(int i = 0; i < 4; ++i) {
        if(currentCycleCards[i].suit == suitLed && currentCycleCards[i].value > maxValue) {
            maxValue=currentCycleCards[i].value;
            maxCardIndex = i;
        }
        if(currentCycleCards[i].suit == HEARTS) {
            totalScore+=1;
        }
        if(currentCycleCards[i].suit == SPADES && currentCycleCards[i].value == 12) {
            totalScore+=13;
        }
    }
    order[(firstPlayer + maxCardIndex) % 4]->score+=totalScore;
}

void Game::printScores() {
    for(int i = 0; i < 4; ++i) {
        std::cout <<"P" << i + 1 << ": " << order[i]->score << "  ";
    }
    std::cout << std::endl;
}

bool Game::emptyOfSuit(int suitLed, std::vector<Card> & Hand) {
    if(suitLed == -1 && heartsBroken == false) {
        for(auto & c: Hand) {
            if(c.suit != HEARTS) {
                return false;
            }
        }
        heartsBroken = true;
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

