#include <gtest/gtest.h>
#include <solution.h>

#include <iostream>
#include <vector>

namespace sudoku {

namespace test {

class SolutionTest : public ::testing::Test {
 protected:
  Solution solution_;

  // clang-format off
  const std::vector<std::vector<char>> valid_board_ = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  const std::vector<std::vector<char>> invalid_board_ = {
      {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  const std::vector<std::vector<char>> valid_digits_ = {
      {'1'},
      {'\0'},
      {'a'},
      {'1', '2', '3', '4', '5', '6', '7', '8', '9'},
      {'3', '7', '9', '4', '2', '5', '1', '8', '6'},
      {'\0', '9', '\0', '2', 'a', '1', '\0', '\0'},
      {'a', 'a', 'a', '3'}};
  // clang-format on
};

namespace {

TEST_F(SolutionTest, DISABLED_isValidSudokuTest) {
  EXPECT_TRUE(solution_.isValidSudoku(valid_board_));
  EXPECT_FALSE(solution_.isValidSudoku(invalid_board_));
}

TEST_F(SolutionTest, IsDigitsValidTest) {
  std::vector<std::vector<char>> rows;
  rows.reserve(valid_digits_.size() + valid_board_.size() + invalid_board_.size());
  rows.insert(rows.end(), valid_digits_.begin(), valid_digits_.end());
  rows.insert(rows.end(), valid_board_.begin(), valid_board_.end());
  rows.insert(rows.end(), invalid_board_.begin(), invalid_board_.end());

  for (const auto& row : rows) {
    EXPECT_TRUE(solution_.Test_IsDigitsValid(row)) << "Digits: " << ::testing::PrintToString(row);
  }
}

// TEST_F(SolutionTest, InvalidDigitsToValidate) {
//   const std::vector<char> digitsTovalidate1 = {'1', '1'};
//   const std::vector<char> digitsTovalidate2 = {'1', '2', '3', '2', '5',
//                                                '6', '7', '8', '9'};

//   EXPECT_FALSE(IsDigitsValid(digitsTovalidate1))
//       << "Digits to validate: " << digitsTovalidate1;
//   EXPECT_FALSE(IsDigitsValid(digitsTovalidate2))
//       << "Digits to validate: " << digitsTovalidate2;
// }

}  // namespace

}  // namespace test

}  // namespace sudoku