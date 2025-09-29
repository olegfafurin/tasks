#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits>

using namespace std;


int minScoreTriangulation(vector<int>& values) {
	int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int d = 2; d < n; ++d) {
    	for (int i = 0; i < n - d; ++i) {
    		int j = i + d; // i <= j < n;
			int min_value = numeric_limits<int>::max();
			for (int k = i + 1; k < j; ++k) {
				if (min_value > values[i] * values[j] * values[k] + dp[i][k] + dp[k][j]) {
					min_value = values[i] * values[j] * values[k] + dp[i][k] + dp[k][j];
				}
			}
			dp[i][j] = min_value;
    	}
    }
    return dp[0][n-1];
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

	cout << minScoreTriangulation(v) << '\n';
	return 0;
}