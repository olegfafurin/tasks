#include<vector>
#include<iostream>

using namespace std;


int maxSum(vector<int>& nums, int k) {
    const long long p = 1e9 + 7;
    const int n = nums.size();
    int cnt[31] = {0};
    int pow2[31] = {1};
    for (int j = 1; j < 31; ++j) {
        pow2[j] = pow2[j - 1] << 1;
    }
    for (int i = 0; i < n; ++i) {\
        for (int j = 0; j < 31; ++j) {
            if (nums[i] & pow2[j]) {
                ++cnt[j];
            }
        }
    }
    vector<long long> opt(k, 0);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < 31; ++j) {
            if (cnt[j] > i) {
                opt[i] += pow2[j];
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += (opt[i] * opt[i]) % p;
        ans %= p;
    }
    return ans;
}

int main() {
    vector<int> v{2, 6, 5, 8};
    cout << maxSum(v, 2) << '\n';
}