#pragma once

template <typename T>
class Queue {
public:

  Queue(int size);

  void enqueue(T elem);
  T dequeue();
  bool isEmpty();
  bool isFull();

  void print();

private:
  T* m_stack;
  int m_front;
  int m_back;
  int m_size;
};

template <typename T>
Queue<T>::Queue(int size) {
  m_stack = new T[size];
  m_back = -1;
  m_front = 0;
  m_size = size;
}

template <typename T>
void Queue<T>::enqueue(T elem) {
  if (!isFull())
  {
    m_back = (m_back + 1) % m_size;
    m_stack[m_back] = elem;
  }
}

template <typename T>
T Queue<T>::dequeue() {
  if (!isEmpty())
  {
    T elem = m_stack[m_front];
    if(m_front != m_back)
      m_front = (m_front + 1) % m_size;
    else {
      m_front = 0;
      m_back = -1;
    }
    return elem;
  }
  else
  {
    std::cout << "Queue empty" << std::endl;
    return NULL;
  }
}

template <typename T>
bool Queue<T>::isEmpty() {
  return m_back == -1;
}

template <typename T>
bool Queue<T>::isFull() {
  bool result = false;
  if ( (m_back - m_front == m_size - 1 )
    || (m_back > -1 && (m_back - m_front == -1)) )
  {
    std::cout << "Queue full" << std::endl;
    result = true;
  }
  return result;
}

template <typename T>
void Queue<T>::print() {
  if (!isEmpty()) {
    if (m_back > m_front) {
      std::cout << "[ ";
      for (int i = m_front; i < m_back - m_front; i++) {
        std::cout << m_stack[i] << ", ";
      }
      std::cout << m_stack[m_back - m_front] << "]" << std::endl;
    }
    else {
      std::cout << "[ ";
      for (int i = m_front; i < m_size; i++) {
        std::cout << m_stack[i] << ", ";
      }
      for (int i = 0; i < m_front - 1; i++) {
        std::cout << m_stack[i] << ", ";
      }
      std::cout << m_stack[m_front - 1] << "]" << std::endl;
    }
  }
}
