#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <vector>
#include <queue>

using namespace std;


int minJumps(vector<int>& arr) {
	const int n = arr.size();
	if (n == 1) {
		return 0;
	}
	unordered_map<int, vector<int>> occ;
	unordered_set<int> visited;
	vector<int> d(n, INT_MAX);
	d[0] = 0;
	queue<int> q;
	q.push(0);
	for (int i = 0; i < n; ++i) {
		occ[arr[i]].push_back(i);
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x - 1 >= 0 && d[x - 1] == INT_MAX) {
			d[x - 1] = d[x] + 1;
			q.push(x - 1);
		}
		if (x + 1 < n && d[x + 1] == INT_MAX) {
			d[x + 1] = d[x] + 1;
			if (x + 1 == n - 1) {
				return d[x + 1];
			}
			q.push(x + 1);
		}
		if (!visited.contains(arr[x])) {
			visited.insert(arr[x]);
			for (auto idx: occ[arr[x]]) {
				if (d[idx] == INT_MAX) {
					d[idx] = d[x] + 1;
					if (idx == n - 1) {
						return d[idx];
					}
					q.push(idx);
				}
			}
		}
	}
	return -1;
}

int main(int argc, char const *argv[]) {
	int n;
    cin >> n;
	vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
	cout << minJumps(v) << '\n';
}
