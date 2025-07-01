
#include "Stack.h"

enum weekday { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };

weekday operator+ (weekday day, int i) {
  return weekday((int(day) + i) % 7);
}

Stack& operator > (Stack& stack, int& elem) {
  elem = stack.peek();
  return stack;
}

void testStack() {
  int i, j, k;

  Stack stack(3);
  stack << 3 << 1;
  stack > k;
  stack >> i >> j;
  std::cout << "First element: " << k << std::endl;
  std::cout << "Stack: " << i << j << std::endl;

}

int main(void) {

  testStack();

  weekday day = weekday::SATURDAY;
  day = weekday(day + 1);
  std::cout << day << std::endl;

  return 0;
}