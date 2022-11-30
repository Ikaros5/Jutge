#include<iostream>
using namespace std;
 
int main() {
    int n, x = 0; 
    cin >> n; 
    cout << "0";
    for(int i = 1; i <= n; i++) {
        cout << "," << i*i*i; 
    }
    cout << endl;
}