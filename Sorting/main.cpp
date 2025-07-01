#include <iostream>
#include <vector>
#include <string>

#include "BubbleSort.h"
#include "QuickSort.h"
#include "MergeSort.h"

const int ARRAY_SIZE = 10;

int binarySearch(int* anArray, int k, int low, int high) {

  if (high >= low)
  {
    int mid = (high + low) / 2;
    if (anArray[mid] == k)
      return mid;
    else if (anArray[mid] > k)
      return binarySearch(anArray, k, low, mid-1);
    else
      return binarySearch(anArray, k, mid+1, high);
  }
  return -1;
}

void displayArray(int* anArray)
{
  for (int i = 0; i < ARRAY_SIZE; i++)
    std::cout << anArray[i] << " ";
  std::cout << std::endl;
}

int main(void)
{
  int sortedArray[] = { 1,3,4,6,3,9 };
  std::cout << "Index of 3 is: " << binarySearch(sortedArray, 3, 0, sizeof(sortedArray) / sizeof(int) - 1) << std::endl;

  int myArray[ARRAY_SIZE];
  for (int i = 0; i < ARRAY_SIZE; i++)
    myArray[i] = rand() % ARRAY_SIZE + 1;

  std::cout << "Input: ";
  displayArray(myArray);

  MergeSort* mergeSort = new MergeSort;

  mergeSort->sort(myArray, ARRAY_SIZE);

  std::cout << "Output: ";
  displayArray(myArray);

  std::cout << "Verification: ";
  if (mergeSort->verify(myArray, ARRAY_SIZE))
    std::cout << "Success !" << std::endl;
  else
    std::cout << "Failed !" << std::endl;

  return 0;
}
