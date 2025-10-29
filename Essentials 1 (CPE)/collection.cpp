#include <iostream>
#include <cstdlib>
#include <ctime>

struct Collection {
	int elno;
	int	*elements;
};

void add_to_collection(Collection &col, int element) {
	if (col.elno == 0) {
		col.elements = new int[1];
		col.elements[0] = element;
		col.elno++;
	} else {
		int *temp_arr = new int[col.elno + 1];
		for (int i = 0; i < col.elno; i++)
			temp_arr[i] = col.elements[i];

		temp_arr[col.elno] = element;
		delete[] col.elements;
		col.elements = temp_arr;
		col.elno++;
	}
}

void print_collection(Collection col) {
	std::cout << "[ ";
	for(int i = 0; i < col.elno; i++)
		std::cout << col.elements[i] << " ";
	std::cout << "]" << std::endl;
}

int main(void) {
	Collection collection = { 0, NULL };
	int elems;
	std::cout << "How many elements? ";
	std::cin >> elems;
	srand(time(NULL));

	for(int i = 0; i < elems; i++)
		add_to_collection(collection, rand() % 100 + 1);
	print_collection(collection);
	delete[] collection.elements;
	return 0;
}