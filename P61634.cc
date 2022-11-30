#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;

	string isleap;
	if ((x % 4 == 0 and x % 100 != 0) or (x % 100 == 0 and (x / 100 % 4) == 0)) isleap = "YES";
	else isleap = "NO";

	cout << isleap << endl;
}
