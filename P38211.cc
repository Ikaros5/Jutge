#include<iostream>
#include<vector>
using namespace std;

typedef vector<bool> VB;
typedef vector<VB> VVB;

void write(VVB &tablero) {
	for(int i = 0; i < tablero.size(); i++) {
		for(int j = 0; j < tablero[0].size(); j++) {
			if(tablero[i][j]) cout << "Q";
            else cout << ".";
		}
		cout << endl;
    }
}

int back(VVB &tablero, VB &files, VB &columnes, VB &diagonalP, VB &diagonalB, int n, int i) {
    if(i == n) {
        write(tablero);
        return 1;
    }
    int res = 0;
    for(int j = 0; j < n; j++) {
        //la casilla es valida para posicionar una reina. 
        if(not files[i] and not columnes[j] and not diagonalP[i+j] and not diagonalB[i-j-1+n]) {
            tablero[i][j] = true;
            files[i] = true;
            columnes[j] = true;
            diagonalP[i+j] = true;
            diagonalB[i-j+n-1] = true;
            
            res += back(tablero, files, columnes, diagonalP, diagonalB, n, i+1);
            if(res) return res;

            tablero[i][j] = false;
            files[i] = false;
            columnes[j] = false;
            diagonalP[i+j] = false;
            diagonalB[i-j+n-1] = false;
        }
        // back(tablero, files, columnes, diagonalP, diagonalB, n, i);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    VVB tablero(n, VB(n, false));
    VB files(n, false);
    VB columnes(n, false);
    VB diagonalB(2*n-1, false); // i-j+n
    VB diagonalP(2*n-1, false); // i+j
   	int sol = back(tablero, files, columnes, diagonalP, diagonalB, n, 0);
    if(not sol) cout << "NO SOLUTION" << endl;
}