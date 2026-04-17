#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int min_dist = 1e9;
        unordered_map<int, int> prev;
        for (int i = n - 1; i >=0; --i) {
            int v = nums[i];
            int rev = 0;
            while (v > 0) {
                rev *= 10;
                rev += (v % 10);
                v /= 10;
            }
            if (prev.contains(rev) && prev[rev] - i < min_dist) {
                min_dist = prev[rev] - i;
            }
            prev[nums[i]] = i;
        }
        return min_dist < 1e9 ? min_dist : -1;
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << sol.minMirrorPairDistance(nums) << '\n';

    return 0;
}