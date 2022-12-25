#include <cstdlib>
#include <vector>

const int divisor = 9;

int checkRow(const int& index) {
  auto dv = std::div(index, divisor);
  return dv.quot;
}

int checkColumn(const int& index) {
  auto dv = std::div(index, divisor);
  return dv.rem;
}