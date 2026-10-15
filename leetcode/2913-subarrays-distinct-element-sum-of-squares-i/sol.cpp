#include<vector>
#include<iostream>

using namespace std;

int sumCounts(vector<int>& nums) {
    const int n = nums.size();
    int cnt[100] = {0};
    int dc = 0;
    int sc = 0;
    for (int i = 0; i < n; ++i) {
        for (int t = 0; t < 100; ++t) {
            cnt[t] = 0;
        }
        dc = 0;
        for (int j = i; j < n; ++j) {
            if (cnt[nums[j] - 1]++ == 0) {
                ++dc;
            }
            sc += dc * dc;
        }
    }
    return sc;
}

int main() {
    vector<int> v{1,2,3,4,3,1,2,4};
    cout << sumCounts(v) << '\n';
}