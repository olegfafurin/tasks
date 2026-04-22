#include "bin_exp.h"
#include "math_types.h"

template <typename T>
T fib(int k) {
	Matrix<T> transform({T(0),T(1),T(1),T(1)});
	Vector<T> state({T(0),T(1)});

	transform = power(transform, k - 1);
	state *= transform;
	return state.y;
}
