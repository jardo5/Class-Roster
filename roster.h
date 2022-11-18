#pragma once
#include <stdio.h>

#include "student.h"

class Roster {
public:
    int lastIndex = -1; //Starting below 0
    const static int numclassRosterArray = 5;

    //initialization
    Student* classRosterArray[numclassRosterArray];

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

    void printAll(); //E3c
    void printByDegreeType(DegreeType dt); //E3f
    void printAverageDays(string studentID); //E3d
    void printInvalidEmails(); //E3e
    bool removeStudentByID(string studentID); //E3b
    ~Roster();
};
