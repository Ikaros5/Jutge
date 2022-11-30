#include<iostream>
using namespace std;

int main() {
    int a, b; 
    cin >> a >> b; 
    if(a <= b) {
        cout << a;
        a++;
        while(a <= b) {
            cout << "," << a;
            a++;
        }
        cout << endl;
    }
    else cout << endl;
}