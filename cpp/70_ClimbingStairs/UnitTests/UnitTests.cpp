#include "pch.h"
#include "CppUnitTest.h"
#include "../SolutionSum.h"
#include "../SolutionMatrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			//SolutionSum solution;
			SolutionMatrix solution;

			//Assert::AreEqual(1, solution.climbStairs(0));
			Assert::AreEqual(1, solution.climbStairs(1));
			Assert::AreEqual(2, solution.climbStairs(2));
			Assert::AreEqual(3, solution.climbStairs(3));
			Assert::AreEqual(5, solution.climbStairs(4));
			Assert::AreEqual(8, solution.climbStairs(5));

			Assert::AreEqual(14930352, solution.climbStairs(35));
		}
	};
}
