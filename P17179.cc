#include <iostream>
using namespace std;

int main() {
		cout.setf(ios::fixed);
			cout.precision(4);

				int n, n1;
					double x, total = 0, min = 0, max = 0, c = 1;

						cin >> n;
							for (int i = 0; i < n; ++i) {
										c = 1;
												cin >> n1;

														cin >> x;
																max = min = total = x;
																		for (int j = 1; j < n1; j++) {
																						cin >> x;
																									if (x > max) max = x;
																												if (x < min) min = x;
																															total += x;
																																		c++;
																																				}
																				cout << min << ' ' << max << ' ' << total / c << endl;
																					}
}
