#ifndef _36_VALIDSUDOKU_H_
#define _36_VALIDSUDOKU_H_

#include <vector>

class Solution {
 public:
  bool isValidSudoku(const std::vector<std::vector<char>> &board) {
    if (board.size() == 0) {
      return false;
    }

    bool valid = true;

    for (size_t rowIndex = 0; rowIndex < board.size(); ++rowIndex) {
      valid = valid && isRowValid(board, rowIndex);
    }

    for (size_t columnIndex = 0; columnIndex < board[0].size(); ++columnIndex) {
      valid = valid && isColumnValid(board, columnIndex);
    }

    for (size_t rowIndex = 0; rowIndex < board.size();
         rowIndex = rowIndex + 3) {
      for (size_t columnIndex = 0; columnIndex < board[0].size();
           columnIndex = columnIndex + 3) {
        valid = valid && isSubBoxValid(board, rowIndex, columnIndex);
      }
    }

    return valid;
  }

 private:
  bool isRowValid(const std::vector<std::vector<char>> &board,
                  const size_t row) {
    if (row >= board.size()) {
      return false;
    }

    std::vector<char> digitsToValidate(board.size());

    for (size_t columnIndex = 0; columnIndex < board[row].size();
         ++columnIndex) {
      digitsToValidate.push_back(board[row][columnIndex]);
    }

    return isDigitsValid(digitsToValidate);
  }

  bool isColumnValid(const std::vector<std::vector<char>> &board,
                     const size_t column) {
    std::vector<char> digitsToValidate(board.size());

    for (size_t rowIndex = 0; rowIndex < board.size(); ++rowIndex) {
      if (column >= board[rowIndex].size()) {
        return false;
      }

      digitsToValidate.push_back(board[rowIndex][column]);
    }

    return isDigitsValid(digitsToValidate);
  }

  bool isSubBoxValid(const std::vector<std::vector<char>> &board,
                     const size_t row, const size_t column) {
    std::vector<char> digitsToValidate(board.size());

    for (size_t rowIndex = row; rowIndex < row + 3; ++rowIndex) {
      if (rowIndex >= board.size()) {
        return false;
      }

      for (size_t columnIndex = column; columnIndex < columnIndex + 3;
           ++columnIndex) {
        if (columnIndex >= board[rowIndex].size()) {
          return false;
        }

        digitsToValidate.push_back(board[rowIndex][columnIndex]);
      }
    }

    return isDigitsValid(digitsToValidate);
  }

  bool isDigitsValid(const std::vector<char> digits) {
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

      return true;
    }
  }

 public:
  friend class SolutionTest;
};

#endif  // _36_VALIDSUDOKU_H_