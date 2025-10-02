#include <iostream>

using namespace std;

int maxBottlesDrunk(int numBottles, int numExchange) {
    int res = numBottles;
    while (numBottles >= numExchange) {
        res += 1;
        numBottles -= numExchange++;
        numBottles++;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    cout << maxBottlesDrunk(n,m) << '\n';
}

