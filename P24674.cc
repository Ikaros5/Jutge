#include<iostream>
#include<vector>
using namespace std;

typedef vector<string> VS;
typedef vector<bool> VB;

void permutaciones_palabras(VS &v, VB &usado, VS &sol, int i) {
    int n = v.size();
	if (n == i) {
        cout << "(";
		for(int j = 0; j < n; j++) {
			cout << sol[j];
			if (j != n-1) cout << ",";
		}
		cout << ")" << endl;
	} 
	else {
		for(int j = 0; j < n; j++) {
			if(not usado[j]) {
				usado[j] = true;
				sol[i] = v[j];
				permutaciones_palabras(v, usado, sol, i+1);
				usado[j] = false;
				sol[i] = "";
			}
		}
	}
}

int main() {
    int n;
    cin >> n;
    VS v(n);
    VS sol(n);
	VB usados(n, false);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    permutaciones_palabras(v, usados, sol, 0);

}