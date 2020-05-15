/**
 * Name: John Runyard
 * IT 279
 * Program 4 - Working with Graphs
 * 
 * This was my attempt at implementing several functions for a directed weighted graph. I wasn't able to finish all the functions on time
 * and plan on redoing this one.
 * 
 */

#include "Graph.h"

Graph Graph::operator=(const Graph &g) {
    this->vertices = g.vertices;
    this->graph = new vector<edge>[this->vertices];
    for (int i = 0; i < this->vertices; i++) {
        this->graph[i] = g.graph[i];
    }
    this->indexMap = g.indexMap;
    this->vertMap = g.vertMap;
    this->indegree = g.indegree;
    return *this;
}

void Graph::readGraph(ifstream& in, ostream& out) {
    string temp, dest;
    int i, j, w;

    in >> i;

    this->vertices = i;
    this->graph = new vector<edge>[i];

    for (j = 0; j < i; j++) {
        in >> temp;
        this->indexMap.insert(pair<string, int>(temp,j));
        this->vertMap.push_back(temp);
        this->indegree.push_back({0, false});
    }

    in >> i;

    for (j = 0; j < i; j++) {
        
        in >> temp; in >> dest; in >> w;

        this->graph[this->indexMap[temp]].push_back({w,dest});
        this->indegree[this->indexMap[dest]].indegree++;
    }

}

void Graph::topologicalSort(ostream& out) {

    vector<vertex> ind = this->indegree;

    queue<int> vertices;

    for (int i = 0; i < this->indegree.size(); i++) {
        if (!ind[i].indegree) {
            vertices.push(i);
            ind[i].found = true;
        }
    }
    
    if (vertices.empty()) 
        out << "Topological sort not possible: directed cycle detected.";

    while (!vertices.empty()) {
        int v = vertices.front();

        for (edge ed: this->graph[v]) {
            int a = this->indexMap[ed.to];
            ind[a].indegree--;

            if (!ind[a].indegree && !ind[a].found) {
                vertices.push(a);
                ind[a].found=true;
            }
        }

        out << this->vertMap[v] << " ";
        vertices.pop();
    }
    out << endl;
}

struct node {
    string to;
    string from;
    int weight = INT_MAX;
    bool found = false;

    bool operator<(const node& rhs) const {
        return weight < rhs.weight;
    }
};


void Graph::shortestPath(ostream& out, string key) {

    vector<node> sorted (this->vertices);

    priority_queue<node> q;

    vector<vertex> ind = this->indegree;

    int i = 0, graphIndex = this->indexMap[key];

    for (edge e: this->graph[graphIndex])
        q.push({e.to, key, e.weight, true});

    while (!q.empty() && i < this->vertices) {

        node current = q.top();
        q.pop();

        graphIndex = this->indexMap[current.to];

        if (sorted[graphIndex].found) {

            if (sorted[graphIndex].weight > current.weight) {
                
                sorted[graphIndex].to = current.from;
                sorted[graphIndex].from = current.from;
                sorted[graphIndex].weight = current.weight;
                sorted[graphIndex].found = true;

            }

        } else {
            sorted[graphIndex].to = current.from;
            sorted[graphIndex].from = current.to;
            sorted[graphIndex].weight = current.weight;
            sorted[graphIndex].found = true;
            i++;
        }

        for (edge e: this->graph[graphIndex]) {

            q.push({e.to, current.to, e.weight+current.weight});

        }

    }

    for (i = 0; i < sorted.size(); i++) 
        if (sorted[i].weight < INT_MAX - 30000)
            cout << this->vertMap[i] << " " << sorted[i].weight << endl;
    


}

void Graph::minSpanTree(ostream& out) {
    /**
     * Still wasn't able to succesffuly implement this method, but I think i got the topSort and shortestpath down!
     * Also this program looks a little more like a program now.
     */
}