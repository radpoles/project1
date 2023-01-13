#pragma once

class Roster {

public:

	int index = 0;

	Student* classRosterArray[5]; //storage for five Student* containers, each representing one studentData entry

	void parse(string);

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);

	void remove(string studentID);

	void printAll();

	void printAverageDaysInCourse(string studentID);

	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram degreeProgram);

	~Roster(); // I don't know if this is right at all ?
};
