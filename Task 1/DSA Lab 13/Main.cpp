#include "Graph.h"
#include <iostream>
using namespace std;

int main()
{
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);
    cout << "Breadth First Traversal (starting from vertex 2): ";
    graph.breadthFirstSearch(2);
    cout << "\nDepth First Traversal (starting from vertex 2): ";
    graph.depthFirstSearch(2);

    return 0;
}