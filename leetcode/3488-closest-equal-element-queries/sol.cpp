#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, int> prev, nxt;
        vector<int> ans(n, n);
        for (int i = 0; i < n; ++i) {
            prev[nums[i]] = i;
            nxt[nums[n - 1 - i]] = n - 1 - i;
        }
        for (int i = 0; i < n; ++i) {
            ans[i] = (i - prev[nums[i]] + n) % n;
            prev[nums[i]] = i;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (ans[i] > (nxt[nums[i]] - i + n) % n) {
                ans[i] = (nxt[nums[i]] - i + n) % n;
            }
            nxt[nums[i]] = i;
        }
        vector<int> qAns(queries.size(), -1);
        for (int i = 0; i < queries.size(); ++ i) {
            if (ans[queries[i]] > 0) {
                qAns[i] = ans[queries[i]];
            }
        }
        return qAns;
    }
};

int main() {
    Solution sol;

    int n, q;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cin >> q;
    vector<int> queries(q);

    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }

    auto ans = sol.solveQueries(nums, queries);

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }


    return 0;
}