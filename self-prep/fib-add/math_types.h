struct Matrix {
	int a00, a01, a10, a11;

	Matrix& operator*=(const Matrix &other) {
		int c00 = a00 * other.a00 + a01 * other.a10;
		int c01 = a00 * other.a01 + a01 * other.a11;
		int c10 = a10 * other.a00 + a11 * other.a10;
		int c11 = a10 * other.a01 + a11 * other.a11;
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
		return {1,0,0,1};
	}

};

struct Vector {
	int x, y;

	Vector& operator*=(const Matrix &other) {
		int newX = x * other.a00 + y * other.a10;
		int newY = x * other.a01 + y * other.a11;
		x = newX;
		y = newY;
		return *this;
	}
};
