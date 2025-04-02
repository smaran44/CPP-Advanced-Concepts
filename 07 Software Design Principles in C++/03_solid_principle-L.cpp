//Liskov Substitution Principle (LSP)
//Subtypes must be substitutable for their base types without altering the correctness of the program.

#include <iostream> // Required for input-output operations
using namespace std;

// Base class representing a generic bird
class Bird {
public:
    // Virtual function that defines flying behavior for birds
    virtual void fly() {
        cout << "Bird is flying" << endl;
    }
};

// Subclass that maintains expected behavior (A sparrow can fly)
class Sparrow : public Bird {
public:
    // Overriding fly() to provide specific implementation for Sparrow
    void fly() override {
        cout << "Sparrow is flying" << endl;
    }
};

// Subclass that breaks the Liskov Substitution Principle (LSP) 
// (Penguins do not fly, so overriding fly() leads to an unexpected behavior)
class Penguin : public Bird {
public:
    // Overriding fly() in a way that contradicts the base class expectation
    void fly() override {
        cout << "Penguins cannot fly!" << endl;
    }
};

// Function that expects any Bird to be able to fly
void makeBirdFly(Bird& bird) {
    bird.fly(); // Calls the appropriate fly() method based on the object type (Polymorphism)
}

int main() {
    Sparrow sparrow;
    Penguin penguin;

    makeBirdFly(sparrow);  // Correct behavior: Sparrow can fly
    makeBirdFly(penguin);  // Violates LSP: Penguin cannot fly, but the base class assumes it can

    return 0;
}
