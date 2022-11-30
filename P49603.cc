#include <iostream>
using namespace std;

int main() {
		string prev, next;
			int n, c = 1, ultim = 0;
				while (cin >> n) {
							bool creixent = true;
									if (n > 0) cin >> prev;
											for (int i = 1; i < n; ++i) {
															cin >> next;
																		if (next < prev) creixent = false;
																					prev = next;
																							}
													if (creixent) ultim = c;
															++c;
																}
					if (ultim != 0) cout << "L'ultima linia ordenada creixentment es la " << ultim << "." << endl;
						else cout << "No hi ha cap linia ordenada creixentment." << endl;
}
