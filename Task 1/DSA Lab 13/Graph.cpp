#include "Graph.h"
#include <iostream>
#include <list>
#include <queue>
#include <stack>
using namespace std;

Graph::Graph(int numVertices) 
{
    this->numVertices = numVertices;
    adjacencyList = new list<int>[numVertices];
}

Graph::~Graph() 
{
    delete[] adjacencyList;
}

void Graph::addEdge(int vertex, int edge) 
{
    adjacencyList[vertex].push_back(edge);
}

void Graph::breadthFirstSearch(int startVertex) 
{
    bool* visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;
    queue<int> queue;
    visited[startVertex] = true;
    queue.push(startVertex);

    while (!queue.empty()) 
    {
        startVertex = queue.front();
        cout << startVertex << " ";
        queue.pop();

        for (auto adjacent : adjacencyList[startVertex]) 
        {
            if (!visited[adjacent]) 
            {
                visited[adjacent] = true;
                queue.push(adjacent);
            }
        }
    }
    delete[] visited;
}

void Graph::depthFirstSearchUtil(int vertex, bool visited[]) 
{
    visited[vertex] = true;
    cout << vertex << " ";
    for (auto adjacent : adjacencyList[vertex])
    {
        if (!visited[adjacent])
            depthFirstSearchUtil(adjacent, visited);
    }
}

void Graph::depthFirstSearch(int startVertex) 
{
    bool* visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;
    depthFirstSearchUtil(startVertex, visited);
    delete[] visited;
}