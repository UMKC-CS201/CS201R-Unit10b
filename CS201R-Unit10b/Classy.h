#include <string>
#include <iostream>
using namespace std;

class Classy {
private:
    string name;
    string* p;

public:
    Classy();                          //default constructor
    Classy(string, string*);           // constructor

    //copy assignment operator
    //Classy& operator= (const Classy& objToCopy);

    //copy constructor
    //Classy(const Classy& origObject);  

     //destructor
    ~Classy();

    // getters
    string getName();
    string* getP();

    // setters
    void setP(string q);
    void setName(string n);

};

