// file name roster.h
// Author Mohamed Roble
// Date 09/12/2019
#pragma once
#include <string>
#include <iostream>
#include "student.h"

//Roster stores a collection of Students
class Roster {
private:
	int lastIndex;//index of last student in roster - so this also effectively records how many entries are currently in the roster
	int capacity;//The maximum size of the roster
	Student** classRosterArray;//students is an array of pointers to students; so, **
public:
	Roster();//empty constructor creates roster & initializes all fields to default values, like "",0,nullptr
	Roster(int capacity);//this constructor does same as above, but sets max size
	
	Student* getStudentAt(int index);
	void parseThenAdd(string datarow);//parses the strings, creates the Student objects, and adds them to the roster
	void add(string sID, string sfirstName, string slastName, string semailAddress, int sage, int sd1, int sd2, int sd3, DegreeType sd);//Called at the end of the parsing routine; not from main()
	void print_All();//prints all students in roster using each student's print() method
	bool remove(string studentID);//removes a student based on its ID
	void printDaysInCourse(string studentID);//Prints some student's average day

	void printInvalidEmails();//Locates and prints negative days
	void printByDegreeProgram(DegreeType b);//Prints all degrees of the specified type.
	~Roster();//Destructor destroys the roster, releasing any resources it requested dynamically
};
