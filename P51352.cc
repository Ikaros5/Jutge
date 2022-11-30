#include <iostream>
using namespace std;

int main() {
	char a, b, r;
	cin >> a >> b;

	if ((a == 'A' and b == 'P') or (a == 'P' and b == 'V') or (a == 'V' and b == 'A')) r = '1';
	else if (a == b) r = '-';
	else r = '2';

	cout << r << endl;
}
