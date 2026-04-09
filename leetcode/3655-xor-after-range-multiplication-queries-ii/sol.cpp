#include <vector>
#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
private:
    int p = 1e9 + 7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        unordered_map<int, int> cnt_mod;

        unordered_map<int, vector<int>> q_in, q_out;

        vector<long long> mult(n, 1);
        int t = sqrt(n);
        for (int j = 0; j < queries.size(); ++j) {
            auto &q = queries[j];
            int l = q[0], &r = q[1], k = q[2], v = q[3];
            int r_old = r;
            r -= (r - l) % k;
            if (k > t) {
                for (int i = l; i <= r; i += k) {
                    mult[i] *= v;
                    mult[i] %= p;
                }
            } else {
                q_in[l].push_back(j);
                q_out[r].push_back(j);
            }
        }

        unordered_map<int, unordered_map<int, long long>> q_cur;

        for (int i = 0; i < n; ++i) {
            for (auto &q_ind: q_in[i]) {
                auto q = queries[q_ind];
                int l = q[0], r = q[1], k = q[2], v = q[3];
                cnt_mod[k]++;
                if (q_cur[k][l % k] == 0) {
                    q_cur[k][l % k] = v;
                } else {
                    q_cur[k][l % k] *= v;
                    q_cur[k][l % k] %= p;
                }
            }

            for (auto &kv: cnt_mod) {
                int mod = kv.first;
                int m = q_cur[mod][i % mod];
                if (m > 1) {
                    mult[i] *= m;
                    mult[i] %= p;
                }
            }

            for (auto &q_ind: q_out[i]) {
                auto q = queries[q_ind];
                int l = q[0], r = q[1], k = q[2], v = q[3];
                cnt_mod[k]--;
                if (cnt_mod[k] == 0) {
                    cnt_mod.erase(k);
                    q_cur.erase(k);
                } else {
                    q_cur[k][l % k] *= inv(v);
                    q_cur[k][l % k] %= p;
                }
            }
        }

        int acc = 0;
        for (int i = 0; i < n; ++i) {
            acc ^= static_cast<int>((mult[i] * nums[i]) % p);
        }
        return acc;
    }

    int inv(int a) {
        return a <= 1 ? a : p - (long long)(p/a) * inv(p % a) % p;
    }
};


int main() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n, 0);
    vector<vector<int>> queries(q, vector<int>(4, 0));
    for (int i = 0; i < n; ++i) {
        cin >>  nums[i];
    }
    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> queries[i][j];
        }
    }
    Solution sol;
    int answer = sol.xorAfterQueries(nums, queries);
    cout << answer << '\n';
}
