#include <iostream>
using namespace std;

// Forward declaration
class ClassB;

class ClassA {
private:
    int privateVar;

public:
    ClassA() { privateVar = 42; }

    // Declaring ClassB as a friend class
    friend class ClassB;
};

class ClassB {
public:
    void showPrivateVar(ClassA obj) {
        cout << "Accessing privateVar from ClassA: " << obj.privateVar << endl;
    }
};

int main() {
    ClassA a;
    ClassB b;
    b.showPrivateVar(a);
    return 0;
}
