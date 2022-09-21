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

			Assert::AreEqual(true, solution.isSubsequence("a", "a"));
			Assert::AreEqual(true, solution.isSubsequence("a", "ab"));
			Assert::AreEqual(true, solution.isSubsequence("a", "ba"));

			Assert::AreEqual(false, solution.isSubsequence("b", "a"));

			Assert::AreEqual(true, solution.isSubsequence("ab", "ab"));
			Assert::AreEqual(false, solution.isSubsequence("ba", "ab"));

			Assert::AreEqual(true, solution.isSubsequence("ab", "abc"));
			Assert::AreEqual(true, solution.isSubsequence("ab", "acb"));
			Assert::AreEqual(true, solution.isSubsequence("abc", "abc"));
		}

		TEST_METHOD(TestMethod2) 		{
			Solution solution;

			Assert::AreEqual(true, solution.isSubsequence("abc", "ahbgdc"));
			Assert::AreEqual(false, solution.isSubsequence("axc", "ahbgdc"));
		}

		TEST_METHOD(TestMethod3) 		{
			Solution solution;

			Assert::AreEqual(false, solution.isSubsequence("acb", "ahbgdc"));
			Assert::AreEqual(true, solution.isSubsequence("hgd", "ahbgdc"));
			Assert::AreEqual(true, solution.isSubsequence("hbgd", "ahbgdc"));
		}

		TEST_METHOD(TestMethod4) {
			Solution solution;

			Assert::AreEqual(true, solution.isSubsequence("", ""));
			Assert::AreEqual(true, solution.isSubsequence("", "ahbgdc"));
			Assert::AreEqual(false, solution.isSubsequence("hbgd", ""));
		}

		TEST_METHOD(TestMethod5) {
			Solution solution;

			Assert::AreEqual(false, solution.isSubsequence("hdello", "helloworld"));
			Assert::AreEqual(true, solution.isSubsequence("aaabbbaaa", "ababababababababa"));
		}
	};
}
