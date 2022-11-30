#include <iostream>
using namespace std;

int factorial(int n) {
		int r = 1;
			for (int i = 1; i <= n; i++) r *= i;
				return r;
}

/*
 * int main() {
 *     int x;
 *         while (cin >> x) cout << factorial(x) << endl;
 *         }
 *         */
