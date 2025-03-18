#include <iostream>
using namespace std;

// 🔹 Base Class
class Base {
private:
    int privateVar = 1;  // ❌ Not inherited
protected:
    int protectedVar = 2; // 🔸 Inherited with modifications
public:
    int publicVar = 3;    // ✅ Inherited with mode effects

    void show() {
        cout << "Base Class Variables: privateVar (Not Inherited), protectedVar = " << protectedVar << ", publicVar = " << publicVar << endl;
    }
};

// 🔹 Derived Class (Private Mode)
class PrivateDerived : private Base {
public:
    void showAccess() {
        cout << "\n🔹 Private Inheritance:\n";
        // privateVar is NOT inherited ❌
        cout << "protectedVar (becomes private) = " << protectedVar << endl; // Now private
        cout << "publicVar (becomes private) = " << publicVar << endl;      // Now private
    }
};

// 🔹 Derived Class (Protected Mode)
class ProtectedDerived : protected Base {
public:
    void showAccess() {
        cout << "\n🔹 Protected Inheritance:\n";
        // privateVar is NOT inherited ❌
        cout << "protectedVar (remains protected) = " << protectedVar << endl; // Still protected
        cout << "publicVar (becomes protected) = " << publicVar << endl;       // Now protected
    }
};

// 🔹 Derived Class (Public Mode)
class PublicDerived : public Base {
public:
    void showAccess() {
        cout << "\n🔹 Public Inheritance:\n";
        // privateVar is NOT inherited ❌
        cout << "protectedVar (remains protected) = " << protectedVar << endl; // Still protected
        cout << "publicVar (remains public) = " << publicVar << endl;          // Still public
    }
};

int main() {
    Base b;
    b.show();

    PrivateDerived pd;
    pd.showAccess();
    // pd.protectedVar;  ❌ Not accessible (private now)
    // pd.publicVar;     ❌ Not accessible (private now)

    ProtectedDerived pt;
    pt.showAccess();
    // pt.protectedVar;  ❌ Not accessible (still protected)
    // pt.publicVar;     ❌ Not accessible (now protected)

    PublicDerived pb;
    pb.showAccess();
    // pb.protectedVar;  ❌ Not accessible (still protected)
    cout << "\n🔹 Accessing publicVar from PublicDerived in main(): " << pb.publicVar << endl;  // ✅ Accessible

    return 0;
}
/*
| Base Class Member | Private Inheritance | Protected Inheritance | Public Inheritance |
|-------------------|---------------------|-----------------------|--------------------|
| private           | ❌ Not Inherited     | ❌ Not Inherited       | ❌ Not Inherited    |
| protected         | 🔸 Becomes Private   | 🔸 Remains Protected   | 🔸 Remains Protected|
| public            | 🔸 Becomes Private   | 🔸 Becomes Protected   | ✅ Remains Public   |
*/