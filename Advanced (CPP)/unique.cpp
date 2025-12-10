#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Pet {
private:
	std::string name;
	std::string pet_type;
public:
	Pet(std::string name, std::string pet_type) :name(name), pet_type(pet_type) {}
	Pet() {}
	std::string get_name() const {
		return name;
	}
	std::string get_type() const {
		return pet_type;
	}
};

struct Equal {
	bool operator()(const Pet & lhs, const Pet & rhs) const {
		return lhs.get_name() == rhs.get_name();
	}
};

int main() {
	std::vector<Pet> pets = { {"Amber", "Cat"}, {"Barky", "Dog"}, { "Barky", "Reptile" }, 
		{"Casper", "Fish"}, {"Casper", "Reptile"}, {"Godzilla", "Reptile" } };
	std::vector<Pet> uniquePets(pets.size());

	auto petsEnd = unique_copy(pets.begin(), pets.end(), uniquePets.begin(), Equal());
	for (auto pet : pets) {
		std::cout << pet.get_name() << " " << pet.get_type() << '\n';
	}
	std::cout << '\n';
	for (auto pet = uniquePets.begin() ; pet != petsEnd ; ++pet) {
		std::cout << pet->get_name() << " " << pet->get_type() << '\n';
	}

	return 0;
}
