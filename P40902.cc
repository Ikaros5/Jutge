#include<iostream>
#include<map>

using namespace std;

int main() {
    string nom;
    string comanda;
    map<string, int> lista;
    
    while(cin >> nom) {
        map<string, int>::iterator it = lista.find(nom);
        if (it == lista.end()) { //No esta al casino
            cin >> comanda;
            if (comanda == "enters") { //agefim el nom al map

                lista.insert({nom, 0});
            }
            else if(comanda == "leaves") {
                cout << nom << " is not in the casino" << endl;
            }
            else {
                cout << nom << " is not in the casino" << endl;
                cin >> comanda;
            }
        }
        else { //Esta al casino
        cin >> comanda;
            if(comanda == "enters") {
                cout <<  nom << " is already in the casino" << endl;
            }
            else if(comanda == "leaves") {
                int x = it->second;
                cout << nom << " has won " << x << endl;
                lista.erase(it);
            }
            else { //wins
                int cantitat;
                cin >> cantitat;
                it->second += cantitat;
            }

        }
    }
    cout << "----------" << endl;
    map<string, int>::iterator it2;
    for (it2 = lista.begin(); it2 != lista.end(); ++it2) {
        cout << it2->first << " is winning " << it2->second << endl;
    }
}