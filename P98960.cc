
#include <iostream>
using namespace std;
int main() {
    char a;
    cin >> a;
    
    if (a >= 'A' and a<= 'Z') a = a + ('a'  - 'A'); 
    else  a = a - ('a' - 'A');
    
        cout << a << endl;

}
    
