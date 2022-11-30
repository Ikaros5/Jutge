#include <iostream>
using namespace std;

int main () {
    cout.setf(ios::fixed);
    cout.precision(2);

    string s;
    while (cin >> s and s != "acabar") {
        if (s == "perimetro" ) { 
            double a,b,c;
            double x = 0;
            cin >> a >> b >> c;
            x = a + b + c; 
            cout << x << endl;
        }
        else if (s == "area") {
            double b,h;
            double x = 0;
            cin >> b >> h;
            x = (b * h) / 2;
            cout << x << endl;
        }
    }
    
}
