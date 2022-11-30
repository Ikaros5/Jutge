#include<iostream>
#include<map>
using namespace std;

int main() {
    string comanda, p;
    map <string, int> m;
	map <string, int>::iterator it;

    while(cin >> comanda) {
        if(comanda == "store") {
            cin >> comanda;
            it = m.find(comanda);
            if(it == m.end()) m.insert(make_pair(comanda, 1));
            else it->second++;
        }
        else if(comanda == "delete") {
            cin >> comanda;
            it = m.find(comanda);
            if(it != m.end()) it->second--;
            if(it->second == 0) m.erase(it);
        }
        else if(comanda == "minimum?") {
            it = m.begin();
            if(it == m.end()) cout << "indefinite minimum" << endl;
            else cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
        }
        else if(comanda == "maximum?") {
            it = m.begin();
            if(it == m.end()) cout << "indefinite maximum" << endl;
            else {
                it = m.end();
                --it;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
    }
}