// CS201R-Unit10b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "examples.h"

int main() {
	//*************************************************************************
	// CREATE A NEW OBJECT CLASIC(Bugs Bunny, PTR TO Yosemite Sam) 
	//    pass  'ptr' to function 1
	//    class1.p and ptr are pointing to the same place
	//    by sending ptr - we update contents of class1.p
	example1();

	//*************************************************************************
	// RUN 1:  COMMENT OUT COPY ASSIGNMENT OPERATOR
	//    SHALLOW COPY (no copy assignment)  
	//    this will cause the pointer to point to the same 
	//    location in memory and update the class
	//    so calling function 2 && passing classic.p will update classic2!!
    //example2();

	//  RUN 2: UNCOMMENT THE COPY ASSIGNMENT OPERATOR & rerun this example2
	//  see changes to the addresses used in previous examples
	//  class2 is now a deep copy & changes to class1 will not affect class2
    //  because they pointers point to different locations

	//*************************************************************************

	//RUN1: THE COPY CONSTRUCTOR IS COMMENTED OUT 
	//      THIS IS A SHALLOW COPY
	//      shallow copy because we are copying all information
	//      from class1
	//      NOTE: the address of 'p' in both class1 & class3
	//          point to the same place. When class1 is deleted 
	//          at the end of this function. class3 'p' pointer 
	//          is no longer valid
	  
	//example3();
	
	//RUN2: UNCOMMENT THE COPY CONSTRUCTOR AND RERUN
	//     class3 is now a deep copy 
	//     note changes to the addresses from previous examples
	//     changes to class1 will not affect class3
	//     because the pointers point to different locations
	//*************************************************************************
	//  here class4 is defined
	//  and class4 is copied into class3  (shallow copy if = is not overriden)
    //example4();

}
