//
// Created by imd on 10/25/2018.
//

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> first, last;
vector<bool> mark;
vector<vector<int>> answer;

int main() {
    ifstream fin("dfs.in");
    ofstream fout("dfs.out");

    int n, l, count;
    vector<int> tree = vector<int>(602);
    fin >> n >> l;
    first = vector<int>(301);
    last = vector<int>(301);
    mark = vector<bool>(301);
    answer = vector<vector<int>>(300);
    for (int i = 0; i < l; i++) {
        fin >> tree[i];
        if (!mark[tree[i]]) first[tree[i]] = i;
        mark[tree[i]] = true;
    }
    for (int i = 0; i <= n; i++) mark[i] = false;
    for (int i = l - 1; i >= 0; i--) {
            if (!mark[tree[i]]) last[tree[i]] = i;
        mark[tree[i]] = true;
    }
    count = 0;
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= n; k++) mark[k] = false;
        if (first[i] == last[i]) continue;
        int j = first[i] + 1;
        while (j < last[i]) {
            int child = tree[j];
            mark[child] = true;
            count++;
            answer[i-1].push_back(child);
            while (j <= last[child]) {
                if ((!mark[tree[j]]) && (tree[j] > child)) {
                    answer[i-1].push_back(tree[j]);
                    count++;
                    mark[tree[j]] = true;
                }
                j++;
            }
            j++;
        }
    }
    fout << count << '\n';
    for (int i = 1; i <= n; i++) {
        for (int akula_kotoraya_ne_plavayet_tonet : answer[i-1]) fout << i << ' ' << akula_kotoraya_ne_plavayet_tonet << '\n';
    }
}