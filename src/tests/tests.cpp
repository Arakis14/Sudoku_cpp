#include <gtest/gtest.h>
#include "../CFileReader.cpp"
#include "../CSudoku.cpp"

std::vector<int> sudoku_correct_size = {
0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 7, 9, 0, 5, 0, 1, 8, 0,
8, 0, 0, 0, 0, 0, 0, 0, 7,
0, 0, 7, 3, 0, 6, 8, 0, 0,
4, 5, 0, 7, 0, 8, 0, 9, 6,
0, 0, 3, 5, 0, 2, 7, 0, 0,
7, 0, 0, 0, 0, 0, 0, 0, 5,
0, 1, 6, 0, 3, 0, 4, 2, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0
};

std::vector<int> sudoku_incorrect_size = {
0, 0, 0, 0, 0, 0, 0, 0,
0, 7, 9, 0, 5, 0, 1, 8,
8, 0, 0, 0, 0, 0, 0, 0,
0, 0, 7, 3, 0, 6, 8, 0,
4, 5, 0, 7, 0, 8, 0, 9,
0, 0, 3, 5, 0, 2, 7, 0,
7, 0, 0, 0, 0, 0, 0, 0,
0, 1, 6, 0, 3, 0, 4, 2,
0, 0, 0, 0, 0, 0, 0, 0
};

TEST(CFileReaderTest, CanReadFromFile) {
  std::filesystem::path path = "/home/wiktor/Documents/workspace/Sudoku_cpp/src/tests/example.txt";
  auto res = readFile(path);
  std::vector<int> v {1, 0, 1};
  EXPECT_EQ(res, v);
}

TEST(CFileReaderTest, CanReadFromFileFail) {
  std::filesystem::path path = "/home/wiktor/Documents/workspace/Sudoku_cpp/src/tests/example1.txt";
  EXPECT_THROW(readFile(path);, std::runtime_error);
}

TEST(CFileReaderTest, IsSizeCorrect) {
  auto res = checkSudokuSize(sudoku_correct_size);
  EXPECT_TRUE(res);
}

TEST(CFileReaderTest, IsSizeIncorrect) {
  auto res = checkSudokuSize(sudoku_incorrect_size);
  EXPECT_FALSE(res);
}

TEST(SudokuTest, checkRow) {
  int a = 21;
  auto res = checkRow(a);
  int expected = 2;
  EXPECT_EQ(res, expected);
}

TEST(SudokuTest, checkColumn) {
  int a = 60;
  auto res = checkColumn(a);
  int expected = 6;
  EXPECT_EQ(res, expected);
}