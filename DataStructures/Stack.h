#pragma once

template <typename T>
class Stack {
public:

  Stack(int size);

  void push(T);
  T pop();
  bool isEmpty();
  bool isFull();
  T peek();
  void print();

private:
  T* m_stack;
  int m_top;
  int m_size;
};

template <typename T>
Stack<T>::Stack(int size) {
  m_stack = new T[size];
  m_top = -1;
  m_size = size;
}

template <typename T>
void Stack<T>::push(T elem) {
  if (!isFull())
  {
    m_top++;
    m_stack[m_top] = elem;
  }
}

template <typename T>
T Stack<T>::pop() {
  if (!isEmpty())
  {
    T elem = peek();
    m_top--;
    return elem;
  }
  else
  {
    std::cout << "Stack empty" << std::endl;
    return NULL;
  }
}

template <typename T>
T Stack<T>::peek() {
  if (!isEmpty())
  {
    T elem = m_stack[m_top];
    return elem;
  }
  else
  {
    std::cout << "Stack empty" << std::endl;
    return NULL;
  }
}

template <typename T>
bool Stack<T>::isEmpty() {
  return m_top == -1;
}

template <typename T>
bool Stack<T>::isFull() {
  bool result = false;
  if (m_top == m_size - 1)
  {
    std::cout << "Stack full" << std::endl;
    result = true;
  }
  return result;
}

template <typename T>
void Stack<T>::print() {
  if (!isEmpty()) {
    std::cout << "[ ";
    for (int i = 0; i < m_top; i++) {
      std::cout << m_stack[i] << ", ";
    }
    std::cout << m_stack[m_top] << "]" << std::endl;
  }
}
