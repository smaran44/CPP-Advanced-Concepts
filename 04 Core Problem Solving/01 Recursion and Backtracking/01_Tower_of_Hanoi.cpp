#include <iostream>
using namespace std;

/*
    Program: Tower of Hanoi using Recursion
    ---------------------------------------
    What we are doing:
    - We solve the Tower of Hanoi problem for 'n' disks using a recursive approach.
    - The goal is to move all disks from the source rod to the destination rod using a helper rod.
    - We follow the classic rules:
      1. Only one disk can be moved at a time.
      2. Only the top disk can be moved.
      3. A larger disk cannot be placed on top of a smaller disk.

    Concept used: Recursion – solving a problem by breaking it down into smaller instances of the same problem.
*/

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char helper, char destination) {
    // Base case: If only one disk, directly move it to the destination
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    // Step 1: Move n-1 disks from source to helper, using destination as temporary
    towerOfHanoi(n - 1, source, destination, helper);

    // Step 2: Move the largest disk (nth disk) from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    // Step 3: Move the n-1 disks from helper to destination, using source as temporary
    towerOfHanoi(n - 1, helper, source, destination);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    // Starting the Tower of Hanoi process
    // A = Source rod, B = Helper rod, C = Destination rod
    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
/* examplw
towerOfHanoi(3, A, B, C)
├── towerOfHanoi(2, A, C, B)
│   ├── towerOfHanoi(1, A, B, C)
│   │   → Move disk 1 from A to C
│   └── Move disk 2 from A to B
│   └── towerOfHanoi(1, C, A, B)
│       → Move disk 1 from C to B
├── Move disk 3 from A to C
├── towerOfHanoi(2, B, A, C)
│   ├── towerOfHanoi(1, B, C, A)
│   │   → Move disk 1 from B to A
│   └── Move disk 2 from B to C
│   └── towerOfHanoi(1, A, B, C)
│       → Move disk 1 from A to C
*/