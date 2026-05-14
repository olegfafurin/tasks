#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isGood(vector<int>& nums) {
    int n = nums.size();
    vector<bool> cnt(n - 1);
    int numCnt = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] < 1 || nums[i] >= n) {
            return false;
        }
        if (cnt[nums[i] - 1]) {
            if (nums[i] < n - 1) {
                return false;
            }
            continue;
        }
        cnt[nums[i] - 1] = true;
        ++numCnt;
    }
    return numCnt == n - 1;
    
}

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
    
    bool ans = isGood(v);

    cout << (ans ? "YES" : "NO") << '\n';
}
