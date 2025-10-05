#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include "Node.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
using namespace std;

class Graph {
private:
    struct EdgeNode {
        int vertex;
        EdgeNode* next;
        
        EdgeNode(int v) {
            vertex = v;
            next = nullptr;
        }
    };
    
    int numVertices;
    int numEdges;
    bool isDirected;
    EdgeNode** adjList;  // Array of adjacency lists ie it is array of pointers to head of the Linked list
    
    void dfsHelper(int vertex, bool* visited);
    
public:
    Graph(int vertices, bool directed = true);
    ~Graph();
    void addEdge(int u, int v);
    void bfs(int startVertex = -1);  // -1 means traverse all components
    void dfs(int startVertex = -1);  // -1 means traverse all components
    void print();
    int getNumVertices();
    int getNumEdges();
    bool isEmpty();
};

// Constructor & Destructor
Graph::Graph(int vertices, bool directed) {
    numVertices = vertices;
    numEdges = 0;
    isDirected = directed;
    adjList = new EdgeNode*[numVertices];
    for (int i = 0; i < numVertices; i++) {
        adjList[i] = nullptr;
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; i++) {
        EdgeNode* current = adjList[i];
        while (current != nullptr) {
            EdgeNode* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] adjList;
}



void Graph::addEdge(int u, int v) {
    if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
        // Add edge from u to v
        EdgeNode* newNode = new EdgeNode(v);
        newNode->next = adjList[u];
        adjList[u] = newNode; // This pointing to the new head of the list ie the newly added edge
        
        // If undirected, add edge from v to u as well
        if (!isDirected) {
            EdgeNode* newNode2 = new EdgeNode(u);
            newNode2->next = adjList[v];
            adjList[v] = newNode2;
        }
        
        numEdges++;
    } else {
        cerr << "Error: Invalid vertex index" << endl;
    }
}

// Breadth First Search using Queue
void Graph::bfs(int startVertex) {
    bool* visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }
    
    // If startVertex is -1, traverse all components
    if (startVertex == -1) {
        cout << "BFS (all components): ";
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                Queue<int> q;
                visited[i] = true;
                q.enqueue(i);
                
                while (!q.isEmpty()) {
                    int current;
                    q.dequeue(current);
                    cout << current << " ";
                    
                    EdgeNode* temp = adjList[current];
                    while (temp != nullptr) {
                        int adjVertex = temp->vertex;
                        if (!visited[adjVertex]) {
                            visited[adjVertex] = true;
                            q.enqueue(adjVertex);
                        }
                        temp = temp->next;
                    }
                }
            }
        }
    } else {
        // Traverse from specific start vertex
        if (startVertex < 0 || startVertex >= numVertices) {
            cerr << "Error: Invalid start vertex" << endl;
            delete[] visited;
            return;
        }
        
        Queue<int> q;
        visited[startVertex] = true;
        q.enqueue(startVertex);
        
        cout << "BFS starting from vertex " << startVertex << ": ";
        
        while (!q.isEmpty()) {
            int current;
            q.dequeue(current);
            cout << current << " ";
            
            EdgeNode* temp = adjList[current];
            while (temp != nullptr) {
                int adjVertex = temp->vertex;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    q.enqueue(adjVertex);
                }
                temp = temp->next;
            }
        }
    }
    cout << endl;
    
    delete[] visited;
}

// Helper function for DFS
void Graph::dfsHelper(int vertex, bool* visited) {
    visited[vertex] = true;
    cout << vertex << " ";
    
    EdgeNode* temp = adjList[vertex];
    while (temp != nullptr) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            dfsHelper(adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Depth First Search using Stack 
void Graph::dfs(int startVertex) {
    bool* visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }
    
    // If startVertex is -1, traverse all components 
    if (startVertex == -1) {
        cout << "DFS (all components): ";
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                dfsHelper(i, visited);
            }
        }
    } else {
        // Traverse from specific start vertex using stack 
        if (startVertex < 0 || startVertex >= numVertices) {
            cerr << "Error: Invalid start vertex" << endl;
            delete[] visited;
            return;
        }
        
        Stack<int> s;
        s.push(startVertex);
        
        cout << "DFS starting from vertex " << startVertex << ": ";
        
        while (!s.isEmpty()) {
            int current;
            s.pop(current);
            
            if (!visited[current]) {
                visited[current] = true;
                cout << current << " ";
                
                // All adjacent vertices into stack in reverse order to maintain order
                Stack<int> tempStack;
                EdgeNode* temp = adjList[current];
                while (temp != nullptr) {
                    if (!visited[temp->vertex]) {
                        tempStack.push(temp->vertex);
                    }
                    temp = temp->next;
                }
                
                // From tempStack to main stack in reverses order
                while (!tempStack.isEmpty()) {
                    int v;
                    tempStack.pop(v);
                    s.push(v);
                }
            }
        }
    }
    cout << endl;
    
    delete[] visited;
}

void Graph::print() {
    cout << "Graph Adjacency List is " << (isDirected ? "Directed" : "Undirected") << ":" << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << i << " : ";
        EdgeNode* temp = adjList[i];
        while (temp != nullptr) {
            cout << temp->vertex << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int Graph::getNumVertices() {
    return numVertices;
}
int Graph::getNumEdges() {
    return numEdges;
}
bool Graph::isEmpty() {
    return (numEdges == 0) ? true : false;
}

#endif
