#pragma once
#include <vector>
#include <cstring>
#include <string.h>
#include <vector>
#include <sstream>
#include <regex>

#include "student.h"

class Roster {
public:
    int lastIndex = -1; //Starting below 0
    const static int numStudents = 5;

    //initialization
    Student* students[numStudents] = {nullptr, nullptr, nullptr, nullptr, nullptr}; //students == classRosterArray

public:
    //Parsing method
    void parse(string row);

    //E3a
    void add(string sID,
             string sFName,
             string sLName,
             string sEmail,
             int sAge,
             int d1,
             int d2,
             int d3,
             DegreeType dt);

    bool removeStudentByID(string studentID); //E3b
    void printAll(); //E3c
    void printAverageDays(string studentID); //E3d
    void printInvalidEmails(); //E3e
    void printByDegreeType(DegreeType dt); //E3f

    ~Roster();
};
