
#include <iostream>
#include <vector>
#include <stack>

void printArray(std::vector<int> anArray) {
  for (int elem : anArray)
    std::cout << elem << " ";
  std::cout << std::endl;
}

std::vector<int> moveZeros2(int* anArray, int size) {
  std::vector<int> result;
  result.resize(size+1);
  int indexOfZeros = 0;
  int indexOfNonZeros = size;

  for (int i = size; i >= 0; i--)
    if (anArray[i] == 0) {
      result[indexOfZeros] = 0;
      indexOfZeros++;
    }
    else {
      result[indexOfNonZeros] = anArray[i];
      indexOfNonZeros--;
    }
  return result;
}

std::vector<int> moveZeros(int* anArray, int size) {
  int numberOfZeros = 0;
  std::stack<int> stackOfNonZeros;

  for (int i = size; i >= 0; i--)
    if (anArray[i] == 0)
      numberOfZeros++;
    else
      stackOfNonZeros.push(anArray[i]);

  std::vector<int> result;
  for (int i = 0; i < numberOfZeros; i++)
    result.push_back(0);
  while (!stackOfNonZeros.empty())
  {
    result.push_back(stackOfNonZeros.top());
    stackOfNonZeros.pop();
  }
  return result;
}

int main() {

  int testArray1[] = { 0,1,5,2,0,5,0,8,0 };
  int testArray2[] = { 0,1 };
  int testArray3[] = { 1,0 };
  int testArray4[] = { 1,2 };

  std::cout << "Test Array 1: "; printArray(moveZeros(testArray1, 8));
  std::cout << "Test Array 1: "; printArray(moveZeros(testArray2, 1));
  std::cout << "Test Array 1: "; printArray(moveZeros(testArray3, 1));
  std::cout << "Test Array 1: "; printArray(moveZeros(testArray4, 1));

  std::cout << "Test Array 1: "; printArray(moveZeros2(testArray1, 8));
  std::cout << "Test Array 1: "; printArray(moveZeros2(testArray2, 1));
  std::cout << "Test Array 1: "; printArray(moveZeros2(testArray3, 1));
  std::cout << "Test Array 1: "; printArray(moveZeros2(testArray4, 1));

  return 0;
}
