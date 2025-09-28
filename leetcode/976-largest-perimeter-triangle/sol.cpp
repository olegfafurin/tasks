#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


int largestPerimeter(vector<int>& nums) {
	sort(nums.begin(), nums.end(), greater<int>());
	int n = nums.size();
	for (int i = 0; i < n-2; ++i) {
		if (nums[i] < nums[i+1] + nums[i+2]) {
			return nums[i] + nums[i+1] + nums[i+2];
		}
	}
	return 0;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		v[i] = x;
	}
	cout << largestPerimeter(v) << '\n';
	return 0;
}