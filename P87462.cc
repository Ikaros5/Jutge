#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;

typedef vector<char> VB;
typedef vector<VB> VVB;

vector<int> X = {1,0,-1,0,1,-1,1,-1};
vector<int> Y = {0,1,0,-1,1,-1,-1,1};

bool pos_ok(int i, int j, int n, int m) {
    return i >= 0 and j >= 0 and i < n and j < m;
}

void elimina_fantasmas(VVC &mapa, int i, int j) {
    int n = mapa.size();
    int m = mapa[0].size();
    int x, y;
    mapa[i][j] = 'X';
    for(int k = 0; k < 8; k++) {
        x = i+X[k];
        y = j+Y[k];
        if(pos_ok(x, y, n, m) and mapa[x][y] != 'F') { 
            mapa[x][y] = 'X';
        }
    }
}

bool BFS(VVC &mapa, int i, int j) {
    VVB visitados(mapa.size(), VB(mapa[0].size(), false));
    queue<pair<int, int>> cola;
    cola.push(make_pair(i, j));
    int x, y;
    while(not cola.empty()) {
        x = cola.front().first;
        y = cola.front().second;
        cola.pop();
        if(mapa[x][y] == 'B') return true;
        else if(not visitados[x][y]) {
            visitados[x][y] = true;
            if(mapa[x+1][y] != 'X') cola.push(make_pair(x+1, y));
            if(mapa[x-1][y] != 'X') cola.push(make_pair(x-1, y));
            if(mapa[x][y+1] != 'X') cola.push(make_pair(x, y+1));
            if(mapa[x][y-1] != 'X') cola.push(make_pair(x, y-1));
        }
    }
    return false;
}

int main() {
    int n, m, x, y;
    while(cin >> n >> m) {
        VVC mapa(n, VC(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> mapa[i][j];
                if(mapa[i][j] == 'P') {
                    x = i; 
                    y = j;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mapa[i][j] == 'F') elimina_fantasmas(mapa, i, j);
            }
        }
        // cout << endl << endl;
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         cout << mapa[i][j];
        //     }
        //     cout << endl;
        // }

        if(mapa[x][y] == 'X') cout << "no" << endl;
        else if(BFS(mapa, x, y)) cout << "si" << endl;
        else cout << "no" << endl;
    }
}