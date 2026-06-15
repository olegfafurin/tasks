#include <vector>
#include <queue>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
    static vector<int> p;
    static bool built;

    static void preprocess() {
        if (built) {
            return;
        }
        p.resize(1'000'001);
        for (int i = 2; i <= 1'000'000; ++i) {
            p[i] = i;
        }
        for (int i = 2; i < 1'000'000; ++i) {
            if (p[i] == i) {
                for (int j = i; j <= 1'000'000; j += i) {
                    p[j] = i;
                }
            }
        }
        built = true;
    }

public:

    int minJumps(vector<int>& nums) {
        preprocess();
        const int n = nums.size();

        array<bool, 1'000'001> primesPresent{0};
        for (auto x: nums) {
            if (p[x] == x) {
                primesPresent[x] = true;
            }
        }

        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            while (x > 1) {
                int div = p[x];
                if (primesPresent[div]) {
                    adj[div].push_back(i);
                }
                while (x % div == 0) {
                    x /= div;
                }
            }
        }
        queue<int> q;
        const int INF = 1e9;
        vector<int> d(n, INF);
        d[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (i - 1 >= 0 && d[i - 1] == INF) {
                d[i - 1] = d[i] + 1;
                q.push(i - 1);
            }
            if (i + 1 < n && d[i + 1] == INF) {
                d[i + 1] = d[i] + 1;
                q.push(i + 1);
                if (i + 1 == n - 1) {
                    return d[n - 1];
                }
            }
            int x = nums[i];
            if (p[x] == x && primesPresent[x]) {
                primesPresent[x] = false;
                for (int idx: adj[x]) {
                    if (d[idx] == INF) {
                        d[idx] = d[i] + 1;
                        q.push(idx);
                        if (idx == n - 1) {
                            return d[n - 1];
                        }
                    }
                }
            }
        }
        return n - 1;
    }
};


bool Solution::built = false;
vector<int> Solution::p;

int main() {
    int n;
    cin >> n; 
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    Solution sol;
    cout << sol.minJumps(v) << '\n';

}
