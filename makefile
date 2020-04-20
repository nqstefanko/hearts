hearts: hearts.cpp deck.cpp card.cpp player.cpp game.cpp
	clang++ -std=c++17 hearts.cpp deck.cpp card.cpp player.cpp game.cpp -o hearts
clean:
	rm hearts