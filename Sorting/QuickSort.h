#pragma once

#include "Sort.h"

/**
 * Quick Sort algorithm is a Divide and Conquer algorithm.
 * It initially selects an element as a pivot element and partitions the given array around the picked pivot.
 */

class QuickSort : public Sort {
public:
  int partition(int anArray[], int low, int high) {

    int pivot = anArray[high];

    // pointer for greater element
    int k = low - 1;

    for (int i = low; i < high; i++)
    {
      if (anArray[i] <= pivot) {
        k++;
        swap(anArray, i, k);
      }
    }

    k++;
    swap(anArray, high, k);

    return k;
  }

  void sort(int* anArray, const int size) {
    quickSort(anArray, 0, size - 1);
  }

  void quickSort(int* anArray, int low, int high) {

    if (low < high)
    {
      int pivot = partition(anArray, low, high);

      // recursive call on the left of pivot
      quickSort(anArray, low, pivot - 1);

      // recursive call on the right of pivot
      quickSort(anArray, pivot + 1, high);
    }
  }

};
