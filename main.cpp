#include "roster.h"
#include <iostream>


/*
 * Added new comments
 */

using namespace std;

int main(){

    cout << "C867" << endl
         << "C++" << endl
         << "010581471" << endl
         << "Jarod Schupp" << endl;

    const string studentData[] =
            {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "010581471,Jarod,Schupp,jschup3@wgu.edu,31,22,15,19,SOFTWARE"
            };

    const int studentDataTable = 5;
    Roster roster;

    for (int i = 0; i < studentDataTable; i++) roster.parse(studentData[i]);
    cout << "Displaying all students:" << std::endl;
    roster.printAll();
    cout << std::endl;
    //display all students

    cout << "Displaying all software students:" << std::endl;
    roster.printByDegreeType(SOFTWARE);
    cout << std::endl;
    //display all students in the software degree program

    cout << "Displaying invalid email addess: " << std::endl;
    roster.printInvalidEmails();
    cout << std::endl;
    //display all students with an incorrectly formatted email address

    cout << "Displaying average days per class:" << std::endl;
    for (int i = 0; i < studentDataTable; i++)
    {
        roster.printAverageDays(roster.classRosterArray[i]->getID());
    }
    cout << std::endl;
    //display the average number of days each student spends in 3 classes

    cout << "Remove student A3." << std::endl;
    roster.removeStudentByID("A3");
    cout << std::endl;

    cout << "Remove student A3." << std::endl;
    roster.removeStudentByID("A3");
    cout << std::endl << std::endl;

    return 0;
}