#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<list>
using namespace std;
typedef vector<list<int>> graph;
typedef pair<int, int> P;
typedef vector<P> VP;
typedef vector<VP> VVP;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef vector<VS> VVS;

void back(VI &nums, VI &prohibits, int sol, int n, int i) {
    if(i == n) cout << sol << endl;
    else {
        for(int j = 0; j < nums.size(); j++) {
            bool valido = true;
            sol = sol * 10;
            sol = sol + nums[j];
            for(int k = 0; k < prohibits.size() and valido; k++) {
                if(sol % prohibits[k] == 0) {
                    valido = false;
                    // cout << sol << " no es valido porque es multiple de " << prohibits[k] << endl;
                }
            }
            if(valido) {
                // cout << sol << " es valido" << endl;
                back(nums, prohibits, sol, n, i+1);
            }
            sol = sol / 10;
            // cout << "***** " << sol << " ******" << endl;
        }
    }
}

int main() {
    int n, m;
    while(cin >> n >> m) {
        VI prohibits(m);
        int sol = 0;
        VI nums(9);
        nums = {0,1,2,3,4,5,6,7,8,9};
        for(int i = 0; i < m; i++) cin >> prohibits[i];
        back(nums, prohibits, sol, n, 0);
        cout << "----------" << endl; 
    }
}