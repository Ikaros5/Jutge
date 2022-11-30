#include <iostream>
using namespace std;


int main() {
    char x;
    int g = 0;
    char y = 0;
    bool acabat = true;
    
    while (cin >> x and x != -1 and acabat == true) {
        
        if (x != y)  {
        y = x;
        g++;
    }
        else {
            cout << g << endl;
            acabat = false; }
    }
}

