#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

struct Country {
	std::string name;
	int area;
};

Country multiply(Country lhs, int value) {
	Country country;
	country.name = lhs.name;
	country.area = lhs.area * value;
	return country;
}

int main() {
	std::vector <Country> countries = {
		{ "India", 3287 },{ "Argentina", 2780 },
		{ "Brazil", 8515 },{ "Australia", 7692 },
		{ "China", 9572 },{ "United States of America", 9525 },
		{ "Russia", 17098 },{ "Canada", 9984 },
		{ "Kazakhstan", 	2724 },{ "Algeria", 2381 }
	};
	std::vector<Country> countries_area_corrected(countries.size());
	transform(countries.begin(), countries.end(), countries_area_corrected.begin(), std::bind2nd(std::ptr_fun(multiply), 1000));
	for (auto country:countries_area_corrected) {
		std::cout << country.name << " " << country.area << std::endl;
	}
	return 0;
}
