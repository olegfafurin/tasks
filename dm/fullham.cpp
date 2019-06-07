//
// Created by imd on 11/2/2018.
//

#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

int main() {
    ifstream fin("fullham.in");
    ofstream fout("fullham.out");
    int n;
    char a;
    vector<int> b;
    fin >> n;
    vector<vector<char>> connect(4000, vector<char>(4000));
    deque<int> order;
    for (int i = 0; i < n; i++) {
        order.push_back(i);
        for (int j = 0; j < i; j++) {
            fin >> a;
            connect[i][j] = a - '0';
            connect[j][i] = a - '0';
        }
    }
    for (int i = 0; i < (n - 1) * n; i++) {
        if (!connect[order[0]][order[1]]) {
            int k = 1;
            while ((k < n - 1) && (!((connect[order[k]][order[0]]) && (connect[order[k + 1]][order[1]])))) k++;
            reverse(order.begin() + 1, order.begin() + k + 1);
        }
        order.push_back(order.front());
        order.pop_front();
    }
    for (int i = 0; i < order.size(); i++) {
        fout << order[i] + 1 << ' ';
    }


}