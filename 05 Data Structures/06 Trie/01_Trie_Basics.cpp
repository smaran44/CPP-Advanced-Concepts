#include <iostream>
#include <vector>
using namespace std;

// Trie Node structure
struct TrieNode {
    TrieNode* children[26]; // 26 letters in the alphabet (for lowercase 'a' to 'z')
    bool isEndOfWord; // Marks the end of a word

    TrieNode() {
        isEndOfWord = false; // Initially, the node is not the end of a word
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr; // Initialize all children to null
        }
    }
};

// Trie class for operations (Insert, Search, Delete)
class Trie {
public:
    TrieNode* root;

    // Constructor to initialize the Trie
    Trie() {
        root = new TrieNode(); // Create the root node
    }

    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* current = root; // Start from the root node
        for (char c : word) { // Loop through each character in the word
            int index = c - 'a'; // Calculate the index for the character ('a' -> 0, 'b' -> 1, ..., 'z' -> 25)
            if (current->children[index] == nullptr) { // If this node doesn't exist
                current->children[index] = new TrieNode(); // Create a new node for this character
            }
            current = current->children[index]; // Move to the next node
        }
        current->isEndOfWord = true; // Mark the last node as the end of the word
    }

    // Search for a word in the Trie
    bool search(string word) {
        TrieNode* current = root; // Start from the root node
        for (char c : word) { // Loop through each character in the word
            int index = c - 'a'; // Calculate the index for the character
            if (current->children[index] == nullptr) { // If the character doesn't exist in the Trie
                return false; // Return false (word not found)
            }
            current = current->children[index]; // Move to the next node
        }
        return current->isEndOfWord; // Return true if the current node marks the end of the word
    }

    // Delete a word from the Trie
    bool deleteWord(TrieNode* current, string word, int index) {
        if (index == word.length()) { // Base case: If we reached the end of the word
            if (!current->isEndOfWord) return false; // Word not found (end of word marker is false)
            current->isEndOfWord = false; // Unmark the end of word
            return true; // Successfully deleted
        }

        int childIndex = word[index] - 'a'; // Get the index of the current character
        if (current->children[childIndex] == nullptr) return false; // If the character does not exist in Trie, return false

        bool deleted = deleteWord(current->children[childIndex], word, index + 1); // Recursively delete the word from the next node

        if (deleted) { // If the word was deleted in the recursion
            // Check if the current node has no children
            bool isEmpty = true;
            for (int i = 0; i < 26; i++) {
                if (current->children[i] != nullptr) {
                    isEmpty = false; // There are still children, so don't delete the current node
                    break;
                }
            }
            if (isEmpty) { // If no children exist, delete the current node's child
                delete current->children[childIndex]; // Delete the child node
                current->children[childIndex] = nullptr; // Set the child pointer to nullptr
            }
        }
        return deleted; // Return true if the word was successfully deleted
    }

    void deleteWord(string word) {
        deleteWord(root, word, 0); // Start the deletion from the root node and index 0
    }
};

// Driver Code
int main() {
    Trie trie; // Create a new Trie object

    trie.insert("hello"); // Insert the word "hello" into the Trie
    trie.insert("world"); // Insert the word "world" into the Trie

    // Search for the word "hello" in the Trie
    cout << "Searching 'hello': " << (trie.search("hello") ? "Found" : "Not Found") << endl;

    // Search for the word "world" in the Trie
    cout << "Searching 'world': " << (trie.search("world") ? "Found" : "Not Found") << endl;

    // Search for the word "hell" in the Trie (should not be found)
    cout << "Searching 'hell': " << (trie.search("hell") ? "Found" : "Not Found") << endl;

    // Delete the word "world" from the Trie
    trie.deleteWord("world");

    // Search for the word "world" after deletion (should not be found)
    cout << "Searching 'world' after deletion: " << (trie.search("world") ? "Found" : "Not Found") << endl;

    return 0; // End of the program
}
