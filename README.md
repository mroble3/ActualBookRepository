#ActualBookRepository

To help a university migrate an existing student system to a new platform using C++ language.
--
The program will maintain a current roster of students within a given course.

Student data for the program includes student ID, first name, last name, email address, age, an array of the number of days to complete each course, and degree.

This information can be found in the studentData table below. The program will read a list of five students and use function calls to manipulate data. While parsing the list of data, the program should create student objects using the appropriate subclasses indicated by the degree program. The entire student list will be stored in one array of students called classRosterArray Specific data-related output will be directed to the console.

STUDENT DATA TABLE:

Student ID First Name Last Name Email Age Days in Course Degree A1 John Smith John1989@gm ail.com 20 30, 35, 40 SECURITY A2 Suzan Erickson Erickson_1990@gmailcom 19 50, 30, 40 NETWORK A3 Jack Napoli The_lawyer99yahoo.com 19 20, 40, 33 SOFTWARE A4 Erin Black Erin.black@comcast.net 22 50, 58, 40 SECURITY A5 Random first name Random last name Random email address Random age Number of days to complete 3 courses SOFTWARE

How Data should be inputted:

const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,[randomfirstname],[randomlastname],[randomemailaddress],[randomage], [randomnumberofdaystocomplete3courses],SOFTWARE"
