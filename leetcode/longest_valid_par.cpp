//
// Created by imd on 10/9/2019.
//

#include <vector>
#include <iostream>
#include <stack>

using namespace std;
int cnt = 0;


int longestValidParentheses(string s) {
    auto p = stack<int>({-1});
    int longest = 0;
    for (char c : s) {
        switch (c) {
            case '(':
                p.push(cnt++);
                break;
            case ')':
                if (!p.empty()) {
                    p.pop();
                    if (p.empty()) p.push(cnt++);
                    else longest = max(longest, cnt++ - p.top());
                }
                break;
            default:
                break;
        }
    }
    return longest;
}

int main() {
    cout << longestValidParentheses("))))()())");
}