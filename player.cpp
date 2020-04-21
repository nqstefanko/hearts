#include "player.hpp"


Player::Player(std::string n): score(0) {
    std::cout << "Initing Player " << n << std::endl;
    name = n;
}

void Player::recieveHand(std::vector<Card> v) {
    hand = v;
}

void Player::printHand() {
    std::cout << name << "'s " << hand.size() << " Card Hand: ";
    for (int i = 0; i < hand.size(); ++i) {
        if(i == hand.size() -1) {
            std::cout << hand[i] << std::endl;
        } else {
            std::cout << hand[i] << ", ";
        }
    }
}

struct less_than_key
{
    inline bool operator() (const Card& c1, const Card& c2)
    {
        if (c1.suit < c2.suit) return true;
        if (c2.suit < c1.suit) return false;

        // a=b for primary condition, go to secondary
        if (c1.value < c2.value) return true;
        if (c2.value < c1.value) return false;
    }
};


void Player::sortHand() {
    std::sort(hand.begin(), hand.end(), less_than_key());
}


void Player::recieveHand(Card c) {
    if(hand.size() >= 13) {
        PRINT_ERROR(ERROR: Tried to add cards to a full hand);
    } else {
        hand.push_back(c);
    }
}


//Poly
//Encap
//Abstract
//Virt
//Pure Virt
