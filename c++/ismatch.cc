#include <iostream>
#include "ismatch.h"

int main()
{
  Solution sol;
  const char s[] = "ab";
  const char p[] = ".*";
  std::cout << sol.isMatch(s, p) << std::endl;
}
