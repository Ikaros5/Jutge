#include <iostream>
using namespace std;

int main() {
	int a, b;
    cin >> a >> b;

    if (a>b) {
        while (a!=b) {
     cout << a << endl;
     a--;
    } 
        cout << a << endl;
    }

    else {
       while (a!=b) {
        cout << b << endl;
        b--;  }

        cout << b << endl;
    }

}

