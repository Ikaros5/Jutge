// (c) FIBerHub, https://fiberhub.tk

#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

typedef vector <int> VI;
typedef vector <VI> VVI;

list<int> ordenacio_topologica(VVI &G, vector<int> &ge) {
	int n = G.size();
	priority_queue<int, vector<int>, greater<int> > Q;
	list<int> L;
	for (int u = n-1; u >= 0; --u) if (ge[u] == 0) Q.push(u);
	while (!Q.empty()) {
		int u = Q.top();
		Q.pop();
		L.push_back(u);
		for (int v: G[u]) if (--ge[v] == 0) Q.push(v);
	}
	return L;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		int x, y;
		vector<int> ge(n, 0);
		VVI adj(n);
		for (int i = 0; i < m; ++i) {
			cin >> x >> y;
			adj[x].push_back(y);
			++ge[y];
		}

		list <int>res = ordenacio_topologica(adj, ge);
		for (list <int>::iterator it = res.begin(); it != res.end(); ++it) {
			if (it != res.begin()) cout << ' ';
			cout << *it;
		}
		cout << endl;
	}
}
