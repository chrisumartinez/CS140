/*
 * Instructor.h
 *
 *  Created on: Apr 20, 2016
 *      Author: Bizzy
 */

#ifndef INSTRUCTOR_H_
#define INSTRUCTOR_H_
#include <string>
#include "Person.h"
using namespace std;


class Instructor:public Person{
public:
	virtual void display();
	void setSalary(int);
	int getSalary();
private:
	int salary;
};
 void Instructor::display(){
	cout << name << endl;
	cout << birthday << endl;
	cout << salary << endl;
}
void Instructor::setSalary(int newSalary){
	salary = newSalary;
}
int Instructor::getSalary(){
	return salary;
}





#endif /* INSTRUCTOR_H_ */
