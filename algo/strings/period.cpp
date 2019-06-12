//
// Created by imd on 08.06.2019.
//


#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("period.in");
    ofstream fout("period.out");

    string s;
    fin >> s;
    vector<int> z(1000000);
    int n = s.size();
    int l = 0, r = 0;
    for (int i = 1 ; i < n; ++i) {
        if (i < r + 1) z[i] = min(r + 1 - i, z[i - l]);
        while (z[i] < n - i && s[z[i]] == s[z[i] + i]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    for (int i = 1 ; i < n; ++i) {
        if (z[i] + i == n && n % i == 0) {
            fout << i;
            fout.close();
            return 0;
        }
    }
    fout << n;
    fout.close();
    return 0;
}