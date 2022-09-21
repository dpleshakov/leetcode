#include "pch.h"
#include "CppUnitTest.h"
#include <vector>

#include "../Solution.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Solution solution;

			Assert::AreEqual(15, solution.minCostClimbingStairs(std::vector<int> {10, 15, 20}));
			Assert::AreEqual(6, solution.minCostClimbingStairs(std::vector<int> {1, 100, 1, 1, 1, 100, 1, 1, 100, 1}));

			Assert::AreEqual(1, solution.minCostClimbingStairs(std::vector<int> {1, 100}));
		}
	};
}
