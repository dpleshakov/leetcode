#pragma once

#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2) {
			return 0;
		}

		int maxPrice = 0;
		int profit = 0;
		for (int index = prices.size() - 1; index >= 0; --index) {
			profit = max(profit, maxPrice - prices[index]);
			maxPrice = max(maxPrice, prices[index]);
		}

		return profit;
	}
};