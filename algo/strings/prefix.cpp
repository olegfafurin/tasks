//
// Created by imd on 08.06.2019.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");

    string s;
    fin >> s;
    int n = s.size();

    vector<int> p(1'000'000);
    for (int i = 1; i < n; i++) {
        if (s[p[i - 1]] == s[i]) p[i] = p[i - 1] + 1;
        else {
            int prev = p[i - 1];
            while (prev > 0 && s[i] != s[prev]) prev = p[prev - 1];
            p[i] = (s[i] == s[prev]) ? prev + 1 : prev;
        }
    }

    for (int i = 0; i < n; ++i) {
        fout << p[i] << ' ';
    }
}