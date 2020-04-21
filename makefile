hearts: hearts.cpp deck.cpp card.cpp player.cpp game.cpp random_ai.cpp
	clang++ -std=c++17 hearts.cpp deck.cpp card.cpp player.cpp game.cpp random_ai.cpp -o hearts
clean:
	rm hearts