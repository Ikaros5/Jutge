#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

typedef vector<vector<int>> Grafo;

void ordenacion_topologica(const Grafo& g, map<string, int>& pos_tareas, 
const vector<string>& nombres, vector<int>& ge, queue<string>& q) {
	int n = g.size();
	priority_queue<string, vector<string>, greater<string>> pq;
	
	//añadir los vertices que no tienen ninguna dependencia
	for (int i = 0; i < n; ++i) {
		if (ge[i] == 0) pq.push(nombres[i]);
	}
	
	//recorrer hasta la cola este vacia
	while (not pq.empty()) {
		int u = pos_tareas[pq.top()];
		pq.pop();
		q.push(nombres[u]);
		/*for (int i = 0; i < g[u].size(); ++i) {
			int v = g[u][i];
		*/
		
		for (int v: g[u]) {
			/*
			--ge[v];
			if (ge[v] == 0) pq.push(v);
			*/
			
			if (--ge[v] == 0) pq.push(nombres[v]);
		}
	}
}

int main() {
    int n;
    while (cin >> n) {
		map<string, int> pos_tareas;
		vector<string> nombres(n);
		
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			nombres[i] = s;
			//pos_tareas.insert({s, i});
			pos_tareas[s] = i;
		}
		int m;
		cin >> m;
		
		Grafo g(n);
		vector<int> ge(n, 0);
		
		for (int i = 0; i < m; ++i) {
			string x, y;
			cin >> x >> y;
			g[pos_tareas[x]].push_back(pos_tareas[y]);
			++ge[pos_tareas[y]];
		}
		
		queue<string> q;
		ordenacion_topologica(g, pos_tareas, nombres, ge, q);
		
		if (q.size() == n) {
			while (not q.empty()) {
				cout << q.front();
				q.pop();
			}
			cout << endl;
		}
		else cout << "NO VALID ORDERING" << endl;
    }
}







