#include<iostream>
#include<vector>
using namespace std;

typedef vector<string> VS;
typedef vector<bool> VB;

void permutaciones_palabras_repe(VS &v, VS &sol, int i) {
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
            sol[i] = v[j];
            permutaciones_palabras_repe(v, sol, i+1);
            sol[i] = "";
		}
	}
}

int main() {
    int n;
    cin >> n;
    VS v(n);
    VS sol(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    permutaciones_palabras_repe(v, sol, 0);

}