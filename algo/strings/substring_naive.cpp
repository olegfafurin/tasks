//
// Created by imd on 22/02/2019.
//


#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string s, t;
//    ios::sync_with_stdio(false);
    ifstream fin("search1.in");
    ofstream fout("search1.out");
    getline(fin, s);
    if (!getline(fin, t)) {
        fout << 0 << endl;
        exit(0);
    }
    vector<bool> mark(10000);
    int n;
    if (t.size() < s.size()) {
        fout << 0 << endl;
        exit(0);
    }
    for (int i = 0; i < t.size() - s.size() + 1; ++i) {
        n = 0;
        while ((n < s.size()) && (t[i + n] == s[n])) n++;
        if (n == s.size()) mark[i] = true;
    }
    fout << count(mark.begin(), mark.end(), true) << endl;
    for (int i = 0; i < mark.size(); i++) {
        if (mark[i]) fout << i + 1 << ' ';
    }
    return 0;
}