//Interface Segregation Principle (ISP)
//Clients should not be forced to depend on interfaces they do not use.
//Instead of a large interface, create multiple smaller interfaces.

#include <iostream> // Required for input-output operations
using namespace std;

// Interface for working capability
class IWorkable {
public:
    virtual void work() = 0; // Pure virtual function (must be implemented)
};

// Interface for eating capability
class IEatable {
public:
    virtual void eat() = 0; // Pure virtual function (must be implemented)
};

// HumanWorker class implements both IWorkable and IEatable
class HumanWorker : public IWorkable, public IEatable {
public:
    // Implementation of work() for humans
    void work() override {
        cout << "Human is working" << endl;
    }

    // Implementation of eat() for humans
    void eat() override {
        cout << "Human is eating" << endl;
    }
};

// RobotWorker class implements only IWorkable (not forced to implement IEatable)
class RobotWorker : public IWorkable {
public:
    // Implementation of work() for robots
    void work() override {
        cout << "Robot is working" << endl;
    }
};

int main() {
    HumanWorker human; // Creating a HumanWorker object
    RobotWorker robot; // Creating a RobotWorker object

    // Demonstrating working and eating functionality for HumanWorker
    human.work(); // Output: "Human is working"
    human.eat();  // Output: "Human is eating"

    // Demonstrating working functionality for RobotWorker
    robot.work(); // Output: "Robot is working"
    // robot.eat(); // ❌ ERROR: RobotWorker doesn't implement eat()

    return 0;
}

