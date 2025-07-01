#pragma once

#include "Sort.h"

class BubbleSort : public Sort{
public:
  void sort(int* anArray, const int size)
  {
    bool isSorted = true;
    do {
      isSorted = true;
      for (int i = 0; i < size - 1; i++) {
        if (anArray[i] > anArray[i + 1]) {
          isSorted = false;
          swap(anArray, i, i + 1);
        }
      }
    } while (!isSorted);
  }

};
