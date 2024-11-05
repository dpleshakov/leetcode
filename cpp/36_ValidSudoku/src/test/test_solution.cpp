#include <gtest/gtest.h>
#include <solution.h>

#include <vector>

class SolutionTest : public ::testing::Test {
 public:
  bool isDigitsValid(const std::vector<char> digits) {
    return solution.isDigitsValid(digits);
  }

 protected:
  Solution solution;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  os << "[ ";
  for (const auto& element : vec) {
    os << "'" << element << "' ";
  }
  os << "]";
  return os;
}

TEST_F(SolutionTest, ValidSudoku) {
  const std::vector<std::vector<char>> board = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  EXPECT_TRUE(solution.isValidSudoku(board));
}

TEST_F(SolutionTest, InvalidSudoku) {
  const std::vector<std::vector<char>> board = {
      {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  EXPECT_FALSE(solution.isValidSudoku(board));
}

TEST_F(SolutionTest, ValidDigitsToValidate) {
  const std::vector<char> digitsTovalidate1 = {'1'};
  const std::vector<char> digitsTovalidate2 = {'\0'};
  const std::vector<char> digitsTovalidate3 = {'a'};
  const std::vector<char> digitsTovalidate2 = {'1', '2', '3', '4', '5',
                                               '6', '7', '8', '9'};
  const std::vector<char> digitsTovalidate3 = {'3', '7', '9', '4', '2',
                                               '5', '1', '8', '6'};
  const std::vector<char> digitsTovalidate4 = {'\0', '9', '\0', '2',
                                               'a',  '1', '\0', '\0'};
  const std::vector<char> digitsTovalidate5 = {'a', 'a', 'a', '3'};

  EXPECT_TRUE(isDigitsValid(digitsTovalidate1))
      << "Digits to validate: " << digitsTovalidate1;
  EXPECT_TRUE(isDigitsValid(digitsTovalidate2))
      << "Digits to validate: " << digitsTovalidate2;
  EXPECT_TRUE(isDigitsValid(digitsTovalidate3))
      << "Digits to validate: " << digitsTovalidate3;
  EXPECT_TRUE(isDigitsValid(digitsTovalidate4))
      << "Digits to validate: " << digitsTovalidate4;
  EXPECT_TRUE(isDigitsValid(digitsTovalidate5))
      << "Digits to validate: " << digitsTovalidate5;
}

TEST_F(SolutionTest, InvalidDigitsToValidate) {
  const std::vector<char> digitsTovalidate1 = {'1', '1'};
  const std::vector<char> digitsTovalidate2 = {'1', '2', '3', '2', '5',
                                               '6', '7', '8', '9'};

  EXPECT_FALSE(isDigitsValid(digitsTovalidate1))
      << "Digits to validate: " << digitsTovalidate1;
  EXPECT_FALSE(isDigitsValid(digitsTovalidate2))
      << "Digits to validate: " << digitsTovalidate2;
}