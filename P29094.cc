#include <iostream>
#include <vector>

using namespace std;

 int posicio_maxim (const vector<double>& v, int m) {
    double maxim = v[0];
    int posmax = 0;
    for (int i=0; i<=m; i++) {
        if (v[i] > maxim) {
                maxim = v[i];
                posmax = i;
        }
    }
    return posmax;
 }
