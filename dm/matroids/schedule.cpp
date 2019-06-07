//
// Created by imd on 08/12/2018.
//

#include "bits/stdc++.h"

using namespace std;

int main() {
    ifstream fin("schedule.in");
    ofstream fout("schedule.out");

    int n;
    vector<pair<int, int>> tasks(100000);
    fin >> n;
    for (int i = 0; i < n; ++i) fin >> tasks[i].first >> tasks[i].second;

    for (int i = 0; i < n; ++i) {

    }

    fout.close();
}