#include "roster.h"
#include <string>


void Roster::parse(string studentdata)//parses each row
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

    DegreeType dt  = SECURITY;

    if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'E') dt = SECURITY;
    else if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'O') dt = SOFTWARE;
    else if (studentdata.at(lhs) == 'N') dt = NETWORK;

    add(sID, sFName, sLName, sEmail, sAge, d1, d2, d3, dt);

}

//Add Method
void Roster::add(string studentID, string fName, string lName, string email, int age, int d1, int d2, int d3, DegreeType dt)
{
    int darr[3] = {d1, d2, d3};

    classRosterArray[++lastIndex] = new Student(studentID, fName, lName, email, age, darr, dt);
}

//Print All Method
void Roster::printAll() {
    Student::printHeader(); //Prints header for columns/rows
    for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();//Display all classRosterArray
}

//Display classRosterArray by Degree
void Roster::printByDegreeType(DegreeType dt) {
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeType() == dt) classRosterArray[i]->print();
    }
    cout << std::endl;
}

void Roster::printInvalidEmails()
{
    bool any = false; //assume no ivalid emails
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string email = (classRosterArray[i]->getEmail());
        if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos))
        {
            any = true;
            cout << email << ":" << classRosterArray[i]->getFirstName() << std::endl; //prints invalid email
        }
    }
    if (!any) cout << "NONE" << std::endl; //prints if no invalid IDs
}

void Roster::printAverageDays(string studentID)
{
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID()==studentID)
        {
            cout << studentID << ":";
            cout << (classRosterArray[i]->getDays()[0]+
                     classRosterArray[i]->getDays()[1]+
                     classRosterArray[i]->getDays()[2])/3 << std::endl;
        }
    }
}

bool Roster::removeStudentByID(string studentID)
//takes student id for student to be removed as param
{
    bool success = false; //assume student does not exist
    for (int i = 0; i <= Roster::lastIndex; i++)
        //use lastIndex since index may change
    {
        if (classRosterArray[i]->getID() == studentID) {
            success = true;//found student
            if (i < numclassRosterArray - 1) {
                Student *temp = classRosterArray[i];//swaps places with last student
                classRosterArray[i] = classRosterArray[numclassRosterArray - 1];//moves pointer not data in memory
                classRosterArray[numclassRosterArray - 1] = temp;
            }
            Roster::lastIndex--;//last student is hidden but not destroyed
        }
    }
    if (success) {
        cout << studentID << " removed from roster." << std::endl << std::endl;
        this->printAll();//display all classRosterArray except removed classRosterArray
    }
    else cout << studentID << " not found." << std::endl << std::endl;;
    return 0;
};
//Destructor
Roster::~Roster()
{
    cout << "Calling Destructor.." << endl << endl;
    for (int i=0; i < numclassRosterArray; i++)
    {
        cout << "Removing student #" << i + 1 << endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
