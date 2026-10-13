#include<vector>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

long long maxAlternatingSum(vector<int>& nums) {
    const int n = nums.size();
    sort(nums.begin(), nums.end(), [](int a, int b) {
        return abs(a) > abs(b);
    });
    long long ans = 0;
    for (int i = 0; i < (n + 1) / 2; ++i) {
        ans += nums[i] * nums[i];
    }
    for (int i = (n + 1) / 2; i < n; ++i) {
        ans -= nums[i] * nums[i];
    }
    return ans;
}

int main() {
    vector<int> v{1, -1, 2, -2, 3, -3};
    cout << maxAlternatingSum(v) << '\n';
}