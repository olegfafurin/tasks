#include<string>
#include<iostream>


using namespace std;

string maxSumOfSquares(int num, int sum) {
    if (num * 9 < sum) {
        return "";
    }
    string s = "";
    s.reserve(num);
    for (int i = 0; i < num; ++i) {
        int d = min(sum, 9);
        s.push_back('0' + d);
        sum -= d;
    }
    return s;
}


int main() {
    cout << maxSumOfSquares(10,87) << '\n';
}