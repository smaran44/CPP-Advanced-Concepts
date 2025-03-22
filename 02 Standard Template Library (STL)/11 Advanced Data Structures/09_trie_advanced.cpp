#include <iostream>
#include <vector>

using namespace std;

class Trie {
private:
    // Define a Trie Node structure
    struct Node {
        bool isWord = false;       // Marks if this node is the end of a word
        Node* children[26] = {};   // Array of pointers for each lowercase English letter (a-z)
    };

    Node* root; // Root of the Trie

public:
    // Constructor initializes the root node
    Trie() {
        root = new Node();
    }

    /*
     * insert(word)
     * ------------
     * - Inserts a word into the Trie.
     * - Traverses character by character.
     * - Creates a new node if a character doesn't exist.
     * - Marks the last node as `isWord = true` to indicate the word's end.
     */
    void insert(string word) {
        Node* node = root;  // Start from the root node
        for (char ch : word) {
            int index = ch - 'a';  // Convert character to index (0-25)
            if (!node->children[index]) {
                node->children[index] = new Node();  // Create a new node if not present
            }
            node = node->children[index];  // Move to the next node
        }
        node->isWord = true;  // Mark the last node as the end of a word
    }

    /*
     * searchHelper(node, prefix, results)
     * ------------------------------------
     * - A recursive helper function to collect all words that start with a given prefix.
     * - If `node->isWord == true`, the prefix itself is a valid word.
     * - Recursively explores all children and adds valid words to `results`.
     */
    void searchHelper(Node* node, string prefix, vector<string>& results) {
        if (!node) return;  // If node is NULL, return

        if (node->isWord) results.push_back(prefix);  // If current node is a word, add to results

        // Iterate over all possible children (a-z)
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int index = ch - 'a';
            if (node->children[index]) {
                // Recursively explore this path and append the character to the prefix
                searchHelper(node->children[index], prefix + ch, results);
            }
        }
    }

    /*
     * searchPrefix(prefix)
     * --------------------
     * - Searches for all words in the Trie that start with a given prefix.
     * - Calls the recursive helper function to collect results.
     */
    vector<string> searchPrefix(string prefix) {
        vector<string> results;
        Node* node = root;
    
        // Traverse the Trie to find the node corresponding to the prefix
        for (char ch : prefix) {
            int index = ch - 'a';
            if (!node->children[index]) return results; // Prefix not found
            node = node->children[index];
        }
    
        // Use searchHelper to collect all words that start with the prefix
        searchHelper(node, prefix, results);
        return results;
    }
    
};
