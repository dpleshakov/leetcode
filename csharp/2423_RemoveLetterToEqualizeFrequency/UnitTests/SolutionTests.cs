using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace _2423_RemoveLetterToEqualizeFrequency.UnitTests
{
    [TestClass()]
    public class SolutionTests
    {
        [TestMethod()]
        public void EqualFrequencyLeetcodeTests() {
            Assert.IsTrue(Solution.EqualFrequency("abcc"));
            Assert.IsTrue(Solution.EqualFrequency("aazz"));
        }

        [TestMethod()]
        public void EqualFrequencyPositiveTests() {
            Assert.IsTrue(Solution.EqualFrequency("aa"));
            Assert.IsTrue(Solution.EqualFrequency("ab"));
            Assert.IsTrue(Solution.EqualFrequency("ba"));
            Assert.IsTrue(Solution.EqualFrequency("kl"));
            Assert.IsTrue(Solution.EqualFrequency("zz"));

            Assert.IsTrue(Solution.EqualFrequency("bbb"));
            Assert.IsTrue(Solution.EqualFrequency("abb"));
            Assert.IsTrue(Solution.EqualFrequency("bab"));
            Assert.IsTrue(Solution.EqualFrequency("bba"));
            Assert.IsTrue(Solution.EqualFrequency("klm"));

            Assert.IsTrue(Solution.EqualFrequency("abcd"));
            Assert.IsTrue(Solution.EqualFrequency("aaaa"));
            Assert.IsTrue(Solution.EqualFrequency("abbc"));
            Assert.IsTrue(Solution.EqualFrequency("babc"));
            Assert.IsTrue(Solution.EqualFrequency("bbac"));
            Assert.IsTrue(Solution.EqualFrequency("abcb"));
            Assert.IsTrue(Solution.EqualFrequency("acbb"));
        }

        [TestMethod()]
        public void EqualFrequencyNegativeTests() {
            Assert.IsFalse(Solution.EqualFrequency("aaab"));
            Assert.IsFalse(Solution.EqualFrequency("aaba"));
            Assert.IsFalse(Solution.EqualFrequency("abaa"));
            Assert.IsFalse(Solution.EqualFrequency("baaa"));

            Assert.IsFalse(Solution.EqualFrequency("baba"));
            Assert.IsFalse(Solution.EqualFrequency("bbaa"));
            Assert.IsFalse(Solution.EqualFrequency("baab"));
        }

        [TestMethod()]
        public void EqualFrequencyStressTests() {
            string input = new string('a', 100);
            Assert.IsTrue(Solution.EqualFrequency(input));

            input = new string('a', 50) + new string('b', 50);
            Assert.IsFalse(Solution.EqualFrequency(input));

            input = new string('a', 50) + new string('b', 49);
            Assert.IsTrue(Solution.EqualFrequency(input));

            input = new string('a', 52) + new string('b', 48);
            Assert.IsFalse(Solution.EqualFrequency(input));

            input = new string('a', 75) + new string('b', 25);
            Assert.IsFalse(Solution.EqualFrequency(input));

            input = new string('a', 25) + new string('b', 25) + new string('a', 25) + new string('b', 25);
            Assert.IsFalse(Solution.EqualFrequency(input));

            input = new string('a', 25) + new string('b', 24) + new string('a', 25) + new string('b', 25);
            Assert.IsTrue(Solution.EqualFrequency(input));
        }
    }
}