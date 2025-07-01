#pragma once

#include "BinaryTree.h"

/**
 * Heap data structure is a complete binary tree that satisfies the heap property, where any given node is
 * - always greater than its child node/s and the key of the root node is
 * the largest among all other nodes. This property is also called max heap property.
 * - always smaller than the child node/s and the key of the root node is
 * the smallest among all other nodes. This property is also called min heap property.
 * Implements Priority Queue
 */
class Heap : public BinaryTree {
public:
  static void heapify(int* anArray, int size, int index);
  static int* insertNode(int* anArray, int size, int node);
  static int* deleteNode(int* anArray, int size, int node);

  static void swap(int* anArray, int i, int j)
  {
    if (i != j) {
      int tmp = anArray[i];
      anArray[i] = anArray[j];
      anArray[j] = tmp;
    }
  }
};


void Heap::heapify(int* anArray, int size, int index) {
  int largest = index;
  int leftIndex = 2 * index + 1;
  int rightIndex = 2 * index + 2;

  if (leftIndex < size && anArray[leftIndex] > anArray[largest])
    largest = leftIndex;
  else if (rightIndex < size && anArray[rightIndex] > anArray[largest])
    largest = rightIndex;

  if (largest != index)
  {
    swap(anArray, index, largest);
    heapify(anArray, size, largest);
  }
}

int* Heap::insertNode(int* anArray, int size, int node) {
  int* newArr = new int[size + 1];
  for (int i = 0; i < sizeof(anArray); i++)
    newArr[i] = anArray[i];

  newArr[size] = node;
  for (int j = 0; j < size + 1; j++)
    heapify(newArr, size + 1, j);
  return newArr;
}

int* Heap::deleteNode(int* anArray, int size, int node) {
  swap(anArray, node, size - 1);

  int* newArr = new int[size - 1];
  for (int i = 0; i < size - 1; i++)
    newArr[i] = anArray[i];

  for (int j = 0; j < size - 1; j++)
    heapify(newArr, size - 1, j);
  return newArr;
}

