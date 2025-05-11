#include <iostream>
#include <vector>
using namespace std;

// UnionFind class to represent the Union-Find (Disjoint Set) data structure
class UnionFind {
private:
    vector<int> parent, rank; // Vectors to store parent pointers and rank of trees

public:
    // Constructor to initialize the UnionFind data structure for n elements
    UnionFind(int n) {
        parent.resize(n); // Resize the parent vector to hold 'n' elements
        rank.resize(n, 0); // Resize the rank vector to hold 'n' elements, initially 0

        // Initially, each element is its own parent (disjoint sets)
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Each element is its own parent, forming n disjoint sets
        }
    }

    // Find function with path compression
    int find(int x) {
        // Base case: if x is its own parent, return x
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression: make the tree flatter
        }
        return parent[x]; // Return the root of the set containing x
    }

    // Union function with union by rank
    void unionSets(int x, int y) {
        int rootX = find(x); // Find the root of the set containing x
        int rootY = find(y); // Find the root of the set containing y

        // If x and y are in different sets, we merge them
        if (rootX != rootY) {
            // Union by rank: attach the smaller tree under the larger tree
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX; // Attach rootY tree under rootX tree
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY; // Attach rootX tree under rootY tree
            } else {
                parent[rootY] = rootX; // Arbitrary choice when both have same rank
                rank[rootX]++; // Increase the rank of rootX since its tree became taller
            }
        }
    }

    // Function to check if two elements are in the same set (connected)
    bool isConnected(int x, int y) {
        return find(x) == find(y); // If the roots of x and y are the same, they are connected
    }
};

int main() {
    UnionFind uf(5); // Create a UnionFind object for 5 elements

    // Perform union operations to connect some elements
    uf.unionSets(0, 1); // Union 0 and 1
    uf.unionSets(1, 2); // Union 1 and 2
    uf.unionSets(3, 4); // Union 3 and 4

    // Check if two elements are in the same set (connected)
    cout << "Are 0 and 2 connected? " << (uf.isConnected(0, 2) ? "Yes" : "No") << endl;
    cout << "Are 0 and 3 connected? " << (uf.isConnected(0, 3) ? "Yes" : "No") << endl;

    // Perform another union operation to connect 2 and 3
    uf.unionSets(2, 3);

    // Check connectivity after another union
    cout << "Are 0 and 3 connected now? " << (uf.isConnected(0, 3) ? "Yes" : "No") << endl;

    return 0;
}
