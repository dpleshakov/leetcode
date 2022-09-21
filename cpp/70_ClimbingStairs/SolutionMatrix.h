#pragma once

#include <cstddef>
#include <cassert>
#include "Solution.h"

struct Matrix {
	int _internalMatrix[2][2];

	Matrix(int element00, int element01, int element10, int element11)
		: _internalMatrix {element00, element01, element10, element11}
	{ }

	int operator() (std::size_t row, std::size_t column) const {
		assert(row >= 0 && row < 2);
		assert(column >= 0 && column < 2);

		return _internalMatrix[row][column]; 
	}

	int& operator() (std::size_t row, std::size_t column) {
		assert(row >= 0 && row < 2);
		assert(column >= 0 && column < 2);

		return _internalMatrix[row][column];
	}

	friend Matrix operator* (const Matrix& left, const Matrix& right) {
		Matrix answer(0, 0, 0, 0);

		for (std::size_t row = 0; row < 2; ++row) {
			for (std::size_t column = 0; column < 2; ++column) {
				for (std::size_t index = 0; index < 2; ++index) {
					answer(row, column) += left(row, index) * right(index, column);
				}
			}
		}

		return answer;
	}

	Matrix pow(int n) {
		assert(n >= 0);

		if (n == 0) {
			return Matrix(1, 0, 0, 1);
		} else if (n % 2 == 0) {
			Matrix sqrt = this->pow(n / 2);
			return sqrt * sqrt;
		} else {
			return *this * this->pow(n - 1);
		}
	}
};

class SolutionMatrix : Solution {
public:
	int climbStairs(int n) {
		return Matrix(0, 1, 1, 1).pow(n)(1, 1);
	}
};