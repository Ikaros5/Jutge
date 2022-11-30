#include <iostream>
using namespace std;

int main() {
		string prev, next;
			int n, i = 1;
				bool creixent = false;
					while (cin >> n and not creixent) {
								creixent = true;
										cin >> prev;
												for (int c = 2; c <= n; ++c) {
																cin >> next;
																			if (next < prev) creixent = false;
																						prev = next;
																								}
														if (creixent) cout << "La primera linia ordenada creixentment es la " << i << "." << endl;
																++i;
																	}
						if (not creixent) cout << "No hi ha cap linia ordenada creixentment." << endl;
}
