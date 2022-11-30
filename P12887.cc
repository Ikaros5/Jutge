#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

typedef pair<int, int> P;
typedef vector<P> VP;
typedef vector<VP> VVP;

int MST(const VVP &g) {
	int n = g.size();
	priority_queue<P, VP, greater<P>> q;
	vector<bool> vis(n, false);
	vis[0] = true;
	P uv;
	//recorrremos todas las aristas 
	for(int i = 0; i < g[0].size(); i++) {
		uv = g[0][i];
		q.push(uv);
	} 
	int num = 1; //numero de vertices visitados
	int sum = 0; //coste del MST

	while (num < n) { //mientras no haya visitado todos los nodos
		int coste = q.top().first;
		int v = q.top().second;
		q.pop();

		if (!vis[v]) {
			vis[v] = true;
			for(int i = 0; i < g[v].size(); i++) {
				uv = g[v][i];
				if (not vis[uv.second]) q.push(uv);
			} 
			sum += coste;
			++num;
		}
	}
	return sum;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		int v, u, w;
		VVP matrix(n);

		for (int i = 0; i < m; ++i) {
			cin >> v >> u >> w;
			matrix[v-1].push_back(make_pair(w, u-1));
			matrix[u-1].push_back(make_pair(w, v-1));
		}

		int res = MST(matrix);
		cout << res << endl;
	}
}
