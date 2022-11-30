#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<list>
using namespace std;
typedef vector<list<int>> graph;
typedef pair<int, int> P;
typedef vector<P> VP;
typedef vector<VP> VVP;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef vector<VS> VVS;

void write(VC &sol) {
    for(int i = 0; i < sol.size(); i++) {
        cout << sol[i];
    }
    cout << endl;
}

void back(VC &sol, int n, int c, int a, int i) {
    if(i == n) write(sol);
    else {
        if(c > 0) {
            // cout << "ENTRO B" << endl;
            sol[i] = 'b';
            back(sol, n, c-1, a+1, i+1);
        }
        if(a > 0) {
            // cout << "ENTRO S" << endl;
            sol[i] = 's';
            back(sol, n, c+1, a-1, i+1);
        }
    }
}

int main() {
    int n, c, a = 0;
    cin >> n >> c;
    VC sol(n);
    back(sol, n, c, a, 0);
}