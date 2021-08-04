//
// Created by Oleg.Fafurin on 05.08.2021.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check(unsigned int value, int bit_count) {
    int balance = 0;
    for (int j = 0; j < bit_count; ++j) {
        if (value % 2 == 0) {
            balance += 1;
        } else {
            balance -= 1;
            if (balance < 0)
                return false;
        }
        value >>= 1;
    }
    return (balance == 0);
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    unsigned int bound = 1;
    for (int i = 0; i < 2 * n; ++i)
        bound <<= 1;
    for (unsigned int i = 0; i < bound; ++i) {
        unsigned int value = i;
        string s;
        if (check(i, 2 * n)) {
            for (int j = 0; j < 2 * n; ++j) {
                if (value % 2 == 0) {
                    s += '(';
                } else {
                    s += ')';
                }
                value >>= 1;
            }
        }
        if (!s.empty())
            result.push_back(s);
    }
    return result;
}

int main() {
    for (const string& s : generateParenthesis(8)) {
        cout << s << endl;
    }
}