#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iostream>

using namespace std;


long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
    const int n = nums1.size();
    int limit = k1 + k2;
    vector<long long> delta(n), pd(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        delta[i] = abs(nums1[i] - nums2[i]);
    }
    sort(delta.begin(), delta.end(), greater<long long>());
    long long cs = 0;
    for (int i = 1; i <= n; ++i) {
        pd[i] = pd[i - 1] + delta[i - 1];
    }
    if (pd[n] <= limit) {
        return 0;
    }
    int r = n;
    int l = 0;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (pd[m] - m * delta[m] <= limit) {
            l =  m;
        } else {
            r = m;
        }
    }
    long long rem = limit - (pd[l] - l * delta[l]);
    long long width = l + 1;
    long long div = rem / width;
    for (int i = 0; i < width; ++i) {
        delta[i] = delta[l] - div;
        if (i < rem % width) {
            --delta[i];
        }
    }
    long long ss = 0;
    for (int i = 0; i < n; ++i) {
        ss += delta[i] * delta[i];
    }
    return ss;
}


int main() {
    vector<int> v1{1,2,3,4,5}, v2{1,1,1,1,1};
    cout << minSumSquareDiff(v1, v2, 0, 4) << '\n';
}