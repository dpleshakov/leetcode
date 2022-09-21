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
		
		TEST_METHOD(TestMethod1) {
			Solution solution;
			std::vector<int> nums;

			nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
			Assert::AreEqual(6, solution.maxSubArray(nums));

			nums = { 1 };
			Assert::AreEqual(1, solution.maxSubArray(nums));

			nums = { 5, 4, -1, 7, 8 };
			Assert::AreEqual(23, solution.maxSubArray(nums));

			nums = { 8, -19, 5, -4, 20 };
			Assert::AreEqual(21, solution.maxSubArray(nums));
		}

		TEST_METHOD(TestMethod2) {
			Solution solution;
			std::vector<int> nums;

			nums = { -1 };
			Assert::AreEqual(-1, solution.maxSubArray(nums));

			nums = { -1, -1 };
			Assert::AreEqual(-1, solution.maxSubArray(nums));

			nums = { 0 };
			Assert::AreEqual(0, solution.maxSubArray(nums));

			nums = { -1, 0, 1 };
			Assert::AreEqual(1, solution.maxSubArray(nums));
		}

		TEST_METHOD(TestMethod3) {
			Solution solution;
			std::vector<int> nums;

			nums = { -99999, 100000 };
			Assert::AreEqual(100000, solution.maxSubArray(nums));
		}

		TEST_METHOD(TestMethod4) {
			Solution solution;
			std::vector<int> nums;

			nums.resize(3000, 100000);
			Assert::AreEqual(300000000, solution.maxSubArray(nums));
		}
	};
}
