#include <iostream>

using namespace std;

int numWaterBottles(int numBottles, int numExchange) {
    int res = numBottles;
    while (numBottles >= numExchange) {
        res += numBottles / numExchange;
        numBottles = numBottles / numExchange + numBottles % numExchange;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    cout << numWaterBottles(n,m) << '\n';
}