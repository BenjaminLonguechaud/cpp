#pragma once

#include <iostream>
#include <vector>
#include <string>

class Sort {
public:
  bool verify(int* anArray, const int size) {
    bool result = true;
    for (int i = 0; i < size - 1; i++)
    {
      if (anArray[i] > anArray[i + 1])
        result = false;
    }
    return result;
  }

  virtual void sort(int* anArray, const int size) = 0;

protected:
  void swap(int* anArray, int i, int j)
  {
    if (i != j) {
      int tmp = anArray[i];
      anArray[i] = anArray[j];
      anArray[j] = tmp;
    }
  }

};
