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

			Assert::AreEqual(true, solution.divisorGame(2));
			Assert::AreEqual(false, solution.divisorGame(3));
		}
	};
}
