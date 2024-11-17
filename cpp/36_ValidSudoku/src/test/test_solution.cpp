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

  const std::vector<std::vector<char>> invalid_digits_ = {
      {'1', '1'},
      {'1', '2', '3', '2', '5', '6', '7', '8', '9'}};
  // clang-format on
};

namespace {

TEST_F(SolutionTest, DISABLED_isValidSudokuTest) {
  EXPECT_TRUE(solution_.isValidSudoku(valid_board_));
  EXPECT_FALSE(solution_.isValidSudoku(invalid_board_));
}

TEST_F(SolutionTest, IsRowValidTest) {
  for (size_t row_index = 0; row_index < valid_board_.size(); ++row_index) {
    EXPECT_TRUE(solution_.Test_IsRowValid(valid_board_, row_index)) << "Row index: " << row_index;
  }

  for (size_t row_index = 0; row_index < invalid_board_.size(); ++row_index) {
    EXPECT_TRUE(solution_.Test_IsRowValid(invalid_board_, row_index)) << "Row index: " << row_index;
  }
}

TEST_F(SolutionTest, IsColumnValidTest) {
  ASSERT_TRUE(valid_board_.size() > 0);

  for (size_t column_index = 0; column_index < valid_board_[0].size(); ++column_index) {
    EXPECT_TRUE(solution_.Test_IsColumnValid(valid_board_, column_index)) << "Column index: " << column_index;
  }

  ASSERT_TRUE(invalid_board_.size() > 0);
  ASSERT_TRUE(invalid_board_[0].size() > 0);

  EXPECT_FALSE(solution_.Test_IsColumnValid(invalid_board_, 0)) << "Column index: 0";

  for (size_t column_index = 1; column_index < invalid_board_[0].size(); ++column_index) {
    EXPECT_TRUE(solution_.Test_IsColumnValid(invalid_board_, column_index)) << "Column index: " << column_index;
  }
}

TEST_F(SolutionTest, IsDigitsValidTest) {
  for (const auto& digits : valid_digits_) {
    EXPECT_TRUE(solution_.Test_IsDigitsValid(digits)) << "Digits: " << ::testing::PrintToString(digits);
  }

  for (const auto& digits : invalid_digits_) {
    EXPECT_FALSE(solution_.Test_IsDigitsValid(digits)) << "Digits: " << ::testing::PrintToString(digits);
  }
}

}  // namespace

}  // namespace test

}  // namespace sudoku