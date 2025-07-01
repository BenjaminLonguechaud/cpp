#pragma once

template <typename T>
class Node {
public:
  Node();
  Node(T);

  T data;
  Node* next;
};

template <typename T>
Node<T>::Node() {
  next = NULL;
}

template <typename T>
Node<T>::Node(T elem) {
  next = NULL;
  data = elem;
}

class LinkedList {
public:
  LinkedList();
  void insertNode(Node<char>* node);
  void deleteNode(int index);
  void sort();
  void print();

private:
  void mergeSort(Node<char>** head);
  Node<char>* merge(Node<char>* a, Node<char>* b);
  void split(Node<char>* head, Node<char>** a, Node<char>** b);

  Node<char>* head;
};

LinkedList::LinkedList() {
  head = NULL;
}

void LinkedList::insertNode(Node<char>* node) {
  if (head == NULL)
    head = node;
  else {
    Node<char>* pointer = head;
    while (pointer->next != NULL)
      pointer = pointer->next;
    pointer->next = node;
  }
}

void LinkedList::deleteNode(int index) {
  if (head == NULL)
    return;
  else {
    Node<char>* pointer = head;
    Node<char>* pointerPrevious = NULL;
    int i = 0;
    while (pointer->next != NULL && i < index - 1)
    {
      pointer = pointer->next;
      i++;
    }
    pointerPrevious = pointer;
    pointer = pointer->next;
    pointerPrevious->next = pointer->next;
    delete pointer;
  }
}

void LinkedList::print() {
  std::cout << "[ ";
  Node<char>* pointer = head;
  while (pointer != NULL )
  {
    std::cout << pointer->data << ", ";
    pointer = pointer->next;
  }
  std::cout << "NULL]" << std::endl;
}

void LinkedList::sort()
{
  mergeSort(&head);
}

void LinkedList::split(Node<char>* source, Node<char>** frontRef, Node<char>** backRef) {
  Node<char>* fast;
  Node<char>* slow;
  slow = source;
  fast = source->next;

  /* Advance 'fast' two nodes, and advance 'slow' one node */
  while (fast != NULL) {
    fast = fast->next;
    if (fast != NULL) {
      slow = slow->next;
      fast = fast->next;
    }
  }

  *frontRef = source;
  *backRef = slow->next;
  slow->next = NULL;
}

Node<char>* LinkedList::merge(Node<char>* a, Node<char>* b) {
  Node<char>* result = NULL;

  if (a == NULL)
    return b;
  else if (b == NULL)
    return a;

  if (a->data <= b->data) {
    result = a;
    result->next = merge(a->next, b);
  }
  else {
    result = b;
    result->next = merge(a, b->next);
  }
  return result;
}

void LinkedList::mergeSort(Node<char>** head) {
  if (*head == NULL || (*head)->next == NULL)
    return;

  Node<char> *a, *b;
  split(*head, &a, &b);

  mergeSort(&a);
  mergeSort(&b);

  *head = merge(a,b);
}