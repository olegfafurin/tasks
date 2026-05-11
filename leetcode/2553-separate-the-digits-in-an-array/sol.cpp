#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> separateDigits(vector<int>& nums) {
    const int n = nums.size();
    vector<int> answer;
    for (int i = n - 1; i >= 0; --i) {
        int x = nums[i];
        vector<int> digits;
        while (x > 0) {
            answer.push_back(x % 10);
            x /= 10;
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}


int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
    
    vector<int> ans = separateDigits(v);

    for (auto &x: ans) {
        cout << x << ' ';
    }
    cout << '\n';
}
