#include <iostream>

#include "big_int.h"
#include "fib_matrix.h"


using namespace std;

int main() {
    for (int i = 1; i <= 10000; ++i) {
        cout << i << ' ' << fib<BigInteger>(i) << '\n';
    }
}
