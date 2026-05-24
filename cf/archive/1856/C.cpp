#include <iostream>
#include <vector>

using namespace std;

int main() {
    int testCnt;
    cin >> testCnt;
    for (int t = 0; t < testCnt; ++t) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        vector<int> h(n);
        int last = n - 1;
        h[last] = v[last];
        for (int i = n - 2; i >= 0; --i) {
            h[i] = max(v[i], v[last] + last - i);
            if (h[i] == v[i]) {
                last = i;
            }
        }
        vector<long long> prefSum(n + 1);
        for (int i = 0; i < n; ++i) {
            prefSum[i + 1] = prefSum[i] + v[i];
        }
        int ans = 0;
        for (int i = 0; i <= last; ++i) {
            int lo = v[i];
            int hi = h[i] + 1;
            while (lo + 1 < hi) {
                int mid = (lo + hi) / 2;
                int budget = k;
                int target = mid;
                int idx = i;
                bool mark = true;
                while (budget >= 0 && idx < n) {
                    if (target - v[idx] > budget) {
                        mark = false;
                        break;
                    }
                    if (target <= v[idx]) {
                        break;
                    }
                    budget -= (target - v[idx]);
                    --target;
                    ++idx;
                }
                if (mark) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            ans = max(ans, lo);
        }
        cout << ans << '\n';
    }
}
