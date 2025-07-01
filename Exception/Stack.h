#ifndef __MYSTACK__
#define __MYSTACK__

#include <iostream>
#include <exception> 

#pragma warning( disable : 4290 )

class stack_size_error : public std::length_error {
public:
  explicit stack_size_error(const std::string &msg) : length_error(msg) {};
};
class stack_bad_alloc : public std::bad_alloc {
public:
  explicit stack_bad_alloc(void) : bad_alloc() {};
};
class stack_overflow : public std::logic_error {
public:
  explicit stack_overflow(const std::string &msg) : logic_error(msg) {};
};
class stack_empty : public std::logic_error {
public:
  explicit stack_empty(const std::string &msg) : logic_error(msg) {};
};


class Stack {
public:

  Stack(int size) throw(stack_bad_alloc, stack_size_error);

  void push(int) throw(stack_overflow);
  int pop() throw(stack_empty);
  bool isEmpty();
  bool isFull();
  int peek();
  void print();

private:
  int* m_stack;
  int m_top;
  int m_size;
};

Stack::Stack(int size) throw(stack_bad_alloc, stack_size_error) {
  if (size <= 0)
    throw stack_size_error("Size <= 0");
  try {
    m_stack = new int[size];
  }
  catch(std::bad_alloc ba) {
    throw stack_bad_alloc();
  }
  m_top = -1;
  m_size = size;
}

void Stack::push(int elem) throw(stack_overflow) {

  if (isFull())
  {
    throw stack_overflow("Stack is full");
  }
  m_top++;
  m_stack[m_top] = elem;
}

int Stack::pop() throw(stack_empty) {
  if (isEmpty())
  {
    throw stack_empty("Stack is empty");
  }
  int elem = peek();
  m_top--;
  return elem;
}

int Stack::peek() {
  if (!isEmpty())
  {
    int elem = m_stack[m_top];
    return elem;
  }
  else
  {
    std::cout << "Stack empty" << std::endl;
    return NULL;
  }
}

bool Stack::isEmpty() {
  return m_top == -1;
}

bool Stack::isFull() {
  bool result = false;
  if (m_top == m_size - 1)
  {
    std::cout << "Stack full" << std::endl;
    result = true;
  }
  return result;
}

void Stack::print() {
  if (!isEmpty()) {
    std::cout << "[ ";
    for (int i = 0; i < m_top; i++) {
      std::cout << m_stack[i] << ", ";
    }
    std::cout << m_stack[m_top] << "]" << std::endl;
  }
}

#endif
