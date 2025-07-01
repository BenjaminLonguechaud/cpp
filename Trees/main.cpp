

#include "BinaryTree.h"
#include "AVLTree.h"
#include "RedBlackTree.h"
#include "Heap.h"

void testBinaryTree() {
  TreeNode* balancedTree = new TreeNode(1);
  TreeNode* left1 = new TreeNode(12);
  TreeNode* right1 = new TreeNode(9);
  TreeNode* left20 = new TreeNode(5);
  TreeNode* right21 = new TreeNode(6);
  balancedTree->left = left1;
  balancedTree->right = right1;
  left1->left = left20;
  left1->right = right21;

  TreeNode* balancedTree2 = new TreeNode(1);
  TreeNode* left12 = new TreeNode(12);
  TreeNode* right12 = new TreeNode(9);
  TreeNode* left202 = new TreeNode(4);
  TreeNode* right212 = new TreeNode(6);
  balancedTree2->left = left12;
  balancedTree2->right = right12;
  left12->left = left202;
  left12->right = right212;

  std::cout << "Preorder: ";
  BinaryTree::preorder(balancedTree);
  std::cout << std::endl;
  std::cout << "Inorder: ";
  BinaryTree::inorder(balancedTree);
  std::cout << std::endl;
  std::cout << "Postorder: ";
  BinaryTree::postorder(balancedTree);
  std::cout << std::endl;
  int height = 0;
  std::cout << "Is balanced: " << BinaryTree::isBalance(balancedTree, height) << " and height is " << height << std::endl;

  std::cout << "Identical? " << BinaryTree::areIdentical(balancedTree, balancedTree2) << std::endl;

  TreeNode* unbalancedTree = new TreeNode(1);
  TreeNode* left30 = new TreeNode(2);
  unbalancedTree->left = left1;
  unbalancedTree->right = right1;
  left1->left = left20;
  left1->right = right21;
  right21->left = left30;
  int height2 = 0;
  std::cout << "Is balanced: " << BinaryTree::isBalance(unbalancedTree, height2) << " and height is " << height2 << std::endl;
}

void testBinarySearchTree() {
  TreeNode* binarySearchTree = new TreeNode(8);
  BinarySearchTree::insertNode(binarySearchTree, new TreeNode(3));
  BinarySearchTree::insertNode(binarySearchTree, new TreeNode(1));
  BinarySearchTree::insertNode(binarySearchTree, new TreeNode(6));
  BinarySearchTree::insertNode(binarySearchTree, new TreeNode(7));
  BinarySearchTree::insertNode(binarySearchTree, new TreeNode(10));
  BinarySearchTree::insertNode(binarySearchTree, new TreeNode(14));
  BinarySearchTree::insertNode(binarySearchTree, new TreeNode(4));

  std::cout << "Inorder traversal: ";
  BinarySearchTree::inorder(binarySearchTree);
  std::cout << "\nAfter deleting 10\n";
  BinarySearchTree::deleteNode(binarySearchTree, new TreeNode(10));
  std::cout << "Inorder traversal: ";
  BinarySearchTree::inorder(binarySearchTree);
  std::cout << std::endl << "Success" << std::endl;
  std::cout << "Search 6: " << BinarySearchTree::searchNode(binarySearchTree, new TreeNode(6)) << std::endl;
  std::cout << "Search 2: " << BinarySearchTree::searchNode(binarySearchTree, new TreeNode(2)) << std::endl;
}

void testHeap() {
  int anArray[] = { 3, 9, 2, 1, 4, 5 };
  for (int i = 0; i < 5; i++)
    std::cout << anArray[i] << ", ";
  std::cout << anArray[5] << std::endl;
  for (int j = 6 / 2 - 1; j >= 0; j--)
    Heap::heapify(anArray, 6, j);
  for (int i = 0; i < 5; i++)
    std::cout << anArray[i] << ", ";
  std::cout << anArray[5] << std::endl;

  int* newArray = Heap::insertNode(anArray, 6, 6);
  for (int i = 0; i < 6; i++)
    std::cout << newArray[i] << ", ";
  std::cout << newArray[6] << std::endl;

  newArray = Heap::deleteNode(anArray, 6, 1);
  for (int i = 0; i < 4; i++)
    std::cout << newArray[i] << ", ";
  std::cout << newArray[4] << std::endl;
}

int main(void)
{
  testBinaryTree();
  //testBinarySearchTree();
  //testHeap();

  return 1;
}