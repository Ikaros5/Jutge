#include <iostream>
#include <vector>
using namespace std;

bool es_palindrom(const string& s) {
		int vs = s.size()-1;
			int zo = 0;
				while (vs != 0) {
							if (s[vs] != s[zo]) return false;
									vs--;
											zo++;
												}
					return true;
}

int main() {
		string x;
			while (cin >> x) cout << es_palindrom(x) << endl;
}
