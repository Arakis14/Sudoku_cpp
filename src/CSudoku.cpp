#include <algorithm>
#include <cstdlib>
#include <functional>
#include <numeric>
#include <vector>

const int divisor = 9;

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
  for (auto i : vec) { std::cout << i; }
  auto it = std::unique(vec.begin(), vec.end());
  return (it == vec.end());
}