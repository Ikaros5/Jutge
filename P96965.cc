#include <iostream>
using namespace std;

int reduccio_digits(int x) {
	int y = 0;
		if (x < 10) return x;
		else
		y = (x % 10) + reduccio_digits(x / 10);
			if (y < 10) return y;
			else return (y % 10) + reduccio_digits(y / 10);
}




int main () {
		int f;
			cin >> f;
				cout << reduccio_digits(f) << endl;




}

