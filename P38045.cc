#include <iostream>
#include <cmath>
using namespace std;
int main () {

    double n;

    while (cin >> n)   {

        cout.setf(ios::fixed);
        cout.precision(0);

        cout << pow(n, 2) << " ";

        cout.setf(ios::fixed);
        cout.precision(6);

        cout << sqrt(n) << endl;

    }



}
