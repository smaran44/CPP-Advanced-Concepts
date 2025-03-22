#include <iostream>

using namespace std;

/*
 * What is a Trie (Prefix Tree)?
 * ------------------------------
 * - A Trie is a **tree-based data structure** used for **efficient string storage & retrieval**.
 * - Each node represents a single character.
 * - Used for:
 *   ✅ Word Search
 *   ✅ AutoComplete
 *   ✅ Dictionary & Spell Checking
 *   ✅ Longest Prefix Matching
 * - Time Complexity:
 *   🔹 Insert: O(L)  (L = length of the word)
 *   🔹 Search: O(L)
 *   🔹 Delete: O(L)
 */

/*
 * Basic Structure of a Trie
 * -------------------------
 * - Each Trie node stores:
 *   ✅ A character
 *   ✅ An array (or map) of child nodes
 *   ✅ A boolean flag to mark the end of a word
 *
 * Example:
 * --------
 * Inserting words: ["cat", "car", "bat"]
 *
 *                (root)
 *               /     \
 *              c       b
 *             / \       \
 *            a   a       a
 *           /     \       \
 *          t       r       t
 *         (✔)     (✔)     (✔)
 */

int main() {
    cout << "A Trie is structured as a tree where each node represents a character." << endl;
    return 0;
}
