
#include <iostream>
#include <vector>

int fiboRecursive(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else if (n > 1)
    return fiboRecursive(n - 1) + fiboRecursive(n-2);
}

int fiboDynamic(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else if (n > 1) {
    std::vector<int> table;
    table.push_back(0);
    table.push_back(1);
    for (int i = 2; i <= n; i++)
      table.push_back(table[i - 1] + table[i - 2]);
    return table[n];
  }
}

int fiboDynamic2(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else if (n > 1) {
    int a = 0;
    int b = 1;
    int c = 0;
    for (int i = 2; i <= n; i++) {
      c = a + b;
      a = b;
      b = c;
    }
    return c;
  }
}

int main() {

  std::cout << fiboRecursive(6) << std::endl;
  std::cout << fiboDynamic(6) << std::endl;
  std::cout << fiboDynamic2(6) << std::endl;
  return 0;
}