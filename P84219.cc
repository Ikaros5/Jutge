#include<iostream>
#include<vector>
using namespace std;

int fo_rec(double x, const vector<double>& v, int esq, int dre) {
    if(dre < esq) return -1;
    int mitad = (esq + dre) / 2;
    if(v[mitad] > x) return fo_rec(x, v, esq, mitad-1);
    if(v[mitad] < x) return fo_rec(x, v, mitad+1, dre);

    //si no es el inicio del vector
    if (mitad-1 >= 0) {
			int mitad2 = fo_rec(x, v, esq, mitad-1);
			if (mitad2 != -1) return mitad2;
		}
	return mitad;
}

int first_occurrence(double x, const vector<double>& v) {
    //el numero no esta al vector (vector buit, o numero fora del rang de numeros del vector)
    if(v.empty() or x < v[0] or v[v.size()-1] < x) return -1;
    else return fo_rec(x, v, 0, v.size()-1);
}

int main() {
    vector<double> vector;
    double a;
    while(cin >> a and a != -1) {
        vector.push_back(a);
    }

    cout << "Vector creado. Que valor debo buscar?" << endl;
    cin >> a;
}