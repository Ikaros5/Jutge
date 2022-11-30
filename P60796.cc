#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> VVC;

typedef vector<bool> VB;
typedef vector<VB> VVB;

int BFS(VVC &mapa, int i, int j) {
    VVB visitados(mapa.size(), VB(mapa[0].size(), false));
    queue<pair<pair<int, int>, int>> cola;
    cola.push(make_pair(make_pair(i, j), 0));
    
    int x, y, d;
    while(not cola.empty()) {
        x = cola.front().first.first;
        y = cola.front().first.second;
        d = cola.front().second;
        cola.pop();
        
        if(mapa[x][y] == 't') return d;
        else if(not visitados[x][y]) {
            visitados[x][y] = true;
            if(x != mapa.size()-1 and mapa[x+1][y] != 'X') cola.push(make_pair(make_pair(x+1, y), d+1));
            if(x != 0 and mapa[x-1][y] != 'X') cola.push(make_pair(make_pair(x-1, y), d+1));
            if(y != mapa[0].size()-1 and mapa[x][y+1] != 'X') cola.push(make_pair(make_pair(x, y+1), d+1));
            if(y != 0 and mapa[x][y-1] != 'X') cola.push(make_pair(make_pair(x, y-1), d+1));
        }
    }
    return -1;
}

int main() {
    int n, m, i, j;
    cin >> n >> m;
    VVC mapa(n, VC(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mapa[i][j];
        }
    }
    cin >> i >> j;
    int res = BFS(mapa, i-1, j-1);
    if(res != -1) cout << "distancia minima: " << res << endl;
    else cout << "no es pot arribar a cap tresor" << endl;
}