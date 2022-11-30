#include <iostream>
#include <vector>
using namespace std;

void permutacions(int n, int i, string sol) {
	if(i == n) {
		cout << sol[0];
		for(int j = 1; j < n; j++) {
			cout << " " << sol[j];
		}
		cout << endl;
	}
	else {
		sol[i] = '0';
		permutacions(n, i+1, sol);
		sol[i] = '1';
		permutacions(n, i+1, sol);
	}
}

int main() {
	int n;
	cin >> n;
	string sol(n, ' ');
	permutacions(n, 0, sol);
}