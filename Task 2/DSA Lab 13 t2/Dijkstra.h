#pragma once
#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> iPair;

class Graph 
{
private:
    int V;
    vector<vector<iPair>> adj;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void dijkstra(int src);
};

#endif