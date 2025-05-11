#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// Graph class to represent the graph using adjacency list
class Graph {
public:
    vector<vector<pair<int, int>>> adjList; // Adjacency list where each vertex points to a list of pairs (neighbor, weight)
    int V; // Number of vertices in the graph

    // Constructor to initialize the graph with V vertices
    Graph(int V) {
        this->V = V;
        adjList.resize(V); // Resize the adjacency list to have V empty lists
    }

    // Function to add an undirected edge between u and v with weight w
    void addEdge(int u, int v, int w) {
        adjList[u].push_back({v, w}); // Add edge u-v with weight w
        adjList[v].push_back({u, w}); // Add edge v-u (undirected graph)
    }

    // Dijkstra's algorithm to find the shortest path from the source node
    void dijkstra(int source) {
        vector<int> dist(V, INT_MAX); // Vector to store the shortest distance from source to each node
        dist[source] = 0; // Distance from the source to itself is 0
        
        // Priority queue (min-heap) to always process the node with the smallest distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source}); // Push the source node with distance 0

        while (!pq.empty()) {
            int u = pq.top().second; // Get the node with the smallest distance
            pq.pop(); // Remove it from the priority queue

            // Traverse all adjacent nodes (neighbors) of node u
            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first; // Neighbor node
                int weight = neighbor.second; // Weight of the edge u-v

                // If a shorter path to v is found, update the distance and push it to the priority queue
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight; // Update the distance
                    pq.push({dist[v], v}); // Push the updated distance and vertex to the priority queue
                }
            }
        }

        // Print the shortest distances from the source node to all other nodes
        cout << "Shortest distances from node " << source << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << ": " << dist[i] << endl;
        }
    }

    // Kruskal's algorithm for finding the Minimum Spanning Tree (MST)
    void kruskal() {
        vector<pair<int, pair<int, int>>> edges; // Vector to store all edges (u, v, weight)
        
        // Collect all edges from the adjacency list
        for (int u = 0; u < V; u++) {
            for (auto& neighbor : adjList[u]) {
                edges.push_back({neighbor.second, {u, neighbor.first}}); // Store edges as {weight, {u, v}}
            }
        }

        // Sort edges by their weight in non-decreasing order
        sort(edges.begin(), edges.end());

        vector<int> parent(V); // To store the parent of each vertex in the disjoint set
        vector<int> rank(V, 0); // To store the rank of each vertex (used for union by rank)

        // Initialize each vertex as its own parent (disjoint sets)
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        int mstWeight = 0; // Variable to store the total weight of the MST
        cout << "Edges in the Minimum Spanning Tree (Kruskal's):\n";

        // Traverse each edge and select it if it doesn't form a cycle
        for (auto& edge : edges) {
            int weight = edge.first; // Weight of the edge
            int u = edge.second.first; // One end of the edge
            int v = edge.second.second; // Other end of the edge

            // Find the root parent of u and v (using Union-Find)
            int root_u = find(parent, u);
            int root_v = find(parent, v);

            // If u and v have different parents, they belong to different sets (no cycle)
            if (root_u != root_v) {
                cout << u << " - " << v << " : " << weight << endl; // Include this edge in the MST
                mstWeight += weight; // Add its weight to the total MST weight
                unionSets(parent, rank, root_u, root_v); // Union the sets of u and v
            }
        }

        // Output the total weight of the MST
        cout << "Total weight of MST: " << mstWeight << endl;
    }

    // Prim's algorithm for finding the Minimum Spanning Tree (MST)
    void prim(int start) {
        vector<int> key(V, INT_MAX); // To store the minimum weight edge for each node
        vector<bool> mstSet(V, false); // To track if a node is included in the MST
        key[start] = 0; // Start from the given node with weight 0

        // Priority queue to store the vertex and its corresponding key (minimum edge weight)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start}); // Push the starting vertex with weight 0

        int mstWeight = 0; // Variable to store the total weight of the MST
        cout << "Edges in the Minimum Spanning Tree (Prim's):\n";

        // Process the graph to construct the MST
        while (!pq.empty()) {
            int u = pq.top().second; // Get the node with the minimum key value
            pq.pop();

            if (mstSet[u]) continue; // Skip if the node is already included in the MST
            mstSet[u] = true; // Mark the node as included in the MST
            mstWeight += key[u]; // Add the weight of the edge connecting u to the MST

            // Explore the neighbors of u and update the key values
            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first; // Neighbor node
                int weight = neighbor.second; // Weight of edge u-v

                // If the edge weight is smaller than the current key value, update it
                if (!mstSet[v] && weight < key[v]) {
                    key[v] = weight; // Update the key value
                    pq.push({key[v], v}); // Push the updated vertex to the priority queue
                }
            }
        }

        // Output the total weight of the MST
        cout << "Total weight of MST: " << mstWeight << endl;
    }

private:
    // Helper function to find the root of a node (used for Union-Find in Kruskal's)
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]); // Path compression
        }
        return parent[x];
    }

    // Helper function to union two sets (used in Kruskal's to avoid cycles)
    void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);

        // Union by rank: attach the tree with lesser rank to the one with higher rank
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    // Create a graph with 6 vertices
    Graph g(6);

    // Add edges to the graph (with weights)
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 5, 6);

    // Call Dijkstra's algorithm from vertex 0 to find the shortest paths
    g.dijkstra(0);

    // Call Kruskal's algorithm to find the Minimum Spanning Tree
    g.kruskal();

    // Call Prim's algorithm from vertex 0 to find the Minimum Spanning Tree
    g.prim(0);

    return 0;
}
