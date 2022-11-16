#include "roster.h"


using std::vector;
using std::stringstream;
using std::regex;

const string studentData[] =

        {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jarod,Schupp,jschup3@wgu.edu,21, 22,30,34,43,SOFTWARE"
        };
const int numStudents = 5; //constant for an array

//Parsing method
void Roster::parse(string studentdata)
{

    int rhs = studentdata.find(',');//find the comma, return index
    string sID = studentdata.substr(0, rhs);//extract substring in front of comma

    int lhs = rhs + 1;//move past previous comma
    rhs = studentdata.find(',', lhs);
    string sFName = studentdata.substr(lhs, rhs - lhs);//first name

    lhs = rhs + 1;//continue
    rhs = studentdata.find(',', lhs);
    string sLName = studentdata.substr(lhs, rhs - lhs);//last name

    lhs = rhs + 1; //continue
    rhs = studentdata.find(",", lhs);
    string sEmail = studentdata.substr(lhs, rhs -lhs);

    lhs = rhs + 1; //continue
    rhs = studentdata.find(",", lhs);
    int sAge = stoi(studentdata.substr(lhs, rhs -lhs));

    lhs = rhs + 1; //continue
    rhs = studentdata.find(",", lhs);
    int d1 = stod(studentdata.substr(lhs, rhs-lhs));//first number of days

    lhs = rhs + 1; //continue
    rhs = studentdata.find(",", lhs);
    int d2 = stod(studentdata.substr(lhs, rhs-lhs));

    lhs = rhs + 1; //continue
    rhs = studentdata.find(",", lhs);
    int d3 = stod(studentdata.substr(lhs, rhs-lhs));

    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);

    double p[3];
    for (int i = 0; i < 3; i++)
    {
        lhs = rhs + 1;
        rhs = studentdata.find(",", lhs);
        p[i] = stod(studentdata.substr(lhs, rhs - lhs)); //stoi?
    };

    add(sID, sFName, sLName, sEmail, sAge, d1, d2, d3, DegreeType::SECURITY);

}
/*
Roster** Roster::getStudents() {
    return Roster::numStudents;
} // POSSIBLE REMOVEABLE */

//Add Method
void Roster::add(string sID, string sFirstName, string sLastName, string sEmail, int sAge, int sDay1, int sDay2, int sDay3, DegreeType dt){
    int dayArray[3] = {sDay1, sDay2, sDay3};
    students[++lastIndex] = new Student(sID, sFirstName, sLastName, sEmail, sAge, dayArray, dt);
    cout << "Student added to class roster at row " << lastIndex + 1 << endl;
}

//Print All Method
void Roster::printAll() {
    Student::printHeader(); //Prints header for columns/rows
    for (int i = 0; i <= Roster::lastIndex; i++)
        Roster::students[i]->print(); //Display all students
}

//Display students by Degree
void Roster::printByDegreeType(DegreeType dt) {
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
        if (Roster::students[i]->getDegreeType() == dt)students[i]->print();
}

void Roster::printInvalidEmails()
{
    bool any = false; //assume no ivalid emails
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string email = (students[i]->getEmail());
        if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos))
        {
            any = true;
            cout << email << ":" << students[i]->getFirstName() << std::endl; //prints invalid email
        }
    }
    if (!any) cout << "NONE" << std::endl; //prints if no invalid IDs
}

void Roster::printAverageDays(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (students[i]->getID()==studentID)
        {
            cout << studentID << ":";
            cout << (students[i]->getDays()[0]+
                     students[i]->getDays()[1]+
                     students[i]->getDays()[2])/3 << std::endl;
        }
    }
}

bool Roster::removeStudentByID(string studentID)
//takes student id for student to be removed as param
{
    bool success = false; //assume student does not exist
    for (int i=0; i <= Roster::lastIndex; i++)
        //use lastIndex since index may change
    {
        if (students[i]->getID() == studentID)
        {
            success = true;//found student
            if (i < numStudents - 1)
            {
                Student* temp = students[i];//swaps places with last student
                students[i] = students[numStudents - 1];//moves pointer not data in memory
                students[numStudents - 1] = temp;
            }
            Roster::lastIndex--;//last student is hidden but not destroyed
        }
    }
    if (success)
    {
        cout << studentID << " removed from roster." << std::endl << std::endl;
        this->printAll();//display all students except removed students
    }
    else cout << studentID << " not found." << std::endl << std::endl;;
    return 0;
}
//Destructor
Roster::~Roster()
{
    cout << "Destructor called!" << std::endl << std::endl;
    for (int i=0; i < numStudents; i++)
    {
        cout << "Removing student #" << i + 1 << std::endl;
        delete students[i];
        students[i] = nullptr;
    }
}

Roster **Roster::getStudents() {
    return nullptr;
}
