#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {
public:
    vector<vector<int>> adjList; // Adjacency list to represent the graph
    int V; // Number of vertices in the graph

    // Constructor to initialize the graph with the number of vertices
    Graph(int V) {
        this->V = V; // Set the number of vertices
        adjList.resize(V); // Resize the adjacency list to hold V lists (one for each vertex)
    }

    // Function to add an edge between two vertices u and v (undirected graph)
    void addEdge(int u, int v) {
        adjList[u].push_back(v); // Add v to the adjacency list of u
        adjList[v].push_back(u); // Add u to the adjacency list of v (for undirected graph)
    }

    // BFS (Breadth-First Search) Traversal starting from a given node
    void BFS(int start) {
        vector<bool> visited(V, false); // Vector to keep track of visited nodes
        queue<int> q; // Queue to implement BFS

        visited[start] = true; // Mark the starting node as visited
        q.push(start); // Push the starting node into the queue

        // BFS traversal
        while (!q.empty()) {
            int node = q.front(); // Get the front element from the queue
            q.pop(); // Remove the front element from the queue
            cout << node << " "; // Print the node

            // Visit all adjacent nodes (neighbors) of the current node
            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) { // If the neighbor has not been visited
                    visited[neighbor] = true; // Mark the neighbor as visited
                    q.push(neighbor); // Push the neighbor into the queue
                }
            }
        }
        cout << endl; // End of BFS traversal
    }

    // DFS (Depth-First Search) Traversal using recursion
    void DFS(int start) {
        vector<bool> visited(V, false); // Vector to keep track of visited nodes
        DFSUtil(start, visited); // Call the helper function for DFS
        cout << endl; // End of DFS traversal
    }

    // Helper function for recursive DFS
    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true; // Mark the node as visited
        cout << node << " "; // Print the node

        // Recursively visit all adjacent nodes (neighbors) of the current node
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) { // If the neighbor has not been visited
                DFSUtil(neighbor, visited); // Recursively call DFS for the neighbor
            }
        }
    }
};

// Driver code
int main() {
    Graph g(5); // Create a graph with 5 vertices (0 to 4)

    // Add edges to the graph
    g.addEdge(0, 1); // Add edge between vertex 0 and vertex 1
    g.addEdge(0, 4); // Add edge between vertex 0 and vertex 4
    g.addEdge(1, 2); // Add edge between vertex 1 and vertex 2
    g.addEdge(1, 3); // Add edge between vertex 1 and vertex 3
    g.addEdge(3, 4); // Add edge between vertex 3 and vertex 4

    // Perform BFS starting from vertex 0
    cout << "BFS starting from node 0: ";
    g.BFS(0); // Output the BFS traversal order

    // Perform DFS starting from vertex 0
    cout << "DFS starting from node 0: ";
    g.DFS(0); // Output the DFS traversal order

    return 0;
}
