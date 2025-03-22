#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * Trie Operations - Insert & Search
 * ---------------------------------
 * - `insert(word)`: Adds a word to the Trie.
 * - `search(word)`: Checks if a word exists in the Trie.
 *
 * - Each character of the word moves **down the tree**.
 * - The last node is marked as `isEndOfWord = true` to indicate the word's presence.
 */

// Class representing a Trie Node
class TrieNode {
public:
    unordered_map<char, TrieNode*> children; // Maps each character to its corresponding TrieNode
    bool isEndOfWord;  // Marks if this node represents the end of a word

    // Constructor initializes a TrieNode
    TrieNode() {
        isEndOfWord = false;
    }
};

// Class representing the Trie
class Trie {
private:
    TrieNode* root;  // Root node of the Trie

public:
    // Constructor initializes the Trie with a root node
    Trie() {
        root = new TrieNode();
    }

    /*
     * Insert a word into the Trie.
     * - Traverse the Trie, character by character.
     * - Create a new node if a character does not exist.
     * - Mark the last node as `isEndOfWord = true` to indicate the end of a valid word.
     */
    void insert(string word) {
        TrieNode* node = root; // Start from the root node
        for (char ch : word) {
            // If the character is not in the current node's children, create a new TrieNode
            if (!node->children[ch]) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch]; // Move to the next node
        }
        node->isEndOfWord = true; // Mark the last node as the end of the word
    }

    /*
     * Search for a word in the Trie.
     * - Traverse character by character.
     * - If a character is missing at any point, return false.
     * - If we reach the last node and `isEndOfWord` is true, return true.
     */
    bool search(string word) {
        TrieNode* node = root; // Start from the root node
        for (char ch : word) {
            // If the character is not found, the word is not present
            if (!node->children[ch]) return false;
            node = node->children[ch]; // Move to the next node
        }
        return node->isEndOfWord; // Return true if this node marks the end of a word
    }
};

int main() {
    Trie trie;  // Create a Trie object

    // Insert words into the Trie
    trie.insert("apple");
    trie.insert("banana");

    // Search for words in the Trie
    cout << "Search apple: " << trie.search("apple") << endl;   // 1 (true) - Exists
    cout << "Search banana: " << trie.search("banana") << endl; // 1 (true) - Exists
    cout << "Search orange: " << trie.search("orange") << endl; // 0 (false) - Not found

    return 0;
}

