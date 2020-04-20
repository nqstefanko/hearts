hearts: hearts.cpp card.cpp
	clang++ -std=c++17 hearts.cpp card.cpp  -o hearts
clean:
	rm hearts