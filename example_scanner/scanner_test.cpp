/*
 * A program for testing the generated scanner
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include "Scanner.h"

using namespace std;

int main()
{
  ifstream in{"fib.c"};
  Scanner scanner;
  auto res = scanner.scan(in);

  printf("%-20s%-20s\n", "SYNTACTIC CATEGORY", "LEXEME");
  for (auto x : res)
  {
    if (x.first != "whitespace")
    {
      printf("%-20s%-20s\n", x.first.c_str(), x.second.c_str());
    }
  }

  return 0;
}
