#include<iostream>
#include<vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre) {
    if(esq <= dre) {
        int mitad = (esq + dre) / 2;
        if(v[mitad] == x) return mitad;
        if(v[mitad] > x) return posicio(x, v, esq, mitad-1);
        if(v[mitad] < x) return posicio(x, v, mitad+1, dre);
    }
    else return -1;
}

// int main() {
//     vector<double> vector;
//     double a;
//     while(cin >> a and a != -1) {
//         vector.push_back(a);
//     }

//     cout << "Vector creado. Que valor debo buscar?" << endl;
//     cin >> a;
//     cout << posicio(a, vector, 0, vector.size()) << endl;
    
// }