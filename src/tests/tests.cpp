#include <gtest/gtest.h>
#include "../CFileReader.cpp"

TEST(SudokuTest, CanReadFromFile) {
  std::filesystem::path path = "/home/wiktor/Documents/workspace/Sudoku_cpp/src/tests/example.txt";
  auto res = readFile(path);
  std::vector<int> v {1, 0, 1};
  EXPECT_EQ(res, v);
}

TEST(SudokuTest, CanReadFromFileFail) {
  std::filesystem::path path = "/home/wiktor/Documents/workspace/Sudoku_cpp/src/tests/example1.txt";
  EXPECT_THROW(readFile(path);, std::runtime_error);
}