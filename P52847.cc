#include<iostream>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    cout << max(max(x, y), z) << endl;
}