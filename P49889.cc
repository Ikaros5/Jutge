#include<iostream>
#include<vector>
using namespace std;

typedef vector<char> VC;
typedef vector<bool> VB;

void write(VC &sol) {
    int n = sol.size();
    for(int i = 0; i < n; i++) cout << sol[i];
    cout << endl;
}

void back(VC &c, VC &v, VB &usedc, VB &usedv, VC &sol, bool consonante, int i) {
    int n = c.size();
    if(i == n*2) write(sol);
    else {
        if(consonante) {
            for(int j = 0; j < n; j++) {
                if(not usedc[j]) {
                    usedc[j] = true;
                    sol[i] = c[j];
                    back(c, v, usedc, usedv, sol, false, i+1);
                    usedc[j] = false;
                    sol[i] = ' ';
                }
            }
        }
        else {
            for(int j = 0; j < n; j++) {
                if(not usedv[j]) {
                    usedv[j] = true;
                    sol[i] = v[j];
                    back(c, v, usedc, usedv, sol, true, i+1);
                    usedv[j] = false;
                    sol[i] = ' ';
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    VC vocals(n);
    VB usedv(n, false);
    VC consonants(n);
    VB usedc(n, false);
    VC sol(2*n);
    for(int i = 0; i < n; i++) {
        cin >> consonants[i];
    }    
    for(int i = 0; i < n; i++) {
        cin >> vocals[i];
    }
    back(consonants, vocals, usedc, usedv, sol, true, 0);
}