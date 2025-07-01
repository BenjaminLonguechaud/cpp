#include <iostream>
#include <exception> 
#include <stdexcept>

#include "Stack.h"

using namespace std;

void testStack() {
  std::cout << "Stack" << std::endl;
  try {
    Stack stack(3);
    stack.push(3);
    stack.push(1);
    stack.pop();
    stack.pop();
    stack.pop();
  }
  catch (stack_bad_alloc ba) {
    std::cout << "stack_bad_alloc: " << ba.what() << std::endl;
  }
  catch (stack_size_error se) {
    std::cout << "stack_size_error" << std::endl;
  }
  catch (stack_empty ba) {
    std::cout << "stack_empty: " << ba.what() << std::endl;
  }
  catch (stack_overflow ba) {
    std::cout << "stack_overflow" << std::endl;
  }
}

class myException : public exception {
  char const*  what() const { return "myException"; }
};

class myLogicError : public logic_error {
public:
  explicit myLogicError(const string& _Message) : logic_error(_Message) {};
};

void throwingStringException(bool test) throw(string){
  if (test)
    throw string("Throwing a string");
  else
    std::cout << "throwingStringException excecuted normally" << std::endl;
}

void throwingException(int i) {
  switch (i) {
  case 0: throw out_of_range("0");
  case 1: throw overflow_error("1");
  case 2: throw domain_error("2");
  case 3: throw exception();
  case 4: throw myLogicError("myLogicError with explicit constructor");
  case 5: throw myException();
  }
}

int main(void) {
  for (int i = 0; i < 6; i++) {
    try {
      throwingException(i);
    }
    catch (logic_error &ex) {
      cout << "Exception caught: " << ex.what() << endl;
    }
    catch (...) {
      cout << "Catching all exception " << endl;
    }
  }
  try {
    throwingStringException(true);
  }
  catch (...)
  {
    cout << "Something went wrong" << endl;
  }

  testStack();

  return 0;
}
