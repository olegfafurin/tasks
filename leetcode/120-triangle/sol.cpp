#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> prev(n), cur(n);

    prev[0] = triangle[0][0];
    for (int i = 1; i < n; ++i) {
    	cur[0] = prev[0] + triangle[i][0];
    	for (int j = 1; j < i; ++j) {
    		cur[j] = prev[j-1] < prev[j] ? prev[j-1] : prev[j];
    		cur[j] += triangle[i][j];
    	}
    	cur[i] = prev[i-1] + triangle[i][i];
    	swap(prev, cur);
    	cout << "i=" << i << '\n';
    	for (int j = 0; j <= i; ++j) {
    		cout << prev[j] << ' ';
    	}
    	cout << '\n';
    }
    int ans = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
    	if (prev[i] < ans)
    		ans = prev[i];
    }
    return ans;
}

int main(int argc, char const *argv[]) {
	int n = 200;
	vector<vector<int>> t(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			t[i][j] = 10 - i *j;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cout << t[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << minimumTotal(t) << '\n';

	cout << '\n';

	return 0;
}