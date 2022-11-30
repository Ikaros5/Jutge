#include<iostream>
#include<vector>
using namespace std;

typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<char> VC;
typedef vector<VC> VVC;

void write(VC &sol) {
    int n = sol.size();
    for(int i = 0; i < n; i++) cout << sol[i];
    cout << endl;
}

void back(VC &especies, VB &usado, VVB &incompatible, VC &sol, bool first, int x, int i) {
    int n = especies.size();
    if(i == n) write(sol);
    else {
        for(int j = 0; j < n; j++) {
            if(not usado[j] and (first or not incompatible[x][j])) {
                usado[j] = true;
                sol[i] = especies[j];
                back(especies, usado, incompatible, sol, false, j, i+1);                
                usado[j] = false;
                sol[i] = ' ';
            }
        }
    }
}

int main() {
    int n, m;
    char a, b;
    cin >> n;
    VC especies(n);
    VC sol(n);
    VB usado(n, false);
    VVB incompatible(n, VB(n, false));
    for(int i = 0; i < n; i++) {
        cin >> especies[i];
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        int pos1, pos2;
        for(int j = 0; j < n; j++) {
            if(especies[j] == a) pos1 = j;
            if(especies[j] == b) pos2 = j;
        }
        // cout << "especie A: " << a << " especie B: " << b << " posicions: " << pos1 << " " << pos2 << endl;
        incompatible[pos1][pos2] = true;
        incompatible[pos2][pos1] = true;
        
    }
    // cout << "INCOMPATIBLES:" << endl;
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         if(incompatible[i][j]) cout << especies[i] << especies[j] << " ";
    //     }
    // }
    back(especies, usado, incompatible, sol, true, 0, 0);
}