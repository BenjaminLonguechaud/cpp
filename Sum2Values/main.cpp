

#include<iostream>
#include<unordered_set>

bool findSumInArray(int* table, int size, int sum)  {
  std::unordered_set<int> hashTable;

  for (int i = 0; i < size; i++)
  {
    if (hashTable.find(sum - table[i]) != hashTable.end())
      return true;
    else
      hashTable.insert(table[i]);
  }
  return false;
}

int subArrayWithLargestSumLinear(int *anArray, int size)
{
  if (size < 1) {
    return 0;
  }

  int curr_max = anArray[0];
  int global_max = anArray[0];
  for (int i = 1; i < size; ++i) {
    if (curr_max < 0) {
      curr_max = anArray[i];
    }
    else {
      curr_max += anArray[i];
    }

    if (global_max < curr_max) {
      global_max = curr_max;
    }
  }

  return global_max;
}

std::vector<int> subArrayWithLargestSum(int *anArray, int size)
{
  std::vector<int> result;

  int maxSum = anArray[0];
  int subArrayLowIndex = 0;
  int subArrayUpperIndex = size - 1;

  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      int currentSum = anArray[0];
      for (int k = i; k < j; k++) {
        currentSum += anArray[k];
      }
      if (currentSum > maxSum)
      {
        maxSum = currentSum;
        subArrayLowIndex = i;
        subArrayUpperIndex = j;
      }
    }
  }

  for (int i = subArrayLowIndex; i < subArrayUpperIndex; i++)
    result.push_back(anArray[i]);

  return result;
}

int main() {
  int array1[] = { 1,2,7,4 };
  int sum1 = 9;

  int array2[] = { 1,2,7,4 };
  int sum2 = 1;

  //std::cout << "first test: " << testArray(array1, 3, sum1) << std::endl;
  //std::cout << "first test: " << testArray(array2, 3, sum2) << std::endl;

  // Largest sum
  int anArray[] = {-4, 2, -5, 1, 2, 3, 6, -5, 1};

  std::vector<int> result = subArrayWithLargestSum(anArray, 9);

  std::cout << "Array with largest sum: ";
  for (int number : result)
    std::cout << number << ", ";
  std::cout << std::endl;

  std::cout << "Largest sum: " << subArrayWithLargestSumLinear(anArray, 9);

  return 0;
}