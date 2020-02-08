//
// Created by imd on 9/25/2019.
//

#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <cmath>

static const size_t INF = 1000;
using namespace std;
ifstream fin;

void readchunk(int k) {
    char c;
    for (int i = 0; i < k; ++i) {
        fin >> c;
        cout << c;
    }
}

void decrypt(const string &s, const vector<int> &key) {
    ofstream hout("decoded.out");
    int l = s.size();
    int k = key.size();
    for (int i = 0; i < l; i += k) {
        int j = min(l, i + k);
        if (j - i >= k) {
            for (int m = 0; m < k; ++m) hout << s[i + key[m]];
        } else {
            string t = s.substr(i);
            while (t.size() < k) t += ' ';
            vector<char> v = vector<char>();
            for (int m = 0; m < k; ++m) v.push_back(t[key[m]]);
            for (auto sym : v) if (sym != ' ') hout << sym;
        }
    }
    hout.flush();
    hout.close();
    cout << "\nDone!";
    exit(0);
}

void normalize(vector<vector<double>> &p) {
    for (int i = 0; i < p.size(); i++) {
        double sq = 0;
        for (int j = 0; j < p[i].size(); j++) sq += p[i][j];
        if (sq == 0) continue;
        for (int j = 0; j < p[i].size(); j++) p[i][j] /= sq;
    }
}

vector<int> make_chain(vector<int> &match, vector<bool> &visited, int start) {
    int current = start;
    visited[start] = true;
    vector<int> current_chain = vector<int>{start};
    if (!visited[match[current]]) {
        current = match[current];
        visited[current] = true;
        current_chain.push_back(current);
    }
    return current_chain;
}

//int locate_min(vector<int> &match, int start) {
//    auto candidate = make_pair(1000,-1);
//    int current = start;
//    do {
//        candidate = min(candidate, make_pair(match[current]))
//    }
//}

int main(int argc, char **argv) {
    cout.precision(2);
    if (argc < 2) {
        cout << "Usage: decrypt <filename>";
        exit(1);
    }
    cout << argv[1] << '\n';
    fin = ifstream(argv[1]);
    ifstream statstream("stat.data");
    map<string, double> h = map<string, double>();
    fin.tie();
    string s;
    while (getline(statstream, s)) {
        string t = s.substr(0, 2);
        int n = stoi(s.substr(s.find(':') + 1));
        h.insert(make_pair(t, n));
    }
    fin >> s;
    double summ = 0;
    for (const auto &entry : h) summ += entry.second * entry.second;
    double coeff = sqrt(summ);
    for (auto &entry : h) entry.second /= coeff;
    for (int k = 2; k < 50; k++) {
        vector<bool> visited(k, false);
        vector<vector<double>> priority(k + 1, vector<double>(k + 1));
        int chunk_start = 0;
        while (chunk_start < s.size()) {
            int rest = s.size() - chunk_start;
            for (int i = 0; i < min(k, rest); ++i) {
                for (int j = 0; j < min(k, rest); ++j) {
                    if (i == j) continue;
                    priority[i + 1][j + 1] += h.at(string() + s[chunk_start + i] + s[chunk_start + j]);
                }
            }
            chunk_start += k;
        }
        normalize(priority);
        for (int i = 1; i < k + 1; ++i) {
            cout << i << ": ";
            for (int j = 1; j < k + 1; ++j) {
                cout << (int) (priority[i][j] * 50 * (k - 1)) << ' ';
            }
            cout << '\n';
        }
        int start_index = 0;
        vector<int> match(k);
        vector<int> reverse(k, -1);
        for (int i = 0; i < k; ++i) {
            match[i] = max_element(priority[i + 1].begin(), priority[i + 1].end()) - priority[i + 1].begin() - 1;
        }
        vector<char> present(k);
        for (int i = 0; i < k; ++i) present[match[i]] += 1;
        for (int i = 0; i < k; ++i) {
            if (present[i] == 0) {
                present[i] = -1;
                if (!visited[i]) make_chain(match, visited, i);
            }
        }
        for (int i = 0; i < k; i++) {
            if (!visited[i]) {
//                locate_min(i);
            }
        }

        for (int i = 0; i < k; ++i) {
            double cur_min = 0;
            if (priority[i][match[i]] < cur_min) {
                cur_min = priority[i][match[i]];
                start_index = match[i];
            }
        }

        vector<int> perm = vector<int>();
        cout << k << " : ";
        for (int i = 0; i < k; ++i) {
            perm.push_back(start_index);
            cout << start_index << ' ';
            start_index = match[start_index];
        }
        cout << "\n> ";
        chunk_start = 0;
        while (chunk_start < min(50, (int) s.size() - k)) {
            int chunk_end = chunk_start + k;
            for (int i = 0; i < k; ++i) cout << s[chunk_start + perm[i]];
            chunk_start += k;
        }
        cout << "\nAccept? (y/n) >\n";
        string t;
        cin >> t;
        if (t == "y") {
            decrypt(s, perm);
        }
    }

}