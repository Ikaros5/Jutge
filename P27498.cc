#include <iostream>
#include <vector>
using namespace std;

typedef vector <vector <int> >Matriu;

void transposa(Matriu& m) {
	Matriu m1(m.size(), vector <int>(m.size()));
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m.size(); j++) m1[i][j] = m[j][i];
	}
	m = m1;
}

int main() {
	int x;
	cin >> x;
	Matriu Mat(x, vector <int>(x));

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) cin >> Mat[i][j];
	}

	transposa(Mat);
	bool first = true;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			if (not first) cout << ' ';
			cout << Mat[i][j];
			first = false;
		}
		first = true;
		cout << endl;
	}
}
