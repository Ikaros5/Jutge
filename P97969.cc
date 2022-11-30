#include<iostream>
using namespace std;

int main() {
    int x = 0; 
    char letra;
    cin >> letra;
    while(letra != '.') {
        if(letra == 'a') x++;
        cin >> letra;
    }
    cout << x << endl; 
}