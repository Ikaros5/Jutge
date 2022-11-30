#include <iostream>
using namespace std;

int main() {
	char r;
	cin >> r;

	if (r >= 'a' and r <= 'z') cout << "lowercase" << endl;
	if (r >= 'A' and r <= 'Z') cout << "uppercase" << endl;

	if (r == 'A' or r == 'E' or r == 'I' or r == 'O' or r == 'U' or r == 'a' or r == 'e' or r == 'i' or r == 'o' or r == 'u') cout << "vowel" << endl;
	else cout << "consonant" << endl;
}
