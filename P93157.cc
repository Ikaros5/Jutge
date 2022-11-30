#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool read_rational(int& num, int& den) {
    char c;
    if(cin >> num >> c >> den) {
        int d = __gcd(num, den);
        num = num / d;
        den = den / d;
        return true;
    }
    return false;
}

int main() {
	int num, den;
	while (read_rational(num, den)) cout << num << ' ' << den << endl;
}