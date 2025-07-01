#pragma once

/**
 * - Height of a Node is the number of edges from the node to the deepest leaf
 * (ie. the longest path from the node to a leaf node).
 * - Depth of a Node is the number of edges from the root to the node.
 * - Height of a Tree is the height of the root node or the depth of the deepest node.
 * - Degree of a Node is the total number of branches of that node.
 *
 * A binary tree is a tree data structure in which each parent node can have at most two children.
 * A full Binary tree is a binary tree in which every parent node/internal node has either two or no children.
 * A perfect binary tree is a tree in which every internal node has exactly two child nodes and all the leaf nodes are at the same level.
 * A degenerate tree is the tree having a single child either left or right.
 * A skewed binary tree is a pathological/degenerate tree in which the tree is either dominated by the left nodes or the right nodes.
 * A balanced Binary Tree is a type tree in which the difference between the height of the left and the right subtree for each node is either 0 or 1.
 * A complete binary tree is a binary tree in which all the levels are completely filled except possibly the lowest one, which is filled from the left.
 * A binary search tree is a binary tree with all nodes of left subtree are less than the root node and all nodes of right subtree are more than the root node
 */

#include <iostream>

class TreeNode {
public:
  TreeNode(int i);

  int data;
  TreeNode* left;
  TreeNode* right;
};

TreeNode::TreeNode(int i) {
  data = i;
  left = NULL;
  right = NULL;
}

class BinaryTree {
public:
  static void preorder(TreeNode* root);
  static void inorder(TreeNode* root);
  static void postorder(TreeNode* root);

  static void mirror(TreeNode* root);
  static bool areIdentical(TreeNode* rootA, TreeNode* rootB);

  static bool isBalance(TreeNode* root, int& height);
};

class BinarySearchTree : public BinaryTree {
public:
  static TreeNode* insertNode(TreeNode* root, TreeNode* node);
  static TreeNode* deleteNode(TreeNode* root, TreeNode* node);
  static bool searchNode(TreeNode* root, TreeNode* node);

  // Node with a minimum value of key in the right subtree
  static TreeNode* inOrderSuccessor(TreeNode* node);
};

TreeNode* BinarySearchTree::inOrderSuccessor(TreeNode* node) {
  TreeNode* current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

void BinaryTree::preorder(TreeNode* root) {
  std::cout << root->data << ", ";
  if (root->left != NULL)
    preorder(root->left);
  if (root->right != NULL)
    preorder(root->right);
}

void BinaryTree::inorder(TreeNode* root) {
  if (root != NULL)
  {
    if (root->left != NULL)
      inorder(root->left);
    std::cout << root->data << ", ";
    if (root->right != NULL)
      inorder(root->right);
  }
}

void BinaryTree::postorder(TreeNode* root) {
  if (root->left != NULL)
    postorder(root->left);
  if (root->right != NULL)
    postorder(root->right);
  std::cout << root->data << ", ";
}

bool BinaryTree::isBalance(TreeNode* root, int& height) {

  if (root == NULL) {
    height = 0;
    return true;
  }

  int leftHeight = 0, rightHeight = 0;
  bool leftBalanced = isBalance(root->left, leftHeight);
  bool rightBalanced = isBalance(root->right, rightHeight);

  height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

  if( std::abs(leftHeight - rightHeight >= 2) )
    return 0;
  else
    return leftBalanced && rightBalanced;
}

TreeNode* BinarySearchTree::insertNode(TreeNode* root, TreeNode* node) {
  if (root == NULL)
    return node;

  if (root->data > node->data)
    root->left = insertNode(root->left, node);
  else if (root->data < node->data)
    root->right = insertNode(root->right, node);
  return root;
}

TreeNode* BinarySearchTree::deleteNode(TreeNode* root, TreeNode* node) {
  if (root == NULL)
    return root;
  
  if (root->data > node->data)
    root->left = deleteNode(root->left, node);
  else if (root->data < node->data)
    root->right = deleteNode(root->right, node);
  else {
    if (root->left == NULL && root->right == NULL)
    {
      delete root;
      root = NULL;
      return root;
    }
    else if (root->left == NULL)
    {
      TreeNode* nodeCopy = root->right;
      delete root;
      return nodeCopy;
    }
    else if (root->right == NULL)
    {
      TreeNode* nodeCopy = root->left;
      delete root;
      return nodeCopy;
    }
    
    TreeNode* newRoot = inOrderSuccessor(root->right);
    root->data = newRoot->data;
    root->right = deleteNode(root->right, newRoot);
    
  }
  return root;
}

bool BinarySearchTree::searchNode(TreeNode* root, TreeNode* node) {
  if (root == NULL)
    return false;
  else if (root->left == NULL && root->right == NULL)
    if (root->data != node->data)
      return false;
    else
      return true;

  else if (root->data > node->data)
    return searchNode(root->left, node);
  else if (root->data < node->data)
    return searchNode(root->right, node);
  else
    return true;
}

void BinaryTree::mirror(TreeNode* root) {
  if (root == NULL)
    return;
  if(root->left)
    mirror(root->left);
  if (root->right)
    mirror(root->right);

  TreeNode* tmp = root->left;
  root->left = root->right;
  root->right = tmp;
}

bool BinaryTree::areIdentical(TreeNode* rootA, TreeNode* rootB) {
  if (rootA == NULL && rootB == NULL)
    return true;
  
  if (rootA != NULL && rootB != NULL)
    if( (rootA->data == rootB->data) &&
      areIdentical(rootA->left, rootB->left) &&
      areIdentical(rootA->right, rootB->right))
    return true;

  return false;
}
