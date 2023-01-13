#include <iostream>
#include <string>
#include <array>
#include "student.h"
#include "roster.h"

using namespace std;

void Roster::parse(string data) {
	size_t rhs = data.find(",");
	string studentID = data.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string firstName = data.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string lastName = data.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string emailAddress = data.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int age = stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int daysInCourse1 = stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int daysInCourse2 = stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int daysInCourse3 = stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string strDegreeProgram = data.substr(lhs, rhs - lhs);

	DegreeProgram degreeProgram = DegreeProgram::NETWORK;
	if (strDegreeProgram == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK;
	}
	else if (strDegreeProgram == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (strDegreeProgram == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int days[] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterArray[index++] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);

}

void Roster::remove(string studentID)
{	
	for (int i = 0; i < index; ++i) {
		if (classRosterArray[i]->GetstudentID() == studentID) {
			classRosterArray[i]->SetstudentID("invalid"); 
			cout << "Student with ID " << studentID << " removed" << endl;
			return;
		}
	} 
	cout << "Error - Student with ID " << studentID << " not found." << endl;
}

void Roster::printAll()
{
	for (int i = 0; i < index; ++i) {
		if (classRosterArray[i]->GetstudentID() != "invalid") {
			classRosterArray[i]->print();
		}
	}
} // why isn't this printing 

void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i < index; i++) {
		if (classRosterArray[i]->GetstudentID() == studentID) {
			cout << "Average number of days: " << (*(classRosterArray[i]->GetdaysInCourse()) + *(classRosterArray[i]->GetdaysInCourse() + 1) + *(classRosterArray[i]->GetdaysInCourse() + 2)) / 3 << endl;
		}
	}
}					

void Roster::printInvalidEmails()
{
	for (int i = 0; i < index; ++i) {
		string emailAddress = classRosterArray[i]->Getemail();
		if ((emailAddress.find(".") == string::npos) || (emailAddress.find("@") == string::npos) || (emailAddress.find(" ") != string::npos)) {
			cout << "Email: " << emailAddress << " - is invalid" << endl;
		}
	} // this is printing ALL emails instead of invaild ones
} 

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	cout << "Showing students in degree program: " << degreeProgram << endl;
	for (int i = 0; i < index; ++i) {
		if (classRosterArray[i]->GetdegreeProgram() == degreeProgram){
			classRosterArray[i]->Student::print();
		}
	}	
}

Roster::~Roster() {

}

/*E.  Create a Roster class (roster.cpp) by doing the following:

1.  Create an array of pointers, classRosterArray, to hold the data provided in the �studentData Table.�

2.  Create a student object for each student in the data table and populate classRosterArray.

a.  Parse each set of data identified in the �studentData Table.�

b.  Add each student object to classRosterArray.

3.  Define the following functions:

a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.

b.  public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.

c. public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.

d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student�s average number of days in the three courses. The student is identified by the studentID parameter.

e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.


Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
/7

f.  public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type.*/
