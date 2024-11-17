#ifndef LEETCODE_36_VALIDSUDOKU_SOLUTION_H_
#define LEETCODE_36_VALIDSUDOKU_SOLUTION_H_

#include <vector>

namespace sudoku {

class Solution {
 public:
  bool isValidSudoku(const std::vector<std::vector<char>> &board) const {
    if (board.size() == 0) {
      return false;
    }

    bool valid = true;

    for (size_t row_index = 0; row_index < board.size(); ++row_index) {
      valid = valid && IsRowValid(board, row_index);
    }

    for (size_t column_index = 0; column_index < board[0].size(); ++column_index) {
      valid = valid && IsColumnValid(board, column_index);
    }

    for (size_t row_index = 0; row_index < board.size(); row_index = row_index + 3) {
      for (size_t column_index = 0; column_index < board[0].size(); column_index = column_index + 3) {
        valid = valid && IsSubBoxValid(board, row_index, column_index);
      }
    }

    return valid;
  }

 private:
  bool IsRowValid(const std::vector<std::vector<char>> &board, const size_t row) const {
    if (row >= board.size()) {
      return false;
    }

    std::vector<char> digits_to_validate(board.size());

    for (size_t column_index = 0; column_index < board[row].size(); ++column_index) {
      digits_to_validate.push_back(board[row][column_index]);
    }

    return IsDigitsValid(digits_to_validate);
  }

  bool IsColumnValid(const std::vector<std::vector<char>> &board, const size_t column) const {
    std::vector<char> digits_to_validate(board.size());

    for (size_t row_index = 0; row_index < board.size(); ++row_index) {
      if (column >= board[row_index].size()) {
        return false;
      }

      digits_to_validate.push_back(board[row_index][column]);
    }

    return IsDigitsValid(digits_to_validate);
  }

  bool IsSubBoxValid(const std::vector<std::vector<char>> &board, const size_t row, const size_t column) const {
    std::vector<char> digits_to_validate(board.size());

    for (size_t row_index = row; row_index < row + 3; ++row_index) {
      if (row_index >= board.size()) {
        return false;
      }

      for (size_t column_index = column; column_index < column_index + 3; ++column_index) {
        if (column_index >= board[row_index].size()) {
          return false;
        }

        digits_to_validate.push_back(board[row_index][column_index]);
      }
    }

    return IsDigitsValid(digits_to_validate);
  }

  bool IsDigitsValid(const std::vector<char> digits) const {
    bool found1 = false;
    bool found2 = false;
    bool found3 = false;
    bool found4 = false;
    bool found5 = false;
    bool found6 = false;
    bool found7 = false;
    bool found8 = false;
    bool found9 = false;

    for (size_t index = 0; index < digits.size(); ++index) {
      switch (digits[index]) {
        case '1':
          if (found1) return false;
          found1 = true;
          break;
        case '2':
          if (found2) return false;
          found2 = true;
          break;
        case '3':
          if (found3) return false;
          found3 = true;
          break;
        case '4':
          if (found4) return false;
          found4 = true;
          break;
        case '5':
          if (found5) return false;
          found5 = true;
          break;
        case '6':
          if (found6) return false;
          found6 = true;
          break;
        case '7':
          if (found7) return false;
          found7 = true;
          break;
        case '8':
          if (found8) return false;
          found8 = true;
          break;
        case '9':
          if (found9) return false;
          found9 = true;
          break;
      }
    }

    return true;
  }

#ifdef UNIT_TESTING
 public:
  bool Test_IsRowValid(const std::vector<std::vector<char>> &board, const size_t row) const {
    return IsRowValid(board, row);
  }

  bool Test_IsColumnValid(const std::vector<std::vector<char>> &board, const size_t column) {
    return IsColumnValid(board, column);
  }

  bool Test_IsSubBoxValid(const std::vector<std::vector<char>> &board, const size_t row, const size_t column) {
    return IsSubBoxValid(board, row, column);
  }

  bool Test_IsDigitsValid(const std::vector<char> digits) { return IsDigitsValid(digits); }

#endif  // #ifdef UNIT_TESTING
};

}  // namespace sudoku

#endif  // LEETCODE_36_VALIDSUDOKU_SOLUTION_H_