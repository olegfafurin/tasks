#include <vector>

// started at 8:53

template <typename T>
T fib(int k) {
	T a(0);
	T b(1);
	for (int i = 0; i < k - 1; ++i) {
		b += a;
		a = b - a;
	}
	return b;
}