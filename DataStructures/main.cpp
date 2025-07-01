
/**
  * Any Hash Table implementation has the following three components:
  * - A good Hash function to map keys to values
  * - A Hash Table Data Structure that supports insert, search and delete operations.
  * - A Data Structure to account for collision of keys 
  */

#include <stdio.h>
#include <iostream>
#include <string>
#include <list>

#include "HashTable.h"
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"

void testLinkedLists() {
  std::cout << "Linked List" << std::endl;
  LinkedList linkedList;
  linkedList.insertNode(new Node<char>('A'));
  linkedList.insertNode(new Node<char>('E'));
  linkedList.insertNode(new Node<char>('S'));
  linkedList.print();
  linkedList.deleteNode(1);
  linkedList.print();
  linkedList.insertNode(new Node<char>('D'));
  linkedList.insertNode(new Node<char>('C'));
  linkedList.print();
  linkedList.sort();
  linkedList.print();
  std::cout << std::endl;
}

void testStack() {
  std::cout << "Stack" << std::endl;
  Stack<char> stack(3);
  stack.push('A');
  stack.push('B');
  stack.push('C');
  stack.print();
  stack.pop();
  stack.push('D');
  stack.print();
  stack.push('E');
  stack.print();
  std::cout << std::endl;
}

void testQueue() {
  std::cout << "Queue" << std::endl;
  Queue<char> queue(3);
  queue.enqueue('A');
  queue.enqueue('B');
  queue.enqueue('C');
  queue.print();
  queue.dequeue();
  queue.enqueue('D');
  queue.print();
  queue.enqueue('E');
  queue.print();
  std::cout << std::endl;
}

void testHashTables() {
  std::cout << "HashTable" << std::endl;
  HashItem Benjamin = { "Benjamin", "35" };
  HashItem Amanda = { "Amanda", "33" };

  HashTable table(10);
  table.add_item(Benjamin);
  table.add_item(Amanda);

  table.displayHash();

  if (table.delete_item("Benjamin"))
    std::cout << "Item deleted" << std::endl;

  table.displayHash();
  std::cout << std::endl;
}



int main(void)
{
  //testHashTables();
  //testStack();
  //testQueue();
  testLinkedLists();

  return 1;
}