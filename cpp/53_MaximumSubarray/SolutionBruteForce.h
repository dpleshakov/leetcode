#pragma once

#pragma once

#include <vector>
#include <math.h>

using namespace std;

class SolutionBruteForce {
public:
    int sumSubArray(const std::vector<int>& nums, unsigned int startIndex, unsigned int endIndex) {
        int sum = 0;
        for (unsigned int index = startIndex; index <= endIndex; ++index) {
            sum += nums[index];
        }
        return sum;
    }

    int maxSubArray(vector<int>& nums) {
        int maxSum = INT32_MIN;
        for (unsigned int startIndex = 0; startIndex < nums.size(); ++startIndex) {
            for (unsigned int endIndex = startIndex; endIndex < nums.size(); ++endIndex) {
                maxSum = std::max(maxSum, sumSubArray(nums, startIndex, endIndex));
            }
        }
        return maxSum;
    }
};