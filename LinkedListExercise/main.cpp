
#include <iostream>
#include <unordered_map>

class Node {
public:
  Node();
  Node(int data);

  int data;
  Node* next;
  Node* extraPointer;
};

Node::Node() {
  next = NULL;
  extraPointer = NULL;
}

Node::Node(int elem) {
  next = NULL;
  extraPointer = NULL;
  data = elem;
}

class LinkedList {
public:
  LinkedList();
  Node* head;
  void addNode(Node* node);
  void addPointer(int a, int b);
};

LinkedList::LinkedList() {
  head = NULL;
}

void LinkedList::addNode(Node* node) {
  if (head == NULL) {
    head = node;
  }
  else {
    Node* pointer = head;
    while (pointer->next != NULL)
      pointer = pointer->next;
    pointer->next = node;
  }
}

void LinkedList::addPointer(int a, int b) {
  Node* pointer = head;
  int i = 0;
  Node* from = NULL, *to = NULL;
  while (pointer != NULL)
  {
    if (i == a)
      from = pointer;
    else if (i == b)
      to = pointer;
    pointer = pointer->next;
    i++;
  }
  from->extraPointer = to;
}

LinkedList* deepCopy(LinkedList* originalList) {
  LinkedList* copiedList = new LinkedList();

  std::unordered_map<Node*, Node*> map;

  if (originalList->head == NULL)
    return NULL;
  else
  {
    copiedList->head = new Node(originalList->head->data);
    map[originalList->head] = copiedList->head;
  }

  // copy original list
  Node* pointer = originalList->head;
  Node* copiedPointer = copiedList->head;
  while (pointer != NULL)
  {
    Node* copyNode = new Node(pointer->data);
    copiedPointer->next = pointer->next;
    map[pointer] = copyNode;
    pointer = pointer->next;
    copiedPointer = copiedPointer->next;
  }

  pointer = originalList->head;
  copiedPointer = copiedList->head;
  while (pointer != NULL)
  {
    if (pointer->extraPointer != NULL)
      copiedPointer->extraPointer = map[pointer->extraPointer];
    pointer = pointer->next;
    copiedPointer = copiedPointer->next;
  }
  return copiedList;
}

void print_with_arb_pointers(Node* head) {
  while (head != nullptr) {
    std::cout << head->data << " (";
    if (head->extraPointer)
      std::cout << head->extraPointer->data;
    std::cout << "), ";
    head = head->next;
  }
  std::cout << std::endl;
}

int main() {
  LinkedList* list = new LinkedList;
  list->addNode(new Node(1));
  list->addNode(new Node(2));
  list->addNode(new Node(3));
  list->addPointer(0,2);
  print_with_arb_pointers(list->head);

  LinkedList* copiedList = deepCopy(list);  
  print_with_arb_pointers(copiedList->head);

  return 0;
}