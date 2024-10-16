#include "examples.h"

void function1(string* x) {
	*x = "ONE";
	cout << setw(15) << "x:" << setw(18)
		<< *x << " : " << x << endl;
}

void example1() {
	cout << "\n\nEXAMPLE 1" << endl;

	// CREATE A NEW OBJECT CLASIC(Bugs Bunny, PTR TO Yosemite Sam) 
	//    pass  'ptr' to function 1
	//    class1.p and ptr are pointing to the same place
	//    by sending ptr - we update contents of class1.p

	string name = "Bugs Bunny";
	string* ptr = new string("Yosemite Sam");
	Classy class1(name, ptr);

	cout << "Class1 Name: " << class1.getName() << endl;
	cout << setw(15) << "1Class1 Before:   " << setw(15)
		<< *class1.getP() << " : "
		<< class1.getP() << endl;
	function1(ptr);
	cout << setw(15) << "1Class2 After:    " << setw(15)
		<< *class1.getP() << " : "
		<< class1.getP() << endl << endl;
}

void function2(string* x) {
	*x = "TWO";
	cout << setw(19) << "       x:   " << setw(6)
	 	 << " " << setw(15) << *x << " : " << x << endl;
}

void example2() {

	cout << "\n\nEXAMPLE 2: COPY ASSIGNMENT OPERATOR" << endl;

	//RUN1: THE COPY ASSIGNMENT OPERATOR IS COMMENTED OUT
	//    THIS IS A SHALLOW COPY (no copy assignment)  
	//    this will cause the pointer to point to the same 
	//    location in memory and update the class
	//    so calling function 2 && 
    //       passing classic.p will update classic2!!  
    //    NOTE: the exit status -1 is due 
    //          to the destructor being called for 
    //          both classes (1&2) are
    //          pointing to the same location in memory
    //          which was deleted when the first class
    //          was destroyed at the end of the function
	//
	//RUN 2: UNCOMMENT THE COPY ASSIGNMENT OPERATOR & RERUN
	//  class 2 is now a deep copy 
    //     note changes to the addresses from previous examples
    //     changes to class1 will not affect class2
    //     because the pointers point to different locations
    //    

	string name = "Bugs Bunny";
	string* ptr = new string("Yosemite Sam");
	Classy class1(name, ptr);

	Classy class2;
	class2 = class1;
	class2.setName("Wiley Coyote");

	cout << "Class2 Name: " << class2.getName() << endl;
	cout << setw(15) << " 2Class1 Before:   " << setw(15)
		<< class1.getName() << " : "
		<< *class1.getP() << " : "
		<< class1.getP() << endl;
	cout << setw(15) << " 2Class2 Before:   " << setw(15)
		<< class2.getName() << " : "
		<< *class2.getP() << " : "
		<< class2.getP() << endl;

	function2(class1.getP());

	cout << setw(15) << " 2Class1 After:     " << setw(14)
		<< class1.getName() << " : "
		<< *class1.getP() << " : "
		<< class1.getP() << endl;
	cout << setw(15) << " 2Class2 After:     " << setw(14)
		<< class2.getName() << " : "
		<< *class2.getP() << " : "
		<< class2.getP() << endl << endl;
}

void function3(Classy& c) {
	c.setP("THREE");
	cout << setw(19) << "      p:     " << setw(8)
		<< " " << setw(15) << *c.getP() << " : " << c.getP() << endl;
}
void example3() {

	cout << "\n\nEXAMPLE 3: COPY CONSTRUCTOR" << endl;

	//RUN1: THE COPY CONSTRUCTOR IS COMMENTED OUT 
	//      THIS IS A SHALLOW COPY
	//      shallow copy because we are copying all information
	//      from class1
    //      NOTE: the address of 'p' in both class1 & class3
	//          point to the same place. When class1 is deleted 
	//          at the end of this function. class3 'p' pointer 
	//          is no longer valid
	//  
    //RUN2: UNCOMMENT THE COPY CONSTRUCTOR AND RERUN
	//     class3 is now a deep copy 
	//     note changes to the addresses from previous examples
	//     changes to class1 will not affect class3
	//     because the pointers point to different locations

    // first - reset class 1
	string name = "Bugs Bunny";
	string* ptr = new string("Yosemite Sam");
	Classy class1(name, ptr);

	// Instantiate class3 using the information from class1
	Classy class3(class1);

	// call to function 3 will pass classic3 using copy constructor
	cout << setw(15) << " 3Class1 Before:   " << setw(15)
		<< class1.getName() << " : "
		<< *class1.getP() << " : "
		<< class1.getP() << endl;
	cout << setw(15) << " 3Class3 Before:   " << setw(15)
		<< class3.getName() << " : "
		<< *class3.getP() << " : "
		<< class3.getP() << endl;

	function3(class3);

	cout << setw(15) << " 3Class1 After:    " << setw(15)
		<< class1.getName() << " : "
		<< *class1.getP() << " : "
		<< class1.getP() << endl;
	cout << setw(15) << " 3Class3 After:    " << setw(15)
		<< class3.getName() << " : "
		<< *class3.getP() << " : "
		<< class3.getP() << endl;

}
void example4() {

	cout << "\n\nEXAMPLE 4" << endl;

	//  first - reset class 1 & 3
	string name = "Bugs Bunny";
	string* ptr = new string("Yosemite Sam");
	Classy class1(name, ptr);
	Classy class3(class1);

	//  here class4 is defined
	//  and class4 is copied into class3  
	//  This would be a shallow copy if copy
	//  assignment operator (=) was not overriden 
	name = "Han Solo";
	string* x = new string("Scooby Doo");
	Classy class4(name, x);

	cout << setw(15) << " 4Class3 Before:    " << setw(15)
		<< class3.getName() << " : "
		<< *class3.getP() << " : "
		<< class3.getP() << endl;
	cout << setw(15) << " 4Class4 Before:    " << setw(15)
		<< class4.getName() << " : "
		<< *class4.getP() << " : "
		<< class4.getP() << endl;

	class3 = class4;

	cout << setw(15) << " 4Class3 After:     " << setw(15)
		<< class3.getName() << " : "
		<< *class3.getP() << " : "
		<< class3.getP() << endl;
	cout << setw(15) << " 4Class4 After:     " << setw(15)
		<< class4.getName() << " : "
		<< *class4.getP() << " : "
		<< class4.getP() << endl;

}

