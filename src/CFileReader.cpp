#include <stdexcept>
#include <fstream>
#include <iterator>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

std::vector<int> readFile(fs::path &input)
{
  std::vector<int> v = {};
  if(!fs::exists(input))
    throw std::runtime_error("File does not exist.");
  std::ifstream file(input);
  if (file) {
      std::copy(std::istream_iterator<int> (file),
        std::istream_iterator<int>(),
        std::back_inserter(v));
  }
  return v;
}