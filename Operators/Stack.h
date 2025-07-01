#ifndef __MYSTACK__
#define __MYSTACK__

#include <iostream>
#include <exception> 

#pragma warning( disable : 4290 )

class Stack {
public:

  Stack(int size);

  void push(int);
  int pop();
  bool isEmpty();
  bool isFull();
  int peek();
  void print();
  Stack& operator << (int);
  Stack& operator >> (int&);

private:
  int* m_stack;
  int m_top;
  int m_size;
};

Stack::Stack(int size){
  m_stack = new int[size];
  m_top = -1;
  m_size = size;
}

Stack& Stack::operator<<(int elem) {
  push(elem);
  return *this;
}

Stack& Stack::operator>>(int& elem) {
  elem = pop();
  return *this;
}

void Stack::push(int elem){
  if (!isFull())
  {
    m_top++;
    m_stack[m_top] = elem;
  }
}

int Stack::pop(){
  if (isEmpty())
  {
    throw std::logic_error("Stack empty");
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
