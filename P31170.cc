#include <iostream>
using namespace std;

int main() {
	int a;
    cin >> a;
    int b = 1;
    
    while (b<11) {
         cout << a << "*" << b << " = " << a*b << endl;
        b = b + 1;
    }
}
