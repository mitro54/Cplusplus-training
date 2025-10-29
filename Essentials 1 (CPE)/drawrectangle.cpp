#include <iostream>

using namespace std;

int main(void) {
    int size;
    cout << "Provide a size for sides of the rectangle: ";
    cin >> size;
    if (size >= 0) {
    size -= 2;
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
    } else {
        cout << "Only positive integers allowed.";
    }
	return 0;
}