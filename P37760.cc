#include <iostream>
#include <cmath>
using namespace std;
int main () {

    double n;

    while (cin >> n)   {

        cout.setf(ios::fixed);
        cout.precision(6);

        n = (n*M_PI) / 180;

        cout << sin(n) << " " << cos(n) << endl;



}
}
