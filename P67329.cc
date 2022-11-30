#include<iostream>
#include<vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;

void back(VC &sol, int n, int i) {
    if(i == n) {
        for(int j = 0; j < n; ++j) {
            cout << sol[j];
        }
        cout << endl;
    }
    else {
        sol[i] = 'A';
        back(sol, n, i+1);
        sol[i] = 'C';
        back(sol, n, i+1);
        sol[i] = 'G';
        back(sol, n, i+1);
        sol[i] = 'T';
        back(sol, n, i+1);
    }
}

int main() {
    int n;
    cin >> n;
    VC sol(n);
    VC adn(4);
    back(sol, n, 0);
}