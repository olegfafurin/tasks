//
// Created by imd on 15/03/2019.
//

#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main () {
    ifstream fin("z.in");
    ofstream fout("z.out");

    int n;
    string s;
    fin >> s;
    vector<int> z(1000000);
    n = s.size();
    int l = 0, r = 0;
    for (int i = 1 ; i < n; ++i) {
        if (i < r + 1) z[i] = min(r + 1 - i, z[i - l]);
        while (z[i] < n - i && s[z[i]] == s[z[i] + i]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    for (int i = 1 ; i < n; ++i) { fout << z[i] << ' '; }
    fout.close();
}