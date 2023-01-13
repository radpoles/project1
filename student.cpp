#include <iostream>
#include <string>
#include <array>
#include "student.h"

using namespace std;

/*Create the class Student  in the files student.hand student.cpp, which includes each of the following variables:
student ID
first name
last name
email address
age
array of number of days to complete each course
degree program*/

/*Create each of the following functions in the Student class :

	a.an accessor(i.e., getter) for each instance variable from part D1

	b.a mutator(i.e., setter) for each instance variable from part D1

	c.All external accessand changes to any instance variables of the Student class must be done using accessor and mutator functions.

	d.constructor using all of the input parameters provided in the table

	e.print() to print specific student data*/

Student::Student(string stdID, string fName, string lName, string eml, int stdAge, int dysInCourse[], DegreeProgram dgrProgram)
{
	studentID = stdID;
	firstName = fName;
	lastName = lName;
	email = eml;
	age = stdAge;
	daysInCourse[0] = dysInCourse[0];
	daysInCourse[1] = dysInCourse[1];
	daysInCourse[2] = dysInCourse[2];
	degreeProgram = dgrProgram;
}

void Student::SetstudentID(string stdID) {
	studentID = stdID;
	return;
}

void Student::SetfirstName(string fName) {
	firstName = fName;
	return;
}

void Student::SetlastName(string lName) {
	lastName = lName;
	return;
}

void Student::Setemail(string eml) {
	email = eml;
	return;
}

void Student::Setage(int stdage) {
	age = stdage;
	return;
}

void Student::SetdaysInCourse(int dysInCourse[]) {
	daysInCourse[0] = dysInCourse[0];
	daysInCourse[1] = dysInCourse[1];
	daysInCourse[2] = dysInCourse[2];
	return;
}

void Student::SetdegreeProgram(DegreeProgram dgrProgram) {
	degreeProgram = dgrProgram;
	return;
}

string Student::GetstudentID() const {
	return studentID;
}

string Student::GetfirstName() const {
	return firstName;
}

string Student::GetlastName() const {
	return lastName;
}

string Student::Getemail() const {
	return email;
}

int Student::Getage() const {
	return age;
}

int* Student::GetdaysInCourse() {
	return daysInCourse;
} // not sure if i need to fix this ? ^^
DegreeProgram Student::GetdegreeProgram() {
	return degreeProgram;
}

void Student::print() {
	cout << this->studentID << "	First Name: " << this->firstName << "	Last Name: " << this->lastName;
	cout << "		Age: " << this->age << "   	Days in Course: " << this->daysInCourse[0] << ", ";
	cout << this->daysInCourse[1] << ", " << this->daysInCourse[2] << "		Degree Program : ";
	string DegreeString = "SECURITY";
	if (this->degreeProgram == SOFTWARE) {
		DegreeString = "SOFTWARE";
	}
	if (this->degreeProgram == NETWORK) {
		DegreeString = "NETWORK";
	}
	cout << DegreeString << endl;
} // this is printing out the index for Degree Program and Number of Days in Courses
