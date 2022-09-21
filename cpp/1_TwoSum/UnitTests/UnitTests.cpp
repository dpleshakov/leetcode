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

			Assert::IsTrue(std::vector<int> {0, 1} == solution.twoSum(std::vector<int> { 2, 7, 11, 15 }, 9));
			Assert::IsTrue(std::vector<int> {1, 2} == solution.twoSum(std::vector<int> { 3, 2, 4 }, 6));
		}
	};
}
