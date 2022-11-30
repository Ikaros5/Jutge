#include<iostream>
using namespace std;
 
int main() {
    int x, y;
    cin >> x >> y;
    int a = x / y;
    int b = x % y;

    if(b < 0) {
        a--;
        b = x-a*y;
    }

    cout << a << " " << b << endl;
}