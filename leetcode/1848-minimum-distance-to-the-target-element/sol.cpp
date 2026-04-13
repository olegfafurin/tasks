#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        for (int i = 0; i < nums.size(); ++i) {
            if (start + i < nums.size() && nums[start + i] == target) {
                return i;
            }
            if (start - i >= 0 && nums[start - i] == target) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >>  nums[i];
    }
    int target, ind;
    cin >> target >> ind;
    Solution sol;
    int answer = sol.getMinDistance(nums, target, ind);
    cout << answer << '\n';
}