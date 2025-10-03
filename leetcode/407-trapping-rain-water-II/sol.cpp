#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

using namespace std;

int trapRainWater(vector<vector<int>>& heightMap) {
	int m = heightMap.size();
	int n = heightMap[0].size();
    priority_queue<pair<int, pair<int,int>>> q;
    vector<vector<int>> mh(m, vector<int>(n, numeric_limits<int>::max()));
    int idx_i = 0, idx_j = 0, min_border = numeric_limits<int>::max();

    for (int i = 0; i < m; ++i) {
    	mh[i][0] = heightMap[i][0];
		mh[i][n-1] = heightMap[i][n-1];
		q.push({-heightMap[i][0], {i,0}});
		q.push({-heightMap[i][n-1], {i,n-1}});
    }

	for (int j = 1; j < n - 1; ++j) {
		mh[0][j] = heightMap[0][j];
		mh[m-1][j] = heightMap[m-1][j];
		q.push({-heightMap[0][j], {0,j}});
		q.push({-heightMap[m-1][j], {m-1,j}});
	}

    while (!q.empty()) {
    	auto top_elem = q.top();
    	q.pop();
    	int v = -top_elem.first, x = top_elem.second.first, y = top_elem.second.second;
    	if (v > mh[x][y]) {
    		continue;
    	}
    	int dxs[4] = {1,0,-1,0}, dys[4] = {0,1,0,-1};
    	for (int idx = 0; idx < 4; ++idx) {
    		int dx = dxs[idx], dy = dys[idx];
			if ((x + dx >= 0) && (x + dx < m) && (y + dy >= 0) && (y + dy < n)) {
				int m_new = max(mh[x][y], heightMap[x+dx][y+dy]);
				if (mh[x+dx][y+dy] > m_new) {
					mh[x+dx][y+dy] = m_new;
					q.push({-mh[x+dx][y+dy], {x+dx, y+dy}});
				}
			}
    	}
    }
    int totalWater = 0;
    for (int i = 0; i < m; ++i) {
    	for (int j = 0; j < n; ++j) {
    		totalWater += max(mh[i][j] - heightMap[i][j], 0);
    	}
    }
    return totalWater;
}

int main() {
	int n, m;
	cin >> m >> n;

	vector<vector<int>> grid(m, vector<int>(n));
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n;++j) {
			int x;
			cin >> x;
			grid[i][j] = x;
		}
	}


	cout << trapRainWater(grid) << '\n';
}