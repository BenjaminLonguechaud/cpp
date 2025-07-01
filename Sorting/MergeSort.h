#pragma once

#include "Sort.h"

class MergeSort : public Sort {
public:
  void sort(int* anArray, const int size)
  {
    mergeSort(anArray, 0, size - 1);
  }

  void merge(int *anArray, const int i, const int middle, const int j) {

    const int arrayOneSize = middle - i + 1;
    const int arrayTwoSize = j - middle;

    int* arrayOne = new int[arrayOneSize];
    int* arrayTwo = new int[arrayTwoSize];

    for (int k = 0; k < arrayOneSize; k++)
      arrayOne[k] = anArray[i + k];
    for (int k = 0; k < arrayTwoSize; k++)
      arrayTwo[k] = anArray[middle + 1 + k];

    int u = 0, v = 0;
    int index = i;
    while (u != arrayOneSize && v != arrayTwoSize) {
      if (arrayOne[u] <= arrayTwo[v]) {
        anArray[index] = arrayOne[u];
        u++;
      }
      else {
        anArray[index] = arrayTwo[v];
        v++;
      }
      index++;
    }

    while (v != arrayTwoSize){
      anArray[index] = arrayTwo[v];
      index++;
      v++;
    }
    
    while (u != arrayOneSize) {
      anArray[index] = arrayOne[u];
      index++;
      u++;
    }

    delete arrayOne;
    delete arrayTwo;
  }

  void mergeSort(int* anArray, int i, int j) {
    if (i < j) {
      int middle = (i + j) / 2;
      mergeSort(anArray, i, middle);
      mergeSort(anArray, middle + 1, j);
      merge(anArray, i, middle, j);
    }
  }

};
