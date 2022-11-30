#include<iostream>
#include<vector>
using namespace std;

typedef vector<bool> VB;
typedef vector<VB> VVB;

void write(VVB &tablero) {
    for(uint i = 0; i < tablero.size(); i++) {
        for(uint j = 0; j < tablero[0].size(); j++) {
            if(tablero[i][j]) cout << "R";
            else cout << ".";
        }
        cout << endl;
    }
    cout << endl;
}

void rooks(VVB &sol, VB &rows, VB &cols, int n, int m, int i) {
    if(i == n) write(sol);
    else {
        for(int j = 0; j < m; j++) {
            if(not rows[i] and not cols[j]) {
                rows[i] = true;
                cols[j] = true;
                sol[i][j] = true;
                rooks(sol, rows, cols, n, m, i+1);
                rows[i] = false;
                cols[j] = false;
                sol[i][j] = false;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    VB rows(n, false);
    VB cols(m, false);
    VVB sol(n, VB(m, false));
    rooks(sol, rows, cols, n, m, 0);
}