#include <iostream>
using namespace std;

int main() {
	int x, y;

	while (cin >> x >> y) {
		int n = 1, r = 1;
		while (n <= y) {
			r *= x;
			++n;
		}
		cout << r << endl;
	}
}
