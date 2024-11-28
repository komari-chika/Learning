// The effect of not adding noexcept to move members
#include "Array.h"
#include <string>
#include <vector>

// Construct an Array<> of a given size, filled with some arbitrary string data
Array<std::string> buildStringArray(const size_t size)
{
  Array<std::string> result{ size };
  for (size_t i = 0; i < size; ++i)
    result[i] = "You should learn from your competitor, but never copy. Copy and you die.";
  return result;
}

int main()
{
  Array<std::string> lvalue = buildStringArray(1'000);

  std::vector<Array<std::string>> v;
  v.push_back(lvalue);              // Push an lvalue
  v.push_back(std::move(lvalue));   // Push an rvalue
}