//============================================================================
// Name        : Inheritance.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Instructor.h"
using namespace std;

int main() {
	Person Chris;
	Instructor Sam;
	Student Gil;

	Chris.setName("Christian Martinez");
	Chris.setBirthday("February 27, 1993");

	Sam.setName("Salmaun Masooman");
	Sam.setBirthday("October 12, 1984");
	Sam.setSalary(90000);

	Gil.setName("Gil Colleluori");
	Gil.setBirthday("April 25, 1992");
	Gil.setMajor("Computer Science");

	Chris.display();
	cout << endl;
	Sam.display();
	cout << endl;
	Gil.display();

	return 0;
}
