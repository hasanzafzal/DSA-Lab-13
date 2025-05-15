#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class Graph 
{
private:
    int numVertices;
    list<int>* adjacencyList;
    void depthFirstSearchUtil(int vertex, bool visited[]);
public:
    Graph(int numVertices);
    ~Graph();
    void addEdge(int vertex, int edge);
    void breadthFirstSearch(int startVertex);
    void depthFirstSearch(int startVertex);
};

#endif 