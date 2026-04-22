#ifndef MATH_TYPES_H
#define MATH_TYPES_H

template <typename T>
struct Matrix {
	T a00, a01, a10, a11;

	Matrix& operator*=(const Matrix &other) {
		T c00 = a00 * other.a00 + a01 * other.a10;
		T c01 = a00 * other.a01 + a01 * other.a11;
		T c10 = a10 * other.a00 + a11 * other.a10;
		T c11 = a10 * other.a01 + a11 * other.a11;
		a00 = c00;
		a01 = c01;
		a10 = c10;
		a11 = c11;
		return *this;
	}

	friend Matrix operator*(Matrix lhs, Matrix& rhs) {
		lhs *= rhs;
		return lhs;
	}

	static Matrix identity() {
		return {T(1),T(0),T(0),T(1)};
	}
};

template <typename T>
struct Vector {
	T x, y;

	Vector& operator*=(const Matrix<T> &other) {
		T newX = x * other.a00 + y * other.a10;
		T newY = x * other.a01 + y * other.a11;
		x = newX;
		y = newY;
		return *this;
	}
};

#endif