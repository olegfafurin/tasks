#include <vector>

// started at 8:53

int fib(int k) {
	int a = 0;
	int b = 1;
	for (int i = 0; i < k - 1; ++i) {
		b += a;
		a = b - a;
	}
	return b;
}