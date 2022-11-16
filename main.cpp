#include "DegreeType.h"
#include "roster.h"
#include <iostream>

using namespace std;

int main(){

    cout << "C867" << endl
         << "C++" << endl
         << "010581471" << endl
         << "Jarod Schupp" << endl;

    const string studentData[] =

            {
                    "A1, John, Smith,John19 89@gmail.com, 20,30,35,40, SECURITY",
                    "A2, Suzan, Erickson,Erickson_1990@gmail.com, 19,50,30,40, NETWORK",
                    "A3, Jack, Napoli,The_lawyer99yahoo.com, 19,20,40,33, SOFTWARE",
                    "A4, Erin, Black,Erin.black@comcast.net, 22,50,58,40, SECURITY",
                    "010581471, Jarod, Schupp,jschup3@wgu.edu, 21, 20, 10, 30, SOFTWARE"
            };
    const int studentDataTable = 5;
    Roster roster;

    for (int i = 0; i < studentDataTable; i++) roster.parse(studentData[i]);
    cout << "Displaying all students:" << endl;
    roster.printAll();
    cout << endl;

    cout << "Displaying all software students:" << endl;
    roster.printByDegreeType(DegreeType::SECURITY);
    cout << endl;


    cout << "Displaying invalid email addess: " << endl;
    roster.printInvalidEmails();
    cout << std::endl;


    cout << "Displaying average days per class:" << endl;
    for (int i = 0; i < studentDataTable; i++)
    {
        roster.printAverageDays(roster.students[i]->getID());
    }
    cout << endl;


    cout << "Remove student A3." << endl;
    roster.removeStudentByID("A3");
    cout << endl;


    cout << "Remove student A3." << endl;
    roster.removeStudentByID("A3");
    cout << endl << endl;

    return 0;
}