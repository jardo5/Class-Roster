#include <iostream>
#include <iomanip>
#include "DegreeType.h"

using std::string;
using std::cout;
using std::endl;
using std::left;
using std::setw;

class Student {
public:
    const static int daysArraySize = 3; // 3 Course Lengths
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int days[daysArraySize];
    DegreeType degreeType; //from DegreeType.h

public:
    Student();
    Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeType degreeType);
    ~Student();

    //getters
    string getID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    const int* getDays();
    DegreeType getDegreeType();

    //setters
    void setID(string ID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDays(const int days[]);
    void setDegreeType(DegreeType dt);

    static void printHeader();

    void print();
};

