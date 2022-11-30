#include <iostream>
using namespace std;

int main () {
    double a;
    double total = 0;
    double mitjana;
    int n = 0;
    
    cout.setf(ios::fixed);
	cout.precision(2);
    
   while (cin >> a) {
        total = total + a;
        n++;
   }

mitjana = total / n;
cout << mitjana << endl;
}
