#include <iostream>
#include <vector>
using namespace std;

// Trie Node structure
struct TrieNode {
    TrieNode* children[26]; // Array of pointers for each letter (a-z)
    bool isEndOfWord; // Flag to mark if the node is the end of a word

    // Constructor to initialize the TrieNode
    TrieNode() {
        isEndOfWord = false; // Initially, the node is not the end of any word
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr; // Initialize all children pointers to nullptr
        }
    }
};

// Trie class to perform operations like insert, search, and prefix search
class Trie {
public:
    TrieNode* root; // Root node of the Trie

    // Constructor to initialize the Trie with an empty root
    Trie() {
        root = new TrieNode();
    }

    // Function to insert a word into the Trie
    void insert(string word) {
        TrieNode* current = root; // Start from the root node
        for (char c : word) { // Traverse each character in the word
            int index = c - 'a'; // Calculate the index based on the character ('a' -> 0, 'b' -> 1, ..., 'z' -> 25)
            // If the current node's child at the calculated index is null, create a new TrieNode
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index]; // Move to the next node in the Trie
        }
        current->isEndOfWord = true; // Mark the end of the word
    }

    // Function to search for a word in the Trie
    bool search(string word) {
        TrieNode* current = root; // Start from the root node
        for (char c : word) { // Traverse each character in the word
            int index = c - 'a'; // Calculate the index of the character in the Trie
            if (current->children[index] == nullptr) { // If no node exists for the character, return false
                return false;
            }
            current = current->children[index]; // Move to the next node
        }
        return current->isEndOfWord; // Return true if we are at the end of the word in the Trie
    }

    // Function to check if there is any word in the Trie that starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* current = root; // Start from the root node
        for (char c : prefix) { // Traverse each character in the prefix
            int index = c - 'a'; // Calculate the index of the character in the Trie
            if (current->children[index] == nullptr) { // If no node exists for the character, return false
                return false;
            }
            current = current->children[index]; // Move to the next node
        }
        return true; // Return true if the prefix exists in the Trie
    }
};

// Driver code to test the Trie operations
int main() {
    Trie trie;

    // Insert words into the Trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("appl");

    // Search for full words
    cout << "Searching for 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'appl': " << (trie.search("appl") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'ap': " << (trie.search("ap") ? "Found" : "Not Found") << endl;

    // Prefix search
    cout << "Prefix search for 'ap': " << (trie.startsWith("ap") ? "Found" : "Not Found") << endl;
    cout << "Prefix search for 'apple': " << (trie.startsWith("apple") ? "Found" : "Not Found") << endl;

    return 0; // End of the program
}
