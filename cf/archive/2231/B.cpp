#include <vector>
#include <iostream>
#include <deque>

using namespace std;

int main() {
    int testK;
    cin >> testK;
    for (int t = 0; t < testK; ++t) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        int curMax = 0;
        int maxDrop = 0;
        for (int i = 0; i < n; ++i) {
            curMax = max(curMax, v[i]);
            maxDrop = max(maxDrop, curMax - v[i]);
        }
        bool possible = true;
        for (int i = 1; i < n; ++i) {
            if (v[i] + maxDrop < v[i - 1]) {
                possible = false;
                break;
            } else if (v[i] < v[i - 1]) {
                v[i] += maxDrop;
            }
        }
        
        if (!possible) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }

    }
}
