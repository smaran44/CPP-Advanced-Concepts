//Dependency Inversion Principle (DIP)
//High-level modules should not depend on low-level modules.
//Both should depend on abstractions (interfaces).

#include <iostream> // Required for input-output operations
using namespace std;

// Abstract interface for notification (Abstraction Layer)
class INotification {
public:
    virtual void sendMessage(const string& message) = 0; // Pure virtual function
};

// Low-level module: Email notification
class EmailNotification : public INotification {
public:
    // Implementation of sendMessage() for email
    void sendMessage(const string& message) override {
        cout << "Sending Email: " << message << endl;
    }
};

// High-level module: Notification Service
// Depends on abstraction (INotification) instead of concrete implementation (like EmailNotification)
class NotificationService {
private:
    INotification& notifier; // Using reference to INotification (Dependency Injection)
public:
    // Constructor receives a notifier object (dependency injection)
    NotificationService(INotification& n) : notifier(n) {}

    // Uses the notifier object to send messages
    void notifyUser(const string& message) {
        notifier.sendMessage(message);
    }
};

int main() {
    EmailNotification emailNotifier;  // Creating an email notification object
    NotificationService service(emailNotifier); // Injecting dependency into NotificationService
    
    service.notifyUser("Your order has been shipped!"); // Sending notification

    return 0;
}

