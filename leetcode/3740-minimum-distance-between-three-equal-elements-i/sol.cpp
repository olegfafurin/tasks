#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int min_dist = 1000;
        int n = nums.size();
        unordered_map<int, int> last;
        vector<int> prev(n, -1);
        for (int i = 0; i < n; ++i) {
            if (last.contains(nums[i])) {
                prev[i] = last[nums[i]];
                if (prev[prev[i]] > -1) {
                    int d = 2 * (i - prev[prev[i]]);
                    if (d < min_dist) {
                        min_dist = d;
                    }
                }
            } else {
                prev[i] = -1;
            }
            last[nums[i]] = i;
        }
        if (min_dist < 1000) {
            return min_dist;
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
    Solution sol;
    int answer = sol.minimumDistance(nums);
    cout << answer << '\n';
}