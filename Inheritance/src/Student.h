/*
 * Student.h
 *
 *  Created on: Apr 20, 2016
 *      Author: Bizzy
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include "Person.h"
using namespace std;
class Student:public Person{
public:
	virtual void display();
	void setMajor(string);
	string getMajor();
private:
	string Major;
};

 void Student::display(){
	cout << name << endl;
	cout << birthday << endl;
	cout << Major << endl;
}
string Student::getMajor(){
	return Major;
}
void Student::setMajor(string newMajor){
	Major = newMajor;
}


#endif /* STUDENT_H_ */
