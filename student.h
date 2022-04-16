// file name student.h
// Author Mohamed Roble
// Date 09/12/2019
#pragma once
#include <string>
#include "degree.h"
using std::string;

class Student//This class represents a Student
{
public://put this up top so everyone can see it :-)
	const static int daysArraySize = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int days[daysArraySize];//days will be an array of size 3
	DegreeType dtype;//Put this HERE - there are virtual methods implying its existence, and you cannot create a Student object anyway
public://public items are visible everywhere in the application
	Student();//empty constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[]);//full constructor-does not include degree type, though - subclasses will do this

	//getters for each instance field
	string getStudentID();
	string getfirstName();
	string getlastName();
	string getemailAddress();
	int getage();
	int* getDays();
	virtual DegreeType getDegreeType() = 0;//VIRTUAL; cannot instantiate a Student object

	//the setters
	void setStudentID(string studentID);
	void setfirstName(string firstName);
	void setlastName(string lastName);
	void setemailAddress(string emailAddress);
	void setage(int age);
	void setDays(double days[]);
	virtual void print() = 0;

	//The destructor
	~Student();
};
