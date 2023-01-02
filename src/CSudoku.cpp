#include <algorithm>
#include <cstdlib>
#include <functional>
#include <numeric>
#include <vector>

const int divisor = 9;
const int divisor_square = 3;

int checkRowNumber(const int& index) {
  auto dv = std::div(index, divisor);
  return dv.quot+1;
}

int checkColumnNumber(const int& index) {
  auto dv = std::div(index, divisor);
  return dv.rem+1;
}

bool checkRowValues(const int& row, const std::vector<int>& sudoku) {
  std::vector<int> indexes {};
  int num = (row-1) * 9;
  indexes.resize(9);
  std::iota(indexes.begin(), indexes.end(), num);
  std::vector<int> vec {};
  for (auto i : indexes) {
    if (sudoku.at(i) == 0)
      continue;
    vec.push_back(sudoku.at(i));
  }
  //for (auto i : vec) { std::cout << i; }
  auto it = std::unique(vec.begin(), vec.end());
  return (it == vec.end());
}

bool checkColumnValues(const int& column, const std::vector<int>& sudoku) {
  std::vector<int> indexes {};
  int num = column-1;
  indexes.resize(9);
  for (auto i = 0; i < 9; i++) {
    indexes.push_back(num+i*9);
  }
  std::vector<int> vec {};
  for (auto i : indexes) {
    if (sudoku.at(i) == 0)
      continue;
    vec.push_back(sudoku.at(i));
  }
  //for (auto i : vec) { std::cout << i; }
  auto it = std::unique(vec.begin(), vec.end());
  return (it == vec.end());
}

int checkSquareNumber(const int& row, const int& column) {
  // 1 2 3
  // 4 5 6
  // 7 8 9
  auto dv_r = std::div(row, divisor_square);
  auto dv_c = std::div(column, divisor_square);

  if (dv_c.rem != 0) { dv_c.quot += 1; }
  if (dv_r.rem != 0) { dv_r.quot += 1; }

  if (dv_c.quot == dv_r.quot) {
    if (dv_c.quot == 1)
      return 1;
    else if (dv_c.quot == 2)
      return 5;
    else if (dv_c.quot == 3)
      return 9;
    else 
      return 0;
  }
  else if (dv_r.quot == 1 && dv_c.quot == 2) {
    return 2;
  }
  else if (dv_r.quot == 2 && dv_c.quot == 1) {
    return 4;
  }
  else if (dv_r.quot == 1 && dv_c.quot == 3) {
    return 3;
  }
  else if (dv_r.quot == 3 && dv_c.quot == 1) {
    return 7;
  }
  else if (dv_r.quot == 2 && dv_c.quot == 3) {
    return 6;
  }
  else if (dv_r.quot == 3 && dv_c.quot == 2) {
    return 8;
  }
  else
    return 0;
}