#include "game.hpp"
#include "random_ai.hpp"

int main() {

    Random_AI p1("Player 1");
    Random_AI p2("Player 2");
    Random_AI p3("Player 3");
    Random_AI p4("Player 4");

    Random_AI * pp1 = &p1;
    Random_AI * pp2 = &p2;
    Random_AI * pp3 = &p3;
    Random_AI * pp4 = &p4;

    Game g(pp1, pp2, pp3, pp4);

    g.playRound();

    std::cout << "Done with Program!" << std::endl;
    return 0;
}




//Working on it

//Hearts:
//Deal in rotation and play cards
//Count Turn




// ♠ U+2660 Black Spade Suit
// ♡ U+2661 White Heart Suit
// ♢ U+2662 White Diamond Suit
// ♣ U+2663 Black Club Suit
// ♤ U+2664 White Spade Suit
// ♥ U+2665 Black Heart Suit
// ♦ U+2666 Black Diamond Suit
// ♧ U+2667 White Club Suit



//    std::unique_ptr<Player> u1(new Random_AI("Player 1"));
//    std::unique_ptr<Player> u2(new Random_AI("Player 2"));
//    std::unique_ptr<Player> u3(new Random_AI("Player 3"));
//    std::unique_ptr<Player> u4(new Random_AI("Player 4"));
//
//    Game g(u1, u2, u3, u4);
//    u1->printHand();
