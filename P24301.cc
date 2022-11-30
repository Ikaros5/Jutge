#include <iostream>
#include <vector>
using namespace std;

vector <int>concatenacio(const vector <int>&v1, const vector <int>&v2) {
		vector <int>c(v1.size()+v2.size());
			for (int i = 0; i < v1.size(); ++i) c[i] = v1[i];
				for (int i = 0; i < v2.size(); ++i) c[i+v1.size()] = v2[i];
					return c;
}

/*
 *    int main() {
 *        int v1s, v2s;
 *                cin >> v1s;
 *                        vector<int> v1(v1s);
 *                                for (int i = 0; i < v1s; ++i) cin >> v1[i];
 *
 *                                        cin >> v2s;
 *                                                vector<int> v2(v2s);
 *                                                        for (int i = 0; i < v2s; ++i) cin >> v2[i];
 *
 *                                                            vector<int> res = concatenacio(v1, v2);
 *                                                                    for (int i = 0; i < res.size(); ++i) cout << res[i] << endl;
 *                                                                       }
 *                                                                        */
