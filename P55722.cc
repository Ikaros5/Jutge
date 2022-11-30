#include <iostream>

using namespace std;

int nombre_digits(int n) {
		int r = 1;
			while (n >= 10) {
						n /= 10;
								r++;
									}
				return r;
}

/*
 * int main() {
 *     int n;
 *         while (cin >> n) cout << nombre_digits(n) << endl;
 *         }
 *         */
