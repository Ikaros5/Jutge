#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<bool> VB;
typedef vector<VB> VVB;

int BFS(VVS &teclat, int &i, int &j, string destination) {
    VVB visitado(teclat.size(), VB(teclat[0].size(), false));
    queue<pair<pair<int, int>, int>> cola;
    cola.push(make_pair(make_pair(i, j), 0));
    int x, y, dis;
    while(not cola.empty()) {
        x = cola.front().first.first;
        y = cola.front().first.second;
        dis = cola.front().second;
        cola.pop();

        if(teclat[x][y] == destination) {
            i = x;
            j = y;
            return dis;
        }
        else if(not visitado[x][y]) {
            visitado[x][y] = true;
            if(x != teclat.size()-1 and teclat[x+1][y] != "*") cola.push(make_pair(make_pair(x+1, y), dis+1));
            if(x != 0 and teclat[x-1][y] != "*") cola.push(make_pair(make_pair(x-1, y), dis+1));
            if(y != teclat[0].size()-1 and teclat[x][y+1] != "*") cola.push(make_pair(make_pair(x, y+1), dis+1));
            if(y != 0 and teclat[x][y-1] != "*") cola.push(make_pair(make_pair(x, y-1), dis+1));
        }
    }
    return -1;
}

int main() {
    int n, m, x, cont;
    while(cin >> n >> m) {
        cont = 0;
        VVS teclat(n, VS(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> teclat[i][j];
            }
        }
        cin >> x;
        VS pelicula(x);
        for(int i = 0; i < x; i++) {
            cin >> pelicula[i];
        }
        int i = 0, j = 0;
        bool force_end = false;
        for(int k = 0; k < x and not force_end; k++) {
            int res = BFS(teclat, i, j,pelicula[k]);
            if(res == -1) force_end = true;
            cont += res;
        }
        if(force_end) cout << "impossible" << endl;
        else cout << cont+x << endl;
    }
}