#pragma once

#include <cassert>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
        assert(nums.size() > 0);

        /*int sum = 0;
        int maxSum = INT_MIN;

        for (std::size_t index = 0; index < nums.size(); ++index) {
            sum += nums[index];
            maxSum = std::max(sum, maxSum);
            sum = std::max(sum, 0);
        }*/

        int currentMax = nums[0];
        int maxSum = nums[0];

        for (std::size_t index = 1; index < nums.size(); ++index) {
            currentMax = std::max(currentMax + nums[index], nums[index]);
            maxSum = std::max(maxSum, currentMax);
        }

        return maxSum;
    }
};