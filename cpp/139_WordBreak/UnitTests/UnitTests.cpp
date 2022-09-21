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

			Assert::AreEqual(true, solution.wordBreak("leetcode", std::vector<std::string> { "leet", "code" }));
			Assert::AreEqual(true, solution.wordBreak("applepenapple", std::vector<std::string> { "apple", "pen" }));
			Assert::AreEqual(false, solution.wordBreak("catsandog", std::vector<std::string> { "cats", "dog", "sand", "and", "cat" }));

			Assert::AreEqual(true, solution.wordBreak("catsand", std::vector<std::string> { "cat", "cats", "san", "and" }));

			Assert::AreEqual(true, solution.wordBreak("test", std::vector<std::string> { "test" }));
			Assert::AreEqual(false, solution.wordBreak("test", std::vector<std::string> { "check" }));
		}
	};
}
