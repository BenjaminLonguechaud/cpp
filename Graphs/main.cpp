
#include "Graph.h"

void testGraphs() {
  Graph graph(8);
  graph.addEdge(0, 1);
  graph.addEdge(1, 2);
  graph.addEdge(2, 3);
  graph.addEdge(2, 4);
  graph.addEdge(3, 0);
  graph.addEdge(4, 5);
  graph.addEdge(5, 6);
  graph.addEdge(6, 4);
  graph.addEdge(6, 7);

  graph.printGraph();
  std::cout << "Depth first Search: ";
  graph.depthFirstSearch(0);
  std::cout << std::endl;
  std::cout << "Breadth first Search: ";
  graph.breadthFirstSearch(0);
  std::cout << std::endl;
  std::cout << "Strongly Connected Components: " << std::endl;
  graph.findStronglyConnectedComponents();
}

int main() {

  testGraphs();

  return 1;
}