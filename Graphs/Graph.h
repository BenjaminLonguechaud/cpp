#pragma once

#include <iostream>
#include <list>
#include <stack>
#include <queue>

class Graph {
public:
  int _size;
  std::list<int>* adjacency;
  bool* visited;

  Graph(int size);
  void addEdge(int a, int b);
  void printGraph();
  void depthFirstSearch(int node);
  void breadthFirstSearch(int node);
  
  // Only for direct graph
  void findStronglyConnectedComponents();
  Graph* transpose();

  ~Graph();

private:
  void reset();
  std::stack<int> dfsStack;
};

Graph::Graph(int size) {
  _size = size;
  adjacency = new std::list<int>[size];
  visited = new bool[size];
  reset();
}

Graph::~Graph() {
  delete[] adjacency;
  delete[] visited;
}

void Graph::reset() {
  for (int i = 0; i < _size; i++) {
    visited[i] = false;
  }
}

void Graph::addEdge(int a, int b) {
  adjacency[a].push_back(b);
}

void Graph::printGraph() {
  for (int i = 0; i < _size; i++)
  {
    std::cout << i;
    for (int k : adjacency[i])
      std::cout << " -> " << k;
    std::cout << std::endl;
  }
}

void Graph::depthFirstSearch(int node) {
  if (!visited[node]) {
    std::cout << node << " ";
    visited[node] = true;
  }

  for (int k : adjacency[node])
    if(!visited[k])
      depthFirstSearch(k);
  dfsStack.push(node);
}

void Graph::breadthFirstSearch(int node) {
  reset();
  visited[node] = true;

  std::queue<int> queue;
  queue.push(node);
  std::cout << node << " ";

  while (!queue.empty())
  {
    int currentNode = queue.front();
    queue.pop();
    for (int k : adjacency[currentNode])
      if (!visited[k]) {
        visited[k] = true;
        queue.push(k);
        std::cout << k << " ";
      }
  }
}

Graph* Graph::transpose() {
  Graph* result = new Graph(_size);
  
  for (int i = 0; i < _size; i++)
    for (int k : adjacency[i])
      result->adjacency[k].push_back(i);
  return result;
}

void Graph::findStronglyConnectedComponents() {
  depthFirstSearch(0);

  for (int i = 0; i < _size; i++)
    visited[i] = false;

  Graph* transposedGraph = transpose();

  int graphCount = 0;
  while (!dfsStack.empty()) {
    graphCount++;
    int s = dfsStack.top();
    dfsStack.pop();
    if (!visited[s]) {
      std::cout << "SCC graph " << graphCount << ": ";
      transposedGraph->depthFirstSearch(s);
      std::cout << std::endl;
    }
  }
}
