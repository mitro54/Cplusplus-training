#include <iostream>

using namespace std;

int main(void) {
    int size;
    cout << "Provide a size for the rectangle: ";
    cin >> size;
	cout << '+';
	for(int i = 0; i < size; i++)
		cout << '-';
	cout << '+' << endl;
	for(int i = 0; i < size; i++) {
		cout << '|';
		for(int j = 0; j < size; j++)
			cout << ' ';
		cout << '|' << endl;
	}
	cout << '+';
	for(int i = 0; i < size; i++)
		cout << '-';
	cout << '+' << endl;
	return 0;
}