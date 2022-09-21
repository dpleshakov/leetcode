#include "pch.h"
#include "CppUnitTest.h"
#include "../Solution.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests {
	TEST_CLASS(UnitTests) {
	public:
		
		TEST_METHOD(TestMethod1) {
			Solution solution;
			vector<int> prices;
			
			prices = { 1 };
			Assert::AreEqual(0, solution.maxProfit(prices));

			prices = { 9999 };
			Assert::AreEqual(0, solution.maxProfit(prices));

			prices = { 0 };
			Assert::AreEqual(0, solution.maxProfit(prices));

			prices = { 123 };
			Assert::AreEqual(0, solution.maxProfit(prices));
		}

		TEST_METHOD(TestMethod2) {
			Solution solution;
			vector<int> prices;
			
			prices = { 1, 2 };
			Assert::AreEqual(1, solution.maxProfit(prices));

			prices = { 2, 1 };
			Assert::AreEqual(0, solution.maxProfit(prices));

			prices = { 1, 1 };
			Assert::AreEqual(0, solution.maxProfit(prices));

			prices = { 0, 1 };
			Assert::AreEqual(1, solution.maxProfit(prices));

			prices = { 1, 0 };
			Assert::AreEqual(0, solution.maxProfit(prices));

			prices = { 9999, 9999 };
			Assert::AreEqual(0, solution.maxProfit(prices));
			
			prices = { 9998, 9999 };
			Assert::AreEqual(1, solution.maxProfit(prices));

			prices = { 9999, 9998 };
			Assert::AreEqual(0, solution.maxProfit(prices));

			prices = { 123, 321 };
			Assert::AreEqual(198, solution.maxProfit(prices));

			prices = { 951, 12};
			Assert::AreEqual(0, solution.maxProfit(prices));
		}

		TEST_METHOD(TestMethod3) {
			Solution solution;
			vector<int> prices;

			prices = { 1, 2, 3 };
			Assert::AreEqual(2, solution.maxProfit(prices));

			prices = { 1, 3, 2 };
			Assert::AreEqual(2, solution.maxProfit(prices));
			
			prices = { 2, 1, 3 };
			Assert::AreEqual(2, solution.maxProfit(prices));

			prices = { 2, 3, 1 };
			Assert::AreEqual(1, solution.maxProfit(prices));

			prices = { 3, 1, 2 };
			Assert::AreEqual(1, solution.maxProfit(prices));

			prices = { 3, 2, 1 };
			Assert::AreEqual(0, solution.maxProfit(prices));
		}

		TEST_METHOD(TestMethod4) {
			Solution solution;
			vector<int> prices;

			prices = { 7, 1, 5, 3, 6, 4 };
			Assert::AreEqual(5, solution.maxProfit(prices));

			prices = { 7, 6, 4, 3, 1 };
			Assert::AreEqual(0, solution.maxProfit(prices));
		}
	};
}
