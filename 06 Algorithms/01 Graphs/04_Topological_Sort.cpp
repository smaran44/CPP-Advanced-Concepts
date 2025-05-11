#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Graph class to represent the graph using adjacency list
class Graph {
public:
    int V; // Number of vertices in the graph
    vector<vector<int>> adjList; // Adjacency list where each vertex has a list of adjacent vertices

    // Constructor to initialize the graph with V vertices
    Graph(int V) {
        this->V = V;
        adjList.resize(V); // Resize the adjacency list to have V empty lists
    }

    // Function to add a directed edge from u to v
    void addEdge(int u, int v) {
        adjList[u].push_back(v); // Add vertex v to the adjacency list of vertex u
    }

    // Helper function to perform DFS for Topological Sort
    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true; // Mark the current node as visited

        // Recur for all the vertices adjacent to this vertex
        for (int i = 0; i < adjList[v].size(); i++) {
            int adjacent = adjList[v][i];
            if (!visited[adjacent]) { // If the adjacent vertex is not visited, recursively visit it
                topologicalSortUtil(adjacent, visited, Stack);
            }
        }

        // Push the current vertex to the stack which will store the result in topological order
        Stack.push(v);
    }

    // Function to perform the Topological Sort
    void topologicalSort() {
        stack<int> Stack; // Stack to store the result of the topological sort
        vector<bool> visited(V, false); // Vector to track visited vertices

        // Call the helper function for each vertex to perform DFS if the vertex is not visited
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, Stack); // DFS traversal from unvisited vertex
            }
        }

        // Print the topological order by popping vertices from the stack
        cout << "Topological Sort: ";
        while (!Stack.empty()) {
            cout << Stack.top() << " "; // Print the top of the stack (the next vertex in the order)
            Stack.pop(); // Pop the top vertex from the stack
        }
        cout << endl;
    }
};

int main() {
    Graph g(6); // Create a graph with 6 vertices

    // Add directed edges to the graph
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    // Perform the topological sort and print the result
    cout << "Topological Sort of the given graph: ";
    g.topologicalSort();

    return 0;
}
