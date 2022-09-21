#include "pch.h"
#include "CppUnitTest.h"

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

			Assert::AreEqual(3, solution.findLength(std::vector<int> { 1, 2, 3, 2, 1 }, std::vector<int> { 3, 2, 1, 4, 7 }));
			Assert::AreEqual(5, solution.findLength(std::vector<int> { 0, 0, 0, 0, 0 }, std::vector<int> { 0, 0, 0, 0, 0 }));

			Assert::AreEqual(3, solution.findLength(std::vector<int> { 1, 0, 0, 0, 1, 0, 0, 1, 0, 0 }, std::vector<int> { 0, 1, 1, 1, 0, 1, 1, 1, 0, 0 }));

			Assert::AreEqual(3, solution.findLength(std::vector<int> { 3, 2, 1, 4, 7 }, std::vector<int> { 1, 2, 3, 2, 1 }));
		}

		TEST_METHOD(TestMethod2) {
			Solution solution;

			Assert::AreEqual(0, solution.findLength(std::vector<int> { 1 }, std::vector<int> { 0 }));
			Assert::AreEqual(0, solution.findLength(std::vector<int> { 0 }, std::vector<int> { 1 }));
			Assert::AreEqual(1, solution.findLength(std::vector<int> { 0 }, std::vector<int> { 0 }));
			Assert::AreEqual(1, solution.findLength(std::vector<int> { 1 }, std::vector<int> { 1 }));

			Assert::AreEqual(1, solution.findLength(std::vector<int> { 0, 1 }, std::vector<int> { 1 }));
			Assert::AreEqual(1, solution.findLength(std::vector<int> { 0, 1 }, std::vector<int> { 0 }));

			Assert::AreEqual(2, solution.findLength(std::vector<int> { 0, 1 }, std::vector<int> { 0, 1 }));
			Assert::AreEqual(1, solution.findLength(std::vector<int> { 0, 1 }, std::vector<int> { 1, 0 }));

			Assert::AreEqual(2, solution.findLength(std::vector<int> { 0, 1, 0, 1 }, std::vector<int> { 0, 1 }));
			Assert::AreEqual(2, solution.findLength(std::vector<int> { 0, 1 }, std::vector<int> { 0, 1, 0, 1 }));
		}
	};
}
