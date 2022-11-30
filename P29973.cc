#include <iostream>
using namespace std;

int main() {
	int x, c = 1;
	cin >> x;

	while (c <= x) {
		int a = 0;

		while (a < c) {
			cout << "*";
			++a;
		}

		cout << endl;
		++c;
	}
}
