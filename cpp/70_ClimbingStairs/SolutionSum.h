#pragma once

#include <cstddef>
#include <cassert>
#include "Solution.h"

class SolutionSum : Solution {
public:
    int climbStairs(int n) {
        assert(n >= 0);

        if (0 == n || 1 == n) {
            return 1;
        }

        unsigned int previousNumber = 1;
        unsigned int previousPreviousNumber = 1;

        for (int number = 2; number < n; ++number) {
            unsigned int currentNumber = previousNumber + previousPreviousNumber;
            previousPreviousNumber = previousNumber;
            previousNumber = currentNumber;
        }

        return previousNumber + previousPreviousNumber;
    }
};