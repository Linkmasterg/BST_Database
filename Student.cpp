
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "Student.h"

using namespace std;



Student::Student()
{
	set_name("Jr. Null");
	set_ID(rand() % 5001);
	set_level("Freshman");
	set_subject("Math");
	set_GPA(3.42);
	set_advisor(6969);

}


Student::Student(int new_ID)
{
	set_name("Dr. Null");
	set_ID(new_ID);
}

Student::~Student() 
{


}

void Student::print_info()
{
	cout << "Student Name: " << get_name();
	cout << "ID #: " << get_ID();
	cout << "Level: " << get_level();
	cout << "Major: " << get_subject();
	cout << "GPA: " << get_GPA();
	cout << "Advisor ID #: " << get_advisor();

}





double Student::get_GPA()
{
	return GPA;
}

void Student::set_GPA(double new_GPA)
{
	GPA = new_GPA;
}

int Student::get_advisor()
{
	return advisor;
}

void Student::set_advisor(int new_advisor)
{
	advisor = new_advisor;
}


ostream& operator<<(ostream& os, Student& s) 
{  
    os << "Student Name: " << s.get_name() << endl
	<< "ID #: " << s.get_ID() << endl
	<< "Level: " << s.get_level() << endl
	<< "Major: " << s.get_subject() << endl
	<< "GPA: " << s.get_GPA() << endl
	<< "Advisor ID #: " << s.get_advisor() << endl;
    return os;  
}  


