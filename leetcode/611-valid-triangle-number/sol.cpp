#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

// nums.size() <= 1000
int triangleNumber(vector<int>& nums) {
	int n = nums.size();
    
	sort(nums.begin(), nums.end());
    if (n < 3) {
    	return 0;
    }
    int ans = 0;
    for (int i = 0; i < n - 2; ++i) {
    	int k = i + 2;
    	for (int j = i + 1; j < n - 1; ++j) {
    		if (k < j + 1)
                    k = j + 1;
    		while ((k < n) && (nums[i] + nums[j] > nums[k])) {
    			++k;
    		}
    		ans += (k - j - 1);
    	}
    }
    return ans;
}



int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		v[i] = k;
	}

	cout << '\n';
	cout << triangleNumber(v) << '\n';

	return 0;
}