#include "Classy.h"
using namespace std;

Classy::Classy() {
    cout << "\n\nDEFAULT CONSTRUCTOR CALLED\n";
    name = "unknown";
    p = nullptr;
}

Classy::Classy(string s, string* ptr) {
    cout << "\n\nOVERLOADED CONSTRUCTOR CALLED\n";
    name = s;
    p = ptr;
}

string Classy::getName() { return name; }
string* Classy::getP() { return p; }

void Classy::setP(string q) { *p = q; }
void Classy::setName(string n) { name = n; }
/*
// Copy assignment operator
Classy& Classy::operator = (const Classy& objToCopy) {
    cout << "COPY ASSIGNMENT OPERATOR CALLED\n";
    if (this != &objToCopy) {
        name = objToCopy.name;
        delete p;
        p = new string;
        *p = (*objToCopy.p); // Allocate sub-object
    }
    return *this;
}
*/
/*
// Copy constructor
Classy::Classy(const Classy& origObject) {
    cout << "COPY CONSTRUCTOR CALLED\n";
    name = origObject.name;

    p = new string;
    *p = (*origObject.p); // Allocate sub-object
}
*/ 
// Destructor
Classy::~Classy() {
    cout << "\nDESTRUCTOR CALLED\n";
    if (p != nullptr) {
        delete p;
        p = nullptr;
    }
}


