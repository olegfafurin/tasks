//
// Created by imd on 08.06.2019.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("search2.in");
    ofstream fout("search2.out");

    string p, s;
    fin >> p >> s;
    s = p + "`" + s;

    vector<int> z(2'000'001);
    int n = s.size();
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r + 1) z[i] = min(r + 1 - i, z[i - l]);
        while (z[i] < n - i && s[z[i]] == s[z[i] + i]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    int c = 0;
    vector<bool> matched(2'000'001);
    for (int i = p.size() + 1; i < n; ++i) {
        if (z[i] == p.size()) {
            c++;
            matched[i] = true;
        }
    }
    fout << c << '\n';

    for (int i = p.size() + 1; i < n; ++i) {
        if (matched[i]) fout << i - p.size() << ' ';
    }
    fout.close();
}