#include <iostream>
#include <map>
using namespace std;

typedef map<string,string>::iterator it_map;

int main() {
	string op;
	map<string,string> m;
	while (cin >> op) {
		if (op == "liats") {
			string x, y;
			cin >> x >> y;
			
			if (m[x] != "") m[m[x]] = "";
			m[x] = y;
			
			if (m[y] != "") m[m[y]] = "";
			m[y] = x;
			
			/*it_map it = m.find(x);
			if (it == m.end()) m.insert({x, y});
			else { //esta
				if (it->second != "") { //tiene pareja
					it_map it1 = m.find(it->second);
					it1->second = "";
				}
				it->second = y;
			}*/
		}
		else { //info
			cout << "PARELLES:" << endl;
			for (it_map it = m.begin(); it != m.end(); ++it) {
				if (it->second != "" and it->first < it->second)
					cout << it->first << " " << it->second << endl;
			}
			cout << "SOLS:" << endl;
			for (it_map it = m.begin(); it != m.end(); ++it) {
				if (it->second == "")
					cout << it->first << endl;
			}
			cout << string(10,'-') << endl;
		}
	}
}
