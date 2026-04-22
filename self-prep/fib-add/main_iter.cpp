#include <iostream>
#include "fib_iter.h"

using namespace std;

int main() {
	for (int i = 1; i <= 45; ++i) {
		cout << i << ' ' << fib<int>(i) << '\n';
	}
}