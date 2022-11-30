#include<iostream>
#include<vector>
using namespace std;

void hay_camino(const vector <vector <char> > &mapa, int x, int y, vector< vector <bool> > &visitados, bool &trobat) {
    if (not visitados[x][y] && not trobat) {
		visitados[x][y] = true;
		if (mapa[x][y] == 't') trobat = true;
		else if (mapa[x][y] != 'X') {
			if (y != mapa[0].size()-1) hay_camino(mapa, x, y+1, visitados, trobat);
			if (x != mapa.size()-1) hay_camino(mapa, x+1, y, visitados, trobat);
			if (y != 0) hay_camino(mapa, x, y-1, visitados, trobat);
			if (x != 0) hay_camino(mapa, x-1, y, visitados, trobat);
		}
	}
}


int main() {
    //guardem el mapa
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mapa(n, vector <char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mapa[i][j];
        }
    }
    
    //posicio inicial
    int f, c;
    cin >> f >> c;
    bool trobat = false;
    vector<vector<bool>> visitados(n, vector<bool>(m, false));
    hay_camino(mapa, f-1, c-1, visitados, trobat);
    trobat ? cout << "yes" << endl : cout << "no" << endl;
}