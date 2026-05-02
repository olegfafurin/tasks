#include <vector>
#include <iostream>
#include <queue>

using namespace std;

void gen() {
    int n;
    cin >> n;
    vector<pair<int, int>> deg(n);
    int s = 0;
    priority_queue<pair<int,int>> q;
    for (int i = 0; i < n; ++i) {
        int d;
        cin >> d;
        s += d;
        q.push({d, i});
    } // 1 0 2 -> 2,2, 1,0, 0,1;
    int eCnt = s / 2;
    cout << eCnt << '\n';
    while (!q.empty() && q.top().first > 0) {
        auto [d1, i] = q.top();
        q.pop();
        vector<pair<int,int>> neighbors;
        for (int t = 0; t < d1; ++t) {
            auto [d2, j] = q.top();
            q.pop();
            if (--d2 > 0) {
                neighbors.push_back({d2, j});
            }
            cout << i + 1 << ' ' << j + 1  << '\n';
        }
        for (int t = 0; t < neighbors.size(); ++t) {
            q.push(neighbors[t]);
        }
    }
}

int main() {
    int t;
    cin >> t;

    for (int tn = 0; tn < t; ++tn) {
        gen();
    }
}

