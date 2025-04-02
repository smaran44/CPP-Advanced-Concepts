/*
    SOLID Principles in C++
    ------------------------
    - SOLID is a set of five principles that improve software design.
    - They help create maintainable, scalable, and flexible code.

    SOLID Acronym:
    S – Single Responsibility Principle (SRP)
    O – Open/Closed Principle (OCP)
    L – Liskov Substitution Principle (LSP)
    I – Interface Segregation Principle (ISP)
    D – Dependency Inversion Principle (DIP)
*/

// Single Responsibility Principle (SRP)
//A class should have only one reason to change. Each class should have a single responsibility.

#include <iostream> // Required for input-output operations
using namespace std;

// Class responsible for handling report data (Single Responsibility Principle)
class Report {
public:
    // Function to return report data
    // Marked as `const` since it does not modify any member variables
    string getReportData() const {  
        return "Report Data";
    }
};

// Separate class for printing reports (Follows Single Responsibility Principle)
class ReportPrinter {
public:
    // Function to print report data
    // Accepts a constant reference to avoid unnecessary copying
    void printReport(const Report& report) {  
        cout << "Printing: " << report.getReportData() << endl;
    }
};

int main() {
    // Creating an object of Report class
    Report report;

    // Creating an object of ReportPrinter class
    ReportPrinter printer;

    // Calling the printReport function to print the report
    printer.printReport(report); // Works correctly

    return 0;
}
