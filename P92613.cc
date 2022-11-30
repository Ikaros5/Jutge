#include <iostream>
using namespace std;

int main() {
	double a;
	cin >> a;
	cout << int(a) << ' ';
	double aux = a-int(a);
	if (aux != 0) cout << int(a)+1 << ' ';
	else cout << int(a) << ' ';
	if (aux >= 0.5) cout << int(a)+1 << endl;
	else cout << int(a) << endl;
}
