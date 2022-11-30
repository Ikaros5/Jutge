#include <iostream>
using namespace std;

void descompon(int n, int& h, int& m, int& s) {
		m = n / 60;
			s = n % 60;
				h = m / 60;
					m = m % 60;
}

/*
 * int main() {
 *     int n, h, m, s;
 *         while (cin >> n) {
 *                 descompon(n, h, m, s);
 *                         cout << h << " " << m << " " << s << endl;
 *                             }
 *                             }
 *                             */
