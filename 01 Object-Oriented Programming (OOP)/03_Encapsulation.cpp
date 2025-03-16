// Encapsulation is wrapping up of data (attributes) and methods (functions) into a single unit called class.
// It is a way to restrict access to certain parts of the object and to prevent the object's internal state from being accidentally changed.

#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance; // Private data cannot be accessed directly

public:
    // Constructor to initialize values
    BankAccount(string name, double initialBalance) {
        accountHolder = name;
        balance = initialBalance;
    }

    // Getter for accountHolder (Read-Only Access)
    string getAccountHolder() {
        return accountHolder;
    }

    // Getter for balance (Read-Only Access)
    double getBalance() {
        return balance;
    }

    // Method to deposit money (Controlled Access)
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Method to withdraw money (Controlled Access)
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << ". Remaining balance: $" << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance!" << endl;
        }
    }
};

int main() {
    // Creating an object of BankAccount
    BankAccount myAccount("Alice", 1000.0);

    // Accessing accountHolder using getter
    cout << "Account Holder: " << myAccount.getAccountHolder() << endl;

    // Depositing and withdrawing money (Encapsulated behavior)
    myAccount.deposit(500);
    myAccount.withdraw(200);

    // Trying to access balance directly (Not allowed)
    // myAccount.balance = 5000;  // ❌ Error: balance is private

    cout << "Final Balance: $" << myAccount.getBalance() << endl;
    return 0;
}
