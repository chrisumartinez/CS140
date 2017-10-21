/*
 * Person.h
 *
 *  Created on: Apr 20, 2016
 *      Author: Bizzy
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <string>
using namespace std;
class Person{
public:
	 void display();
	 void setName(string newName);
	 string getName();
	 void setBirthday(string);
	 string name;
	 string birthday;
};

 void Person::display(){
	cout << name << endl;
	cout << birthday << endl;
}
 void Person::setName(string newName){
	 name = newName;
 }
 string Person::getName(){
	 return name;
 }
 void Person::setBirthday(string newBirthday){
	 birthday = newBirthday;
 }

#endif /* PERSON_H_ */
