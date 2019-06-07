//
// Created by imd on 12/2/2018.
//

#include <iostream>
#include "algorithm"
#include "vector"

using namespace std;

vector<bool> mark, has_match, take;
vector<vector<bool>> mc;
vector<vector<int>> c(200);
//vector<int> match;
vector<int> match1, match2;
int counter = 0, from_second, from_first;
int n, m, result1, result2;

void process(int &result, vector<int> &match);

void print(int result, vector<int> &match, bool flag, vector<int> &mark);

bool kuhn(int v, vector<int> &match) {
    if (mark[v]) return false;
    mark[v] = true;
    for (int u : c[v]) {
        if (match[u] == -1 || kuhn(match[u], match)) {
            match[u] = v;
            return true;
        }
    }
    return false;
}

void dfs(int v, vector<int> &match) {
    for (int u : c[v]) {
        if (!mark[u]) {
            mark[u] = true;
            from_second++;
            dfs(match[u], match);
        }
    }
}


int main() {
    cin >> n >> m;
    has_match = vector<bool>(200);
    mc = vector<vector<bool>>(200, vector<bool>(200));
    char ch;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> ch;
            if (ch == 'B') {
                if ((i + j) % 2 == 0) mc[i + j][i - j + m - 1] = true;
            } else if ((i + j) % 2 == 1) mc[i + j][i - j + m - 1] = true;
        }
//        cin >> ch;
    }
    match1 = match2 = vector<int>(200);
    process(result1, match1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            mc[i + j][i - j + m - 1] = !mc[i + j][i - j + m - 1];
        }
    }
    vector<int> mark1(200), mark2(200);
    copy(mark.begin(), mark.end(), mark1.begin());
    process(result2, match2);
    copy(mark.begin(), mark.end(), mark2.begin());
    if (result1 <= result2) print(result1, match1, true, mark1);
    else print(result2, match2, false, mark2);
}

void print(int result, vector<int> &match, bool flag, vector<int> &mark) {
    cout << result << '\n';
    for (int i = 0; i < m + n - 1; ++i) {
        if (match[i] != -1) {
            if (mark[i])
                cout << "2 " << (i + match[i] + 1 - m) / 2 + 1 << ' ' << (match[i] - i + m - 1) / 2 + 1 << ' '
                     << (((match[i] % 2) == 0) ^ flag ? "B" : "W") << '\n';
            else
                cout << "1 " << (i + match[i] + 1 - m) / 2 + 1 << ' ' << (match[i] - i + m - 1) / 2 + 1 << ' '
                     << (((match[i] % 2) == 0) ^ flag ? "B" : "W") << '\n';
        }
    }
}

void process(int &result, vector<int> &match) {
    counter = 0;
    for (int i = 0; i < 200; ++i) c[i].clear();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mc[i + j][i - j + m - 1]) {
                c[i + j].emplace_back(i - j + m - 1);
            }
        }
    }
    mark = take = vector<bool>(200);
    has_match = vector<bool>(200);
    for (int i = 0; i < m + n - 1; ++i) match[i] = -1;
    for (int i = 0; i < m + n - 1; ++i) {
        if (!mark[i]) {
            for (int j = 0; j < m + n - 1; ++j) mark[j] = false;
            if (kuhn(i, match)) counter++;
        }
    }
    for (int i = 0; i < m + n - 1; ++i) if (match[i] != -1) has_match[match[i]] = true;
    for (int i = 0; i < m + n - 1; ++i) mark[i] = false;
        for (int i = 0; i < m + n - 1; ++i) {
        if (!has_match[i]) dfs(i, match);
    }
//    for (int i = 0; i < m + n - 1; ++i) {
//        if ((!mark[i]) && (match[i] != -1)) {
//            take[match[i]] = true;
//            from_first++;
//        }
//    }
    result = counter;
}