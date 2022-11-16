#include "student.h"

//sets default values. Strings are empty, Integers are 0
Student::Student(){
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < daysArraySize; i++) this->days[i] = 0; //Loops over all 3 "days" and sets to 0.
    this->degreeType = DegreeType::SECURITY; //Defaults to SECURITY
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeType degreeType){
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < daysArraySize; i++) this->days[i] = days[i];
    this-> degreeType = degreeType;
}

//Destructor
Student::~Student() {}

//Getters
string Student::getID() {return this->studentID;}
string Student::getFirstName() {return this->firstName;}
string Student::getLastName() {return this->lastName;}
string Student::getEmail() {return this->email;}
int Student::getAge() {return this->age;}
const int* Student::getDays() {return this->days;}
DegreeType Student::getDegreeType() {return this->degreeType;}

//Setters
void Student::setID(string ID) {this->studentID = ID;}
void Student::setFirstName(string firstName) {this->firstName = firstName;}
void Student::setLastName(string lastName) {this->lastName = lastName;}
void Student::setEmail(string email) {this->email = email;}
void Student::setAge(int age) {this-> age = age;}
void Student::setDays(const int days[]) {
    for (int i = 0; i < daysArraySize; i++) this->days[i] = days[i];
}
void Student::setDegreeType(DegreeType degreeType) {this->degreeType = degreeType;}

//Headers for console
void Student::printHeader() {
    cout << "StudentID\t";
    cout << "First Name\t";
    cout << "Last Name\t";
    cout << "Email\t";
    cout << "Age\t";
    cout << "Days To Complete Each Course\t";
    cout << "Degree Program\t";
    cout << endl;
}

//Print data
void Student::print() {
    cout << this->studentID << '\t';
    cout << this->firstName << '\t';
    cout << this->lastName << '\t';
    cout << this->email << '\t';
    cout << this-age << '\t';
    cout << this->days[0] << '\t';
    cout << this->days[1] << '\t';
    cout << this->days[2] << '\t';
    cout << degreeTypeStrings[(int)this->degreeType];
    cout << endl;
}