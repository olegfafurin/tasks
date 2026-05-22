#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int testK;
    cin >> testK;
    for (int t = 0; t < testK; ++t) {
        int n;
        cin >> n; 
        vector<int> v(2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            cin >> v[i];
        }
        
        vector<bool> used(n + 1);
        int maxMex = 0;
        for (int s = 0; s < 2 * (2 * n - 1); ++s) {
            int i = (s + 1) / 2;
            int j = s - i;
            while (i < 2 * n && j >= 0 && v[i] == v[j]) {
                used[v[i]] = true;
                ++i;
                --j;
            }

            int mex = 0;
            while (used[mex]) {
                ++mex;
            }
            maxMex = max(maxMex, mex);
            while (--i >= (s + 1) / 2) {
                used[v[i]] = false;
            }
            // fill(used.begin(), used.end(), false);
        }
        cout << maxMex << '\n';
    }
}
