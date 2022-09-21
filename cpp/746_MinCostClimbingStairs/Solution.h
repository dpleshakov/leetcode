#pragma once

#include <vector>
#include <cmath>
#include <cassert>

class Solution {
public:
    int minCostClimbingStairs(const std::vector<int> &cost) {
        assert(cost.size() > 0);

        if (cost.size() == 1) {
            return cost[0];
        } else if (cost.size() == 2) {
            return std::min(cost[0], cost[1]);
        }

        int lastMinCost = 0;
        int prevMinCost = 0;
        int prevPrevMinCost = 0;

        for (size_t index = 2; index <= cost.size(); ++index) {
            lastMinCost = std::min(cost[index - 1] + prevMinCost, cost[index - 2] + prevPrevMinCost);
            
            prevPrevMinCost = prevMinCost;
            prevMinCost = lastMinCost;
        }

        return lastMinCost;
    }
};