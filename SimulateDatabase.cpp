

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "BST.h"
#include "BST.cpp"

#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include "SimulateDatabase.h"


using namespace std;

SimulateDatabase::SimulateDatabase()
{

}

SimulateDatabase::~SimulateDatabase()
{


}


void SimulateDatabase::Run()
{

	for (int i = 0; i < 5; ++i)
	{
		masterStudent.insert(Student());
		masterFaculty.insert(Faculty());
	}


	exit_now = false;
	user_input_int = -1;
	user_input_string = "";



	while (!exit_now)
	{

		cout << "What would you like to do?" << endl <<
				"[1] Print all students and their information" << endl <<
				"[2] Print all faculty and their information" << endl <<
				"[3] Find and display student information given the students id" << endl <<
				"[4] Find and display faculty information given the faculty id" << endl <<
				"[5] Given a student’s id, print the name and info of their faculty advisor" << endl <<
				"[6] Given a faculty id, print ALL the names and info of his/her advisees" << endl <<
				"[7] Add a new student" << endl <<
				"[8] Delete a student given the id" << endl <<
				"[9] Add a new faculty member" << endl <<
				"[10] Delete a faculty member given the id" << endl <<
				"[11] Change a student’s advisor given the student id and the new faculty id" << endl <<
				"[12] Remove an advisee from a faculty member given the ids" << endl <<
				"[13] Rollback" << endl <<
				"[14] Exit" << endl <<
				">";



		cin >> user_input_int;


		if (user_input_int == 1)
		{
			case_1();
		}
		else if (user_input_int == 2)
		{
			case_2();
		}
		else if (user_input_int == 3)
		{
			case_3();
		}
		else if (user_input_int == 4)
		{
			case_4();
		}
		else if (user_input_int == 5)
		{
			case_5();
		}



		else if (user_input_int == 14)
		{
			exit_now = true;
		}


	}


}





void SimulateDatabase::case_1()
{
	masterStudent.print_tree(masterStudent.get_root());
}

void SimulateDatabase::case_2()
{
	masterFaculty.print_tree(masterFaculty.get_root());
}

void SimulateDatabase::case_3()
{
	cout << "Please enter the student's ID #: ";
	cin >> user_input_int;

	Student temp = Student(user_input_int);

	if (masterStudent.find(temp)->key.get_ID() == -1)
	{
		cout << endl;
	}
	else
	{
		cout << endl << masterStudent.find(temp)->key << endl;
	}
}

void SimulateDatabase::case_4()
{
	cout << "Please enter the faculty's ID #: ";
	cin >> user_input_int;

	Faculty temp = Faculty(user_input_int);

	if (masterFaculty.find(temp)->key.get_ID() == -1)
	{
		cout << endl;
	}
	else
	{
		cout << endl << masterFaculty.find(temp)->key << endl;
	}
}

void SimulateDatabase::case_4_with_ID(int faculty_ID)
{
	Faculty temp = Faculty(faculty_ID);

	if (masterFaculty.find(temp)->key.get_ID() == -1)
	{
		cout << endl;
	}
	else
	{
		cout << endl << masterFaculty.find(temp)->key << endl;
	}
}

void SimulateDatabase::case_5()
{
	cout << "Please enter the student's ID # to display their advisor's information: ";
	cin >> user_input_int;

	Student temp = Student(user_input_int);

	if (masterStudent.find(temp)->key.get_ID() == -1)
	{
		cout << endl;
	}
	else		
	{
		case_4_with_ID(masterStudent.find(temp)->key.get_advisor());
	}
}


