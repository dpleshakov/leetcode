#pragma once

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int> &nums, int target) {
        std::unordered_map<int, size_t> differenceMap;

        for (size_t index = 0; index < nums.size(); ++index) {
            int difference = target - nums[index];

            auto differenceIterator = differenceMap.find(difference);
            if (differenceIterator != differenceMap.end()) {
                return std::vector<int> { (int)differenceIterator->second, (int)index };
            } else {
                differenceMap[nums[index]] = index;
            }
        }

        throw new std::exception();
    }
};