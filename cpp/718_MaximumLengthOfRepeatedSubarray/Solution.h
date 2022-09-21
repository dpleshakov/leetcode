#pragma once

#include <cassert>
#include <exception>
#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        assert(nums1.size() >= 0);
        assert(nums2.size() >= 0);

        int maxLenght = 0;
        std::vector<int> prevMaxLength(nums2.size(), 0);
        std::vector<int> currentMaxLength(nums2.size(), 0);

        for (size_t index1 = 0; index1 < nums1.size(); ++index1) {
            for (size_t index2 = 0; index2 < nums2.size(); ++index2) {
                if (nums1[index1] == nums2[index2]) {
                    if (index2 >= 1) {
                        currentMaxLength[index2] = 1 + prevMaxLength[index2 - 1];
                    } else {
                        currentMaxLength[index2] = 1;
                    }
                } else {
                    currentMaxLength[index2] = 0;
                }
                maxLenght = std::max(maxLenght, currentMaxLength[index2]);
            }
            prevMaxLength.swap(currentMaxLength);
        }

        return maxLenght;
    }
};