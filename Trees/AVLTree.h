#pragma once

#include "BinaryTree.h"

/**
 * An AVL tree is a self-balancing binary search tree in which each node maintains extra
 * information called a balance factor whose value is either -1, 0 or +1.
 * 
 * Balance Factor = |Height of Left Subtree - Height of Right Subtree|
 * The self balancing property of an AVL tree is maintained by the balance factor.
 * The value of balance factor should always be -1, 0 or +1.
 *
 * More efficient for search  
 */

class AVLTreeNode {
public:
  AVLTreeNode(int i);

  int data;
  AVLTreeNode* left;
  AVLTreeNode* right;
  int height;
};

AVLTreeNode::AVLTreeNode(int i) {
  data = i;
  left = NULL;
  right = NULL;
  height = 0;
}

class AVLTree : public BinaryTree {
public:
  static int getBalanceFactor(AVLTreeNode* node);

  static AVLTreeNode* leftRotate(AVLTreeNode* node);
  static AVLTreeNode* rightRotate(AVLTreeNode* node);

  static AVLTreeNode* insertNode(AVLTreeNode* root, AVLTreeNode* node);
  static AVLTreeNode* deleteNode(AVLTreeNode* root, AVLTreeNode* node);

  // Node with a minimum value of key in the right subtree
  static AVLTreeNode* inOrderSuccessor(AVLTreeNode* node);
};

int AVLTree::getBalanceFactor(AVLTreeNode* node) {
  if (node == NULL)
    return 0;
  else if (node->left = NULL)
    return -node->right->height;
  else if (node->right = NULL)
    return node->left->height;
  else
    return node->left->height - node->right->height;
}

AVLTreeNode* AVLTree::inOrderSuccessor(AVLTreeNode* node) {
  AVLTreeNode* current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

AVLTreeNode* AVLTree::leftRotate(AVLTreeNode* X) {
  if (X == NULL || X->right == NULL)
    return X;

  AVLTreeNode* Y = X->right;
  if (Y->left != NULL)
  {
    AVLTreeNode* Z = Y->left;
    Y->left = X;
    X->right = Z;
    return Y;
  }
  else
    return X;
}

AVLTreeNode* AVLTree::rightRotate(AVLTreeNode* X) {
  if (X == NULL || X->left == NULL)
    return X;

  AVLTreeNode* Y = X->left;
  if (Y->left != NULL)
  {
    AVLTreeNode* Z = Y->right;
    Y->right = X;
    X->left = Z;
    return Y;
  }
  else
    return X;
}

AVLTreeNode* AVLTree::insertNode(AVLTreeNode* root, AVLTreeNode* node) {
  // Find the correct position and insert the node
  if (root == NULL)
    return node;
  else if (root->data > node->data)
    root->left = insertNode(node->left, node);
  else if (root->data < node->data)
    root->right = insertNode(node->right, node);
  else
    return root;

  // Update the balance factor of each node and balance the tree
  if (root->left->height > root->right->height)
    root->height = root->left->height + 1;
  else
    root->height = root->right->height + 1;

  int b = getBalanceFactor(root);
  // If balanceFactor > 1:
  // If newNodeKey < leftChildKey do right rotation.
  // Else, do left-right rotation.
  if (b > 1) {
    if (node->data < root->left->data)
      return rightRotate(root);
    else {
      node->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  // If balanceFactor < -1:
  // If newNodeKey > leftChildKey do left rotation.
  // Else, do right-left rotation.
  if (b < -1) {
    if (node->data > root->right->data)
      return leftRotate(root);
    else {
      node->right = rightRotate(root->left);
      return leftRotate(root);
    }
  }
  return root;
}

AVLTreeNode* AVLTree::deleteNode(AVLTreeNode* root, AVLTreeNode* node) {
  int key = node->data;

  if (root == NULL)
    return root;
  if (key < root->data)
    root->left = deleteNode(root->left, node);
  else if (key > root->data)
    root->right = deleteNode(root->right, node);
  else {
    AVLTreeNode* tmp;
    if (root->left == NULL && root->right == NULL)
    {
      delete root;
      return NULL;
    }
    else if (root->left == NULL || root->right == NULL)
    {
      AVLTreeNode* tmp = root->left ? root->left : root->right;
      root->data = tmp->data;
      delete tmp;
    }
    else {
      AVLTreeNode* tmp = inOrderSuccessor(root->right);
      root->data = tmp->data;
      root->right = deleteNode(root->right, tmp);
    }
  }

  int b = getBalanceFactor(root);
  if (b > 1) {
    if (getBalanceFactor(root->left) >= 0)
      return rightRotate(root);
    else {
      node->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  // If balanceFactor < -1:
  // If newNodeKey > leftChildKey do left rotation.
  // Else, do right-left rotation.
  if (b < -1) {
    if (getBalanceFactor(root->right) <= 0)
      return leftRotate(root);
    else {
      node->right = rightRotate(root->left);
      return leftRotate(root);
    }
  }
  return root;
}
