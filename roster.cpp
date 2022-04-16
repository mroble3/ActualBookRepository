// file name roster.cpp 
// Author Mohamed Roble
// Date 09/12/2019
#include "roster.h"
#include "student.h"
#include "securitystudent.h"
#include "networkstudent.h"
#include "softwarestudent.h"
using std::cout;
using std::cerr;
//ALWAYS DEFINE THE EMPTY CONSTRUCTOR - IT GETS CALLED BY DEFAULT IF NO OTHER SPECIFIED!
Roster::Roster()//The empty constructor sets to default values
{
	this->capacity = 0;
	this->lastIndex = -1;//Means EMPTY; 0 is a valid index in an array
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)//Sets a max capacity for the roster
{
	this->capacity = capacity;
	this->lastIndex = -1;//AGAIN; means empty
	this->classRosterArray = new Student*[capacity];
}

Student * Roster::getStudentAt(int index)
{
	return classRosterArray[index];
}

//modified 08/24/2019
//Calls a separate add() method at the end
void Roster::parseThenAdd(string row)
{
	if (lastIndex < capacity) {
		lastIndex++;
		DegreeType degreeType = SECURITY;
		//Test if network or security or software - cannot create anything of type 'Student'
		//Note this is a big fat cheat - first letter of ID is always F or N     ;-) (wink)
		//if (row[0] == 'S1') DegreeType = SECURITY;
		//if (row[0] == 'N') DegreeType = NETWORK;
		//if (row[0] == 'S2') DegreeType = SOFTWARE;
		//else //leave
		//{
		//	cerr << "INVALID DEGREE TYPE!  EXITING NOW!\n";
		//	exit(-1);
		//}

		//We will parse through each 'student string' delimiting on the COMMA
		//We will then extract each subtring and store them in temp variables
		//Get the ID, assign it to a temporary holding variable
		
		int rhs = row.find(",");
		string sID = row.substr(0, rhs);

		//read firstName
		int lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string sfirstName = row.substr(lhs, rhs - lhs);

		//read lastName
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string slastName = row.substr(lhs, rhs - lhs);

		//read emailAddress
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string semailAddress = row.substr(lhs, rhs - lhs);

		//read age
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int sage = stoi(row.substr(lhs, rhs - lhs));

		// numage = int, // We were working on this to fix int problem w/ numage.

		//read each day
		//NOTE THAT EACH DAY MUST BE CONVERTED TO A DOUBLE
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int day1 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int day2 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int day3 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string strDegreeType = row.substr(lhs, rhs - lhs);
		if (strDegreeType == "SECURITY")
			degreeType = SECURITY;
		if (strDegreeType == "NETWORK")
			degreeType = NETWORK;
		if (strDegreeType == "SOFTWARE")
			degreeType = SOFTWARE;
		//NOW JAM THE INFO IN HERE - NOTE add() WANTS THE DAYS INDIVIDUALLY, NOT AS AN ARRAY
		//The add() method will create the Security or Network or Software student
		add(sID, sfirstName, slastName, semailAddress, sage, day1, day2, day3, degreeType);
	} 
	else //leave - we have exceeded capacity
	{
		cerr << "ERROR! LIST HAS EXCEEDED MAXIMUM CAPACITY!\n EXITING NOW!";
		exit(-1);
	}
}

//This method creates the student of proper type, then adds to roster - all parsed values passed in
void Roster::add(string sID, string sfirstName, string slastName, string semailAddress, int sage, int sd1, int sd2, int sd3, DegreeType sd)
{
	//Make an array to get the days into the constructor.
	int StudentDays[Student::daysArraySize];//That's why this is public in Student class
	StudentDays[0] = sd1;
	StudentDays[1] = sd2;
	StudentDays[2] = sd3;
	if (sd == SECURITY) classRosterArray[lastIndex] = new SecurityStudent(sID, sfirstName, slastName, semailAddress, sage, StudentDays, sd);
	if (sd == NETWORK) classRosterArray[lastIndex] = new NetworkStudent(sID, sfirstName, slastName, semailAddress, sage, StudentDays, sd);
	if (sd == SOFTWARE) classRosterArray[lastIndex] = new SoftwareStudent(sID, sfirstName, slastName, semailAddress, sage, StudentDays, sd);
}

void Roster::print_All()//Roll thru the array of students and call print method for each one
{
	//Note this works properly for all THREE security and network and software students; that's run-time polymorphism!
	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}

bool Roster::remove(string ID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == ID) //Student found
		{
			found = true;
			//delete it
			delete this->classRosterArray[i];
			//Move last student to this position - no gaps in array
			//This might be self-assignment, but poses no danger
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;//Roster is one element smaller
		}
	}
	return found;
}

void Roster::printDaysInCourse(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID) //Student found
		{
			found = true;
			int* d = classRosterArray[i]->getDays();
			cout << "Average days of Students " << studentID << " is " << (d[0] + d[1] + d[2]) / 3 << "\n";
		}
	}
	if (!found) cout << "Student not found!\n";
}

//modified 20190824
void Roster::printInvalidEmails()
{
	cout << "Displaying invalid emails:\n";
	bool any = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		any = false;
		string email = classRosterArray[i]->getemailAddress();
		if (email.find("@") == string::npos)
			cout << email << "\n";
		if (email.find(".") == string::npos)
			cout << email << "\n";
		if (email.find(" ") != string::npos)
			cout << email << "\n";
		
	}
	
}

void Roster::printByDegreeProgram(DegreeType b)
{
	//cout << "Printing degrees of type " << degreeTypeStrings[b] << "\n";
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getDegreeType() == b) this->classRosterArray[i]->print();
	}
}

Roster::~Roster()//destroys all the students
{
	for (int i = 0; i <= lastIndex; i++) 
	{
		delete this->classRosterArray[i];//Deletes each student first
	}
	delete classRosterArray;//Deletes the dynamically allocated array of pointers to the students
}

int main() //MAIN - HERE WE GO
{
	cout << "Scripting and Programming Applications C867\n";
	cout << "Programming Language used is C++\n";
	cout << "Student ID: 000000000 Mohamed Roble\n";

	//modified 08/24/2019
	int numStudents = 5;
	//Input is 5 long comma-delimited strings
	const string StudentData[5] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Mohamed,Roble,mroble@email.com,20,15,19,12,SOFTWARE"

	};

	Roster * ros = new Roster(numStudents);//MAKE THE ROSTER
	cout << "Parsing data and adding students:\t";
	for (int i = 0; i < numStudents; i++) 
	{
		ros->parseThenAdd(StudentData[i]);//PARSE EACH LINE, TURN THEM INTO STUDENTS, AND ADD THEM TO ROSTER
	}
	cout << "DONE.\n";
	cout << "Displaying all students:\n";
	ros->print_All();//DISPLAY ALL STUDENTS IN THE ROSTER

	ros->printInvalidEmails();

	cout << "Printing average days for all students:\n";
	for (int i = 0; i < numStudents; i++) {
		ros->printDaysInCourse(ros->getStudentAt(i)->getStudentID());//PRINTS THE AVERAGE DAYS OF SPECIFIED STUDENT
	}
	ros->printByDegreeProgram(SOFTWARE);

	cout << "Removing A3:\n";//REMOVE STUDENT WITH THE SUPPLIED ID
	if (ros->remove("A3")) {
		ros->print_All();
		numStudents--;
	}
	else cout << "Student not found!\n";

	cout << "Removing A3:\n";//REMOVE SAME ITEM TWICE TO CHECK ERROR CONDITION
	if (ros->remove("A3")) ros->print_All();
	else cout << "Student not found!\n";

	delete ros;

	
	system("pause");//NEEDED ONLY TO HOLD CONSOLE WINDOW UP IF USING VSTUDIO
	return 0;//ALL DONE;
}
