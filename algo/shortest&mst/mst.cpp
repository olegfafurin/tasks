//
// Created by imd on 11/12/2018.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
#include <set>

using namespace std;

int main() {
    int n, m, weight, u, v ,t;
    vector<int> l(100000), r(100000), w(100000);
    vector<bool> mark(20000);
    vector<vector<int>> from(20000);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i] >> w[i];
        l[i]--;
        r[i]--;
        if (l[i] == r[i]) continue;
        from[r[i]].push_back(i);
        from[l[i]].push_back(i);
    }
    set<pair<int, int>> tree;
    for (auto st : from[0]) {
        tree.insert(make_pair(w[st], st));
    }
    mark[0] = true;
    for (int i = 0; i < n - 1; ++i) {
        int current  = (*tree.begin()).second;
        if (mark[l[current]] == false) {
            for (int ind : from[l[current]]) {
                if (l[current] == l[ind]) {
                    if (!mark[r[ind]]) tree.insert(make_pair(w[ind], ind));
                    else tree.erase(make_pair(w[ind], ind));
                }
                else {
                    if (!mark[l[ind]]) tree.insert(make_pair(w[ind], ind));
                    else tree.erase(make_pair(w[ind], ind));
                }
            }
            mark[l[current]] = true;
        }
        else {
            for (int ind : from[r[current]]) {
                if (r[current] == l[ind]) {
                    if (!mark[r[ind]]) tree.insert(make_pair(w[ind], ind));
                    else tree.erase(make_pair(w[ind], ind));
                }
                else {
                    if (!mark[l[ind]]) tree.insert(make_pair(w[ind], ind));
                    else tree.erase(make_pair(w[ind], ind));
                }
            }
            mark[r[current]] = true;
        }
        weight += w[current];
    }
    cout << weight;

}