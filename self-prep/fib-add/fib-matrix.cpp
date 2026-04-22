#include "bin_exp.h"
#include "math_types.h"

int fib(int k) {
	Matrix transform({0,1,1,1});
	Vector state({0,1});

	transform = power(transform, k - 1);
	state *= transform;
	return state.y;
}
