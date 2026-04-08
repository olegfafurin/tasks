#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int p = 1e9 + 7;
        int n = nums.size();
        vector<long long> mult(n, 1);
        for (auto &q: queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int i = l; i <= r; i += k) {
                mult[i] *= v;
                mult[i] %= p;
            }
        }
        int acc = 0;
        for (int i = 0; i < n; ++i) {
            acc ^= static_cast<int>((mult[i] * nums[i]) % p);
        }
        return acc;
    }
};