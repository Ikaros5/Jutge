#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> P;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<char> VC;
typedef vector<VC> VVC;

VI X = {0, 1, 0, -1, 1, -1, 1, -1};
VI Y = {1, 0, -1, 0, 1, -1, -1, 1};

void BFS(VVC &mapa, VVB &visitados, int i, int j) {
    int n = mapa.size();
    int m = mapa[0].size();
    queue<P> q;
    q.push(make_pair(i, j));
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(mapa[x][y] == 'F') {
            cout << "SI" << endl;;
            return;
        }
        else if(not visitados[x][y]) {
            visitados[x][y] = true;
            // cout << "VISITAMOS: " << x << " " << y << endl;
            if(x != 0 and mapa[x-1][y] != '#') q.push(make_pair(x-1, y));
            if(x != n-1 and mapa[x+1][y] != '#') q.push(make_pair(x+1, y));
            if(y != 0 and mapa[x][y-1] != '#') q.push(make_pair(x, y-1));
            if(y != m-1 and mapa[x][y+1] != '#') q.push(make_pair(x, y+1));
        }
    }
    cout << "NO" << endl;
}

bool pos_ok(int i, int j, int n, int m)  {
    return i >= 0 and j >= 0 and i < n and j < m;
}

void actualiza_mapa(VVC &mapa, int i, int j) {
    int n = mapa.size();
    int m = mapa[0].size();
    for(int k = 0; k < 4; k++) {
        int x = i+X[k];
        int y = j+Y[k];
        if(pos_ok(x, y, n, m) and mapa[x][y] != 'M') mapa[x][y] = '#';
    }
}

int main() {
    int n, m, a, b;
    while(cin >> n >> m) {
        VVC mapa(n, VC(m));
        VVB visitados(n, VB(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mapa[i][j];
                if(mapa[i][j] == 'I') {a = i; b = j;}
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(mapa[i][j] == 'M') actualiza_mapa(mapa, i, j);
            }
        }
        if(mapa[a][b] != '#') BFS(mapa, visitados, a, b);
        else cout << "NO" << endl;
    }
}