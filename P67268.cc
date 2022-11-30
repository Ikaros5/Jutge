#include <iostream>
#include <vector>
using namespace std;

int main () {
int n, a;

while (cin >> n) {
bool first = true;
vector<int>S(n);

for (int i=0; i<n; i++) {
    cin >> S[i];
}

for (int j=0; j<n/2; j++) {
    a = S[n-j-1];
    S[n-j-1] = S[j];
    S[j] = a;
}

for (int k=0; k<n; k++) {
    if (first) {
        cout << S[k];
        first = false;
}
    else cout << " " << S[k];


}
cout << endl;
}
}
