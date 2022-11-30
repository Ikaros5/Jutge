#include <iostream>
using namespace std;

int main() {
		int x, n, max;

			while (cin >> x) {
						cin >> max;
								for (int i = 1; i < x; i++) {
												cin >> n;
															if (n > max) max = n;
																	}
										cout << max << endl;
											}
}
