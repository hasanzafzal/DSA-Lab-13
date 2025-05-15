#include "dijkstra.h"
#include <iostream>
using namespace std;

Graph::Graph(int V) 
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int w) 
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::dijkstra(int src) 
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INT_MAX);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty()) 
    {
        int u = pq.top().second;
        pq.pop();
        for (auto x : adj[u]) 
        {
            int v = x.first;
            int weight = x.second;
            if (dist[v] > dist[u] + weight) 
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < V; ++i)
    {
        cout << i << "\t\t" << dist[i] << "\n";
    }
}