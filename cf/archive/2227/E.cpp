#include <vector>
#include <iostream>

using namespace std;

int main() {
    int testK;
    cin >> testK;
    for (int t = 0; t < testK; ++t) {
        int n;
        cin >> n;
        vector<long long> v(n);
        long long s = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            s += v[i];
        }
        int colMin = n + 1;
        long long liquid = 0;
        int cnt = 0;
        int maxCnt = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (v[i] < colMin) {
                colMin = v[i];
                maxCnt = max(maxCnt, cnt);
                cnt = 1;
            } else {
                liquid += v[i] - colMin;
                ++cnt;
            }
        }
        maxCnt = max(maxCnt, cnt);
        cout << (liquid + maxCnt - 1) << '\n';
    }
}
