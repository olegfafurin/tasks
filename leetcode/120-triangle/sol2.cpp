#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp = triangle[n - 1];

    for (int i = n - 2; i >= 0; --i) {

    	for (int j = 0; j <= i; ++j) {
    		if (dp[j] > dp[j+1])
    			dp[j] = dp[j+1];
    		dp[j] += triangle[i][j];
    	}
    	// dp[i] += triangle[i][i];

    	cout << "i=" << i << '\n';
    	for (int j = 0; j <= i; ++j) {
    		cout << dp[j] << ' ';
    	}
    	cout << '\n';
    }

    return dp[0];
}

int main(int argc, char const *argv[]) {
	int n = 1;
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