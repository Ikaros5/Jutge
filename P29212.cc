#include<iostream>
using namespace std;

//calcula n^k de manera eficiente
int exponenciacion_rapida_mod(int n, int k, int m) {
    if(k == 0) return 1;
    int calc = exponenciacion_rapida_mod(n, k/2, m);
    if(k % 2 == 0) return (calc*calc) % m;
    else return ((calc*calc) % m * n) % m;
}

int main() {
    int n, k, m;
    while(cin >> n >> k >> m) cout << exponenciacion_rapida_mod(n, k, m) << endl;
}