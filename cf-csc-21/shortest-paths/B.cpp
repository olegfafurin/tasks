#include <vector>
#include <queue>
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;


vector<int> neighbors(int v) { 
    vector<int> answer;
    if (v % 10 > 1) {
        answer.push_back(v - 1);
    }
    if (v < 9'000) {
        answer.push_back(v + 1000);
    }
    answer.push_back((v % 1'000) * 10 + (v / 1'000));
    answer.push_back((v % 10) * 1000 + (v / 10));
    return answer;
}


int main() {
    int n, m;
    cin >> n >> m;
    array<int, 9'000> d;
    fill(d.begin(), d.end(), -1);
    d[n - 1'000] = 0;
    array<int, 9'000> p;
    fill(p.begin(), p.end(), -1);

    queue<int> q;
    q.push(n);

    bool done = false;
    while (!q.empty() && !done) {
        int x = q.front();
        q.pop();
        for (auto u: neighbors(x)) {
            if (d[u - 1'000] == -1) {
                d[u - 1'000] = d[x - 1'000] + 1;
                p[u - 1'000] = x;
                if (u == m) {
                    done = true;
                    break;
                }
                q.push(u);
            }
        }
    }

    vector<int> path(d[m - 1'000] + 1);
    int ind = path.size() - 1;
    while (m != n) {
        path[ind--] = m;
        m = p[m - 1'000];
    }
    path[ind] = n;

    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] << '\n';
    }

}
