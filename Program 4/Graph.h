#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

struct edge {
    int weight;
    string to;
};

struct vertex {
    int indegree;
    bool found;
};

class Graph {

    private:
        // weigthed and directed adjancency list
        vector<edge>* graph;
        // vertex dictionary
        map<string, int> indexMap;
        // index dictionary
        vector<string> vertMap;
        // indegree array
        vector<vertex> indegree;
        // number of vertices
        int vertices;

    public:
        // Equals operator overloader
        Graph operator=(const Graph &g);
        // Takes a input graph .tx file to read
        void readGraph(ifstream& in, ostream& out);
        // Prints the topological order of graph
        void topologicalSort(ostream& out);
        // Prints the shortest path from any given node
        void shortestPath(ostream& out, string node);
        // Prints the minimum spanning tree
        void minSpanTree(ostream& out);
          
};

#endif