#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeProgram;

public:
	void SetstudentID(string stdID);
	void SetfirstName(string fName);
	void SetlastName(string lName);
	void Setemail(string eml);
	void Setage(int stdage);
	void SetdaysInCourse(int daysInCourse[]);
	void SetdegreeProgram(DegreeProgram dgrProgram);
	string GetstudentID() const;
	string GetfirstName() const;
	string GetlastName() const;
	string Getemail() const;
	int Getage() const;
	int* GetdaysInCourse();
	DegreeProgram GetdegreeProgram();
	void print();

	Student(string stdID, string fName, string lName, string eml, int stdAge, int dysInCourse[], DegreeProgram dgrProgram);
};
