#ifndef GRAPHAPP_HPP
#define GRAPHAPP_HPP
#include "Graph.hpp"
#include <iostream>
using namespace std;

namespace Demo {
    class GraphApp {
    public:
        static void run() {
            cout << "\n=== Graph Demo ===" << endl;
            // Directed Graph
            Graph g1(6, true); 
            
            cout << "Creating a directed graph with 6 vertices" << endl;
            g1.addEdge(0, 1);
            g1.addEdge(0, 2);
            g1.addEdge(1, 3);
            g1.addEdge(1, 4);
            g1.addEdge(2, 4);
            g1.addEdge(3, 5);
            g1.addEdge(4, 5);
            
            cout << "Edges added: (0->1), (0->2), (1->3), (1->4), (2->4), (3->5), (4->5)" << endl;
            cout << endl;
            g1.print();
            cout << endl;
            cout << "Number of vertices: " << g1.getNumVertices() << endl;
            cout << "Number of edges: " << g1.getNumEdges() << endl;    
            if (g1.isEmpty()) {
                cout << "Graph is empty" << endl;
            } else {
                cout << "Graph is not empty" << endl;
            }
            cout << endl;
            g1.bfs(0);
            g1.dfs(0);
            
            // Undirected Graph
            Graph g2(5, false);  
            cout << "Creating an undirected graph with 5 vertices" << endl;
            g2.addEdge(0, 1);
            g2.addEdge(0, 2);
            g2.addEdge(1, 3);
            g2.addEdge(2, 4);
            
            cout << "Edges added: (0-1), (0-2), (1-3), (2-4)" << endl;
            cout << endl;
            g2.print();
            cout << endl;
            g2.bfs(0);
            g2.dfs(0);
            
            // Disconnected Graph
            Graph g3(7, true); 
            
            cout << "Creating a disconnected directed graph with 7 vertices" << endl;
            g3.addEdge(0, 1);
            g3.addEdge(1, 2);
            g3.addEdge(3, 4);
            g3.addEdge(5, 6);
            
            cout << "Edges added: (0->1), (1->2), (3->4), (5->6)" << endl;
            cout << endl;
            g3.print();
            cout << endl;

            cout << "Down here we are doing bfs and dfs from vertex 0, then for all components using -1 and then from all components using no argument" << endl;
            g3.bfs(0);
            g3.dfs(0);
            cout << endl;
            g3.bfs(-1);
            g3.dfs(-1);
            cout << endl;
            g3.bfs();
            g3.dfs();
            
            cout << "\n=== Graph Demo Complete ===" << endl;
        }
    };
}

#endif
