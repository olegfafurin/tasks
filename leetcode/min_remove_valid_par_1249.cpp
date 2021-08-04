//
// Created by Oleg.Fafurin on 04.08.2021.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string minRemoveToMakeValid(string s) {
    vector<size_t> v;
    pair<int, int> min_balance = {0, -1};
    int balance = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            balance += 1;
        } else if (s[i] == ')') {
            balance -= 1;
            if (min_balance.first > balance) {
                min_balance.first = balance;
                v.push_back(i);
            }
        }
    }
    balance = 0, min_balance = {0, -1};
    for (int i = s.size() - 1; i > min_balance.second; --i) {
        if (s[i] == ')') {
            balance += 1;
        } else if (s[i] == '(') {
            balance -= 1;
            if (min_balance.first > balance) {
                min_balance.first = balance;
                v.push_back(i);
            }
        }
    }
    string t;
    for (int i = 0; i < v.size(); ++i) {
        s[v[i]] = '-';
    }
    for (char c: s) {
        if (c != '-')
            t += c;
    }
    return t;
}

int main() {
    cout << minRemoveToMakeValid("lee(t(c)o)de)") << endl;
    cout << minRemoveToMakeValid("a)b(c)d") << endl;
    cout << minRemoveToMakeValid("))((") << endl;
    cout << minRemoveToMakeValid("") << endl;
    cout << minRemoveToMakeValid("(a(b(c)d)") << endl;
    cout << minRemoveToMakeValid("())()(((") << endl;
}