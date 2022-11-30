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

void write(VI &sol) {
    cout << "(" << sol[0];
    for(int i = 1; i < sol.size(); i++) {
        cout << "," << sol[i];
    }
    cout << ")" << endl;;
}

void back(VI &nums, VB &usado, VI &sol, bool first, bool second, int n, int i) {
    if(i == n) write(sol);
    else if(first) {
        for(int j = 0; j < nums.size(); j++) {
            sol[i] = nums[j];
            usado[j] = true;
            back(nums, usado, sol, false, true, n, i+1);
            sol[i] = -1;
            usado[j] = false;
        }
    }
    else if(second) {
        for(int j = 0; j < nums.size(); j++) {
            if(not usado[j] and sol[i-1] <= 2 * nums[j]) {
                sol[i] = nums[j];
                usado[j] = true;
                back(nums, usado, sol, false, false, n, i+1);
                sol[i] = -1;
                usado[j] = false;
            }
        }
    }
    else {
        for(int j = 0; j < nums.size(); j++) {
            if(not usado[j] and (nums[j]+sol[i-2] <= 2 * sol[i-1]) ) {
                sol[i] = nums[j];
                usado[j] = true;
                back(nums, usado, sol, false, false, n, i+1);
                sol[i] = -1;
                usado[j] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    VI sol(n);
    VI nums(n);
    VB usado(n, false);
    for(int i = 1; i < n+1; i++) {
        nums[i-1] = i;
    }
    
    // for(int i = 0; i < n; i++) {
    //     cout << nums[i] << " ";
    // }
    back(nums, usado, sol, true, true, n, 0);
}