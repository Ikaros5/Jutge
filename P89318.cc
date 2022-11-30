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

void write(VC &sol) {
    for(int i = 0; i < sol.size(); i++) {
        cout << sol[i];
    }
    cout << endl;
}

void back(VC &alfabet, VB &usado, VC &sol, int n, int i) {
    if(i == n) write(sol);
    else {
        for(int j = 1; j < alfabet.size(); j++) {
            if(not usado[j] and sol[i-1] != alfabet[j-1]) {
                usado[j] = true;
                sol[i] = alfabet[j];
                back(alfabet, usado, sol, n, i+1);
                usado[j] = false;
                sol[i] = '1';
            }
        }
    }
}

int main() {
    VC alfabetO(10);
    VB usado(10, false);
    alfabetO = {'3', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    int n;
    cin >> n;
    VC sol(n);
    VC alfabet(n+1);
    for(int i = 0; i < n+1; i++) alfabet[i] = alfabetO[i];
    back(alfabet, usado, sol, n, 0);
}