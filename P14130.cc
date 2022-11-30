#include <iostream>
#include <vector>
using namespace std;

int main () {
int n, a;
cin >> n;

vector<int>S(n);

for(int i=0; i<n; i++) {
    cin >> a;
    S[i] = a;
}

int last = S[n-1];
int contador = 0;

for(int j=0; j<n; j++) {
    if (S[j] == last) {contador++;}
}
cout << contador-1 << endl;
}
