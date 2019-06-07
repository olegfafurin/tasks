//
// Created by imd on 10/28/2018.
//


#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

ifstream fin("tiv.in");
ofstream fout("tiv.out");

vector<vector<int>> edges;
vector<bool> mark, out, firsts;
int t;
vector<int> ans, col;

void dfs(int v, int color) {
    mark[v] = true;
    col[v] = color;
    t++;
    for (int u : edges[v]) {
        if (!mark[u]) {
            dfs(u, color);
        } else {
            if (!out[u]) {
                fout << "No";
                exit(0);
            }
        }
    }
    ans.push_back(v);
    out[v] = true;
}

int main() {
    ifstream fin("tiv.in");
    ofstream fout("tiv.out");

    int n;
    int color = 0;
    vector<string> words = vector<string>(1000);
    edges = vector<vector<int>>(26);
    mark = out = firsts = vector<bool>(26);
    col = vector<int>(26);
    t = 0;
    ans = vector<int>();

    fin >> n;
    getline(fin, words[0]);
    for (int i = 0; i < n; i++) {
        getline(fin, words[i]);
        if (words[i].length() > 1) firsts[words[i][0] - 'a'] = true;
    }

    for (int i = 1; i < n; i++) {
        if (words[i - 1].length() < words[i].length()) continue;
        if (words[i - 1].length() > words[i].length()) {
            fout << "No";
            fout.close();
            exit(0);
        }
        int k = 0;
        while ((k < words[i].length()) &&(words[i][k] == words[i - 1][k])) k++;
        if (k == words[i].length()) {
            fout << "No";
            fout.close();
            exit(0);
        }
        edges[words[i][k] - 'a'].push_back(words[i - 1][k] - 'a');
    }

    for (int i = 0; i < 26; i++) {
        if (!mark[i]) dfs(i, color++);
    }
//    reverse(ans.begin(), ans.end());


    fout << "Yes\n";
    for (int i = 0; i < 26; i++) {
        auto iter = std::find(ans.cbegin(), ans.cend(), i);
        fout << distance(ans.cbegin(), iter) << ' ';
    }

}