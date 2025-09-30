#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int triangularSum(vector<int>& nums) {
	int n = nums.size();
    vector<int> pt(n, 0);
    vector<int> nxt(n,0);
    pt[0] = 1;
    for (int i = 0; i < n-1; ++i) {
    	for (int j = i+1; j > 0; --j) {
    		pt[j] += pt[j-1];
    		pt[j] %= 10;
    	}
    }
    int rs = 0;
    for (int i = 0; i < n; ++i) {
    	rs += pt[i] * nums[i];
    	rs %= 10;
    }
    return rs;
}

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		v[i] = x;
	}

	cout << triangularSum(v) << '\n';
}