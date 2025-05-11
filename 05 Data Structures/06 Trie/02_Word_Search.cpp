#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Trie Node structure
struct TrieNode {
    TrieNode* children[26]; // 26 letters in the alphabet (lowercase a-z)
    bool isEndOfWord; // Flag to mark if the node is the end of a word

    TrieNode() {
        isEndOfWord = false; // Initially, the node is not the end of a word
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr; // Initialize all child pointers to nullptr
        }
    }
};

// Trie class for word insert and search operations
class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode(); // Initialize the root node of the Trie
    }

    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) { // For each character in the word
            int index = c - 'a'; // Calculate the index based on the character ('a' -> 0, 'b' -> 1, ..., 'z' -> 25)
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode(); // Create a new node if it doesn't exist
            }
            current = current->children[index]; // Move to the next node
        }
        current->isEndOfWord = true; // Mark the end of the word
    }

    // Search for a word in the Trie
    bool search(string word) {
        TrieNode* current = root;
        for (char c : word) { // For each character in the word
            int index = c - 'a'; // Calculate the index for the character
            if (current->children[index] == nullptr) {
                return false; // If no match is found in the Trie, return false
            }
            current = current->children[index]; // Move to the next node
        }
        return current->isEndOfWord; // Return true if the node is the end of the word
    }
};

// Depth-First Search (DFS) helper function for finding words
void dfs(vector<vector<char>>& board, Trie& trie, TrieNode* node, int i, int j, string word, unordered_set<string>& result) {
    // If the current node marks the end of a word, add it to the result
    if (node->isEndOfWord) {
        result.insert(word);
    }

    // Boundary check or already visited cell
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#') {
        return; // If out of bounds or already visited, return
    }

    char c = board[i][j]; // Get the current character
    int index = c - 'a'; // Calculate the index of the character in the Trie
    TrieNode* nextNode = node->children[index]; // Get the next node for the character

    if (nextNode == nullptr) {
        return; // If no node exists for this character, return
    }

    board[i][j] = '#'; // Mark the current cell as visited by replacing with '#'

    // Explore all 4 directions (up, down, left, right)
    dfs(board, trie, nextNode, i - 1, j, word + c, result); // Up
    dfs(board, trie, nextNode, i + 1, j, word + c, result); // Down
    dfs(board, trie, nextNode, i, j - 1, word + c, result); // Left
    dfs(board, trie, nextNode, i, j + 1, word + c, result); // Right

    board[i][j] = c; // Unmark the current cell (backtrack)
}

// Function to find all words from the board that exist in the Trie
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie trie;
    unordered_set<string> result;

    // Insert all words into the Trie
    for (string& word : words) {
        trie.insert(word);
    }

    // Perform DFS for each cell in the board
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            dfs(board, trie, trie.root, i, j, "", result); // Start DFS from each cell
        }
    }

    return vector<string>(result.begin(), result.end()); // Return the result as a vector
}

// Driver code
int main() {
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };

    vector<string> words = {"oath", "pea", "eat", "rain"};

    vector<string> foundWords = findWords(board, words); // Find words in the board

    cout << "Found words: ";
    for (string& word : foundWords) {
        cout << word << " "; // Print each found word
    }
    cout << endl;

    return 0; // End of program
}
