#include <iostream>
#include <vector>
using namespace std;

// Graph represented using Adjacency List
class Graph {
public:
    vector<vector<int>> adjList; // Adjacency list to store graph edges
    int V; // Number of vertices in the graph

    // Constructor to initialize the graph with the number of vertices
    Graph(int V) {
        this->V = V; // Set the number of vertices
        adjList.resize(V); // Resize the adjacency list to hold V lists (one for each vertex)
    }

    // Function to add an edge between two vertices (u, v)
    void addEdge(int u, int v) {
        adjList[u].push_back(v); // Add v to the adjacency list of u
        adjList[v].push_back(u); // Add u to the adjacency list of v (for undirected graph)
    }

    // Function to print the graph representation
    void printGraph() {
        // Loop through each vertex and print its adjacency list
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": "; // Print the vertex
            // Loop through all adjacent vertices of vertex i and print them
            for (int j : adjList[i]) {
                cout << j << " "; // Print adjacent vertex j
            }
            cout << endl; // Move to the next line after printing adjacency list for vertex i
        }
    }
};

// Driver code to test the graph implementation
int main() {
    Graph g(5); // Create a graph with 5 vertices (0 to 4)

    // Add edges to the graph
    g.addEdge(0, 1); // Add edge between vertex 0 and vertex 1
    g.addEdge(0, 4); // Add edge between vertex 0 and vertex 4
    g.addEdge(1, 2); // Add edge between vertex 1 and vertex 2
    g.addEdge(1, 3); // Add edge between vertex 1 and vertex 3
    g.addEdge(3, 4); // Add edge between vertex 3 and vertex 4

    g.printGraph(); // Print the graph adjacency list representation

    return 0;
}
