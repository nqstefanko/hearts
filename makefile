hearts: hearts.cpp card.cpp deck.cpp
	clang++ -std=c++17 hearts.cpp card.cpp deck.cpp -o hearts
clean:
	rm hearts