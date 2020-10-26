#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include <utility>

using namespace std;


class Graph{
    vector< list <pair<int, int> > > vertices;
    public:
    Graph(int);
    std::pair<int,int> minEdge(int vertex, vector<bool> visited);
    void addEdge(int,int,int);
    void addVertex();
    void displayGraph();
    list<pair<int,int> >  adjacentVertices(int);
    void particularDegree(int);
    bool path(int, int);
    void sumOfDegrees();
    void dfs(int vertex);
    void bfs(int vertex);
    void minSpanningTree();
    void shortestPath();
};