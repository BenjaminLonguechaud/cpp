#pragma once

#include "BinaryTree.h"

/**
 * Red-Black tree is a self-balancing binary search tree in which each node contains an extra bit for
 * denoting the color of the node, either red or black.
 * - root and leaves are black
 * - If parent is red, children are black
 * - For each node, any path to any of its descendant leaf has the same number of black nodes
 * The limitations put on the node colors ensure that any simple path from the root to a leaf
 * is not more than twice as long as any other such path. It helps in maintaining the
 * self-balancing property of the red-black tree.
 *
 * More efficient for frequent insertions and deletions
 */

class RedBlackTreeNode : public TreeNode {
public:
  int data;
  RedBlackTreeNode* left;
  RedBlackTreeNode* right;
  RedBlackTreeNode* parent;
  bool color;

  RedBlackTreeNode(int i);
};

RedBlackTreeNode::RedBlackTreeNode(int i) : TreeNode(i) {
  data = i;
  left = NULL;
  right = NULL;
  color = 0;
  parent = NULL;
}

class RedBlackTree : public AVLTree
{
public:
  static RedBlackTreeNode* leftRotate(RedBlackTreeNode* node);
  /*static RedBlackTreeNode* rightRotate(RedBlackTreeNode* node);

  static RedBlackTreeNode* insertNode(RedBlackTreeNode* root, RedBlackTreeNode* node);
  static RedBlackTreeNode* deleteNode(RedBlackTreeNode* root, RedBlackTreeNode* node);*/
};

RedBlackTreeNode* RedBlackTree::leftRotate(RedBlackTreeNode* X) {
  if (X == NULL || X->right == NULL)
    return X;

  RedBlackTreeNode* Y = X->right;
  if (Y->left != NULL)
  {
    RedBlackTreeNode* Z = Y->left;
    Y->left = X;
    Y->parent = X->parent;
    if (X == X->parent->left) {
      X->parent->left = Y;
    }
    else {
      X->parent->right = Y;
    }
    X->right = Z;
    Z->parent = X;
    X->parent = Y;
    return Y;
  }
  else
    return X;
}

//RedBlackTreeNode* RedBlackTree::rightRotate(RedBlackTreeNode* node) {
//
//}
//
//RedBlackTreeNode* RedBlackTree::insertNode(RedBlackTreeNode* root, RedBlackTreeNode* node) {
//
//}
//
//RedBlackTreeNode* RedBlackTree::deleteNode(RedBlackTreeNode* root, RedBlackTreeNode* node) {
//
//}
