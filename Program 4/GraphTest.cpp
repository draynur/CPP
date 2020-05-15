/**
 * Name: John Runyard
 * IT 279
 * Program 4 - Working with Graphs
 * 
 * This is implementation of my graph class. It provides a simple menu for users to input graph .txt files and do
 * operations on them.
 */

#include "Graph.h"

int main () {
    string s;
    int a;
    bool  choice = true;

    cout << "Choose which file to read: ";
    cin >> s;
    ifstream in(s);
    Graph g;

    g.readGraph(in, cout);
    in.close();
    
    cout << endl;
        
    while (choice) {
        cout << "Choose function: " << endl
             << "1: Topological Sort" << endl 
             << "2: Find shortest path(s) from node" << endl 
             << "3: Calculate minimum spanning tree" << endl 
             << "4: Load new graph" << endl 
             << "5: Exit" << endl << "Choice: ";
        cin >> a;
        switch (a) {
            case 1:
                g.topologicalSort(cout);
                break;
            case 2:
                cout << "Choose node to start from : ";
                cin >> s;
                g.shortestPath(cout, s);
                break;
            case 3:
                g.minSpanTree(cout);
                break;
            case 4: {
                cout << "Choose which file to read: ";
                cin >> s;
                ifstream newIn(s);
                Graph h;
                h.readGraph(newIn, cout);
                newIn.close();
                g = h;
                break;
            }
            case 5:
                choice = false;
        }
        cout << endl;
    }

    cout << "Done" << endl;
}