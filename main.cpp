// SAPA Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "student.h"
#include "roster.h"

using namespace std;

/*F.  Demonstrate the program’s required functionality by adding a main() function in main.cpp, which will contain the required function calls to achieve the following results:

1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.

2.  Create an instance of the Roster class called classRoster.

3.  Add each student to classRoster.

4.  Convert the following pseudo code to complete the rest of the  main() function:

classRoster.printAll();

classRoster.printInvalidEmails();

 

//loop through classRosterArray and for each element:

classRoster.printAverageDaysInCourse(current_object's student id);



Note: For the current_object's student id, use an accessor (i.e., getter) for the classRosterArray to access the student id.



classRoster.printByDegreeProgram(SOFTWARE);

classRoster.remove("A3");

classRoster.printAll();

classRoster.remove("A3");

//expected: the above line should print a message saying such a student with this ID was not found.

5.  Implement the destructor to release the memory that was allocated dynamically in Roster.*/

const string studentData[] =
{
 "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Caroline,Langridge,cmlangridge99@gmail.com,22,10,10,120,SOFTWARE"
};																		

int main()
{
    cout << "C867 Scripting & Programming: Applications" << endl;
    cout << "Language Used: C++" << endl;
    cout << "Caroline Langridge" << endl;
    cout << "ID: 001470808" << endl << endl;

    Roster classRoster;

    for (int i = 0; i < 5; ++i) {
        classRoster.parse(studentData[i]);
    }

    cout << "Displaying all students:" << endl;

    classRoster.printAll();

    cout << endl << "Displaying invalid emails:" << endl;

    classRoster.printInvalidEmails();
    cout << endl;
    
    cout << "Displaying average days in course:" << endl;

    for (int i = 0; i < 5; ++i) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetstudentID());
    }

    cout << endl;

    classRoster.printByDegreeProgram(SOFTWARE); // this is displaying as the index instead of SOFTWARE in the final output

    cout << endl;

    cout << "Removing A3" << endl;

    classRoster.remove("A3");

    classRoster.printAll(); // this is not printing anything

    cout << "Removing A3 again" << endl;

    classRoster.remove("A3"); 


    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
