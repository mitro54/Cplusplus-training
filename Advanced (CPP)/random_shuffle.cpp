#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int rng_function(int range) {
	return std::rand() % range;
}

int main()  {
	const unsigned RANDOM_SEED = 5;
	std::srand(RANDOM_SEED);
	std::vector<std::string> cards;
	std::vector<std::string> card_names={ "A", "2", "3", "4" , "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	for (auto name : card_names) {
		cards.push_back(name + "S");
		cards.push_back(name + "H");
		cards.push_back(name + "D");
		cards.push_back(name + "C");
	}
	std::vector<std::vector<std::string>> players(4);
	
	std::random_shuffle(cards.begin(), cards.end(), rng_function);
	for(unsigned i=0; i<cards.size(); ++i) {
		auto player_index = i % 4;
		players[player_index].push_back(cards[i]);
	}

	for (auto player : players) {
		for (auto card : player) {
			std::cout << card << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}
