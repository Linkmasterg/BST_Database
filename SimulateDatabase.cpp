

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

		cout << endl << 
				"What would you like to do?" << endl <<
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
		else if (user_input_int == 6)
		{
			case_6();
		}
		else if (user_input_int == 7)
		{
			case_7();
		}
		else if (user_input_int == 8)
		{
			case_8();
		}
		else if (user_input_int == 9)
		{
			case_9();
		}
		else if (user_input_int == 10)
		{
			case_10();
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

void SimulateDatabase::case_3_with_student_ID(int student_ID)
{
	Student temp = Student(student_ID);

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

void SimulateDatabase::case_4_with_faculty_ID(int faculty_ID)
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
		case_4_with_faculty_ID(masterStudent.find(temp)->key.get_advisor());
	}
}

int SimulateDatabase::case_5_with_student_ID(int student_ID)
{
	Student temp = Student(student_ID);

	if (masterStudent.find(temp)->key.get_ID() == -1)
	{
		cout << endl;
	}
	
	return masterStudent.find(temp)->key.get_advisor();
}

void SimulateDatabase::case_6()
{
	cout << "Please enter the faculty's ID # to display ALL their advisees' information: ";
	cin >> user_input_int;

	Faculty temp = Faculty(user_input_int);

	if (masterFaculty.find(temp)->key.get_ID() == -1)
	{
		cout << endl;
	}
	else		
	{
		for (int i = 0; i < masterFaculty.find(temp)->key.get_advisees().size(); ++i)
		{
			case_3_with_student_ID(masterFaculty.find(temp)->key.get_advisees()[i]);
		}
	}


}

void SimulateDatabase::case_7()
{
	string new_name = "";
	int new_ID = -1;
	string new_level = "";
	string new_major = "";
	double new_GPA = 0.0;
	int new_advisor = -1;

	bool duplicates = true;

	cout << "Please enter the following info to add a new student..." << endl;
	cout << "Student Name: ";
	cin >> ws;
	getline(cin, new_name);

	while (duplicates)
	{
		cout << "Student ID # [1 - 5000]: ";
		cin >> new_ID;

		Student temp = Student(new_ID);

		if (masterStudent.contains(temp))
		{
			cout << "That student ID # is already in use." << endl;
		}

		if (!masterStudent.contains(temp))
		{
			duplicates = false;
		}
	}

	cout << "Student level [Freshman, Sophomore, Junior, Senior]: ";
	cin >> new_level;

	cout << "Student Major: ";
	cin >> ws;
	getline(cin, new_major);

	cout << "Student GPA: ";
	cin >> new_GPA;

	cout << "Advisor ID #: ";
	cin >> new_advisor;

	masterStudent.insert(Student(new_name, new_ID, new_level, new_major, new_GPA, new_advisor));
}


void SimulateDatabase::case_8()
{
	int student_ID;
	int faculty_ID;

	cout << "Please enter the student's ID # to delete them from the database: ";
	cin >> student_ID;

	while (!masterStudent.contains(masterStudent.find(student_ID)->key))
	{
		cout << "The database does not contain a student under that ID #. Please try again:";
		cin >> ws;
		cin >> student_ID;
	}

	faculty_ID = case_5_with_student_ID(student_ID);
	Faculty temp_f = Faculty(faculty_ID);

	masterFaculty.find(temp_f)->key.remove_advisee(student_ID);



	Student temp_s = Student(student_ID);
	masterStudent.delete_node(temp_s);
}


void SimulateDatabase::case_9()
{

	string new_name = "";
	int new_ID = -1;
	string new_level = "";
	string new_department = "";
	int new_advisee = -1;

	bool duplicates = true;

	cout << "Please enter the following info to add a new faculty..." << endl;
	cout << "Faculty Name: ";
	cin >> ws;
	getline(cin, new_name);

	while (duplicates)
	{
		cout << "Faculty ID # [5001 - 10000]: ";
		cin >> new_ID;

		Faculty temp = Faculty(new_ID);

		if (masterFaculty.contains(temp))
		{
			cout << "That faculty ID # is already in use." << endl;
		}

		if (!masterFaculty.contains(temp))
		{
			duplicates = false;
		}
	}

	cout << "Faculty level [Professor, Assistant Professor, TA, etc...]: ";
	cin >> ws;
	getline(cin, new_level);

	cout << "Faculty Department: ";
	cin >> ws;
	getline(cin, new_department);

	bool not_finished = true;
	vector<int> new_advisees;

	while (not_finished)
	{
		cout << "Faculty advisee(s) [Enter existing Student of ID # 1 - 5000]" << endl;
		cout << "[enter 0 to finish]: ";
		cin >> new_advisee;

		if (new_advisee == 0)
		{
			not_finished = false;
		}

		else
		{
			new_advisees.push_back(new_advisee);
		}
	}

	Faculty new_faculty = Faculty(new_name, new_ID, new_level, new_department);
	masterFaculty.insert(new_faculty);

	for (int i = 0; i < new_advisees.size(); ++i)
	{
		masterFaculty.find(new_ID)->key.add_advisee(new_advisees[i]);
	}
}

void SimulateDatabase::case_10()
{


	int faculty_ID;

	vector<int> students_to_reassign;


	cout << "Please enter the faculty's ID # to delete them from the database: ";
	cin >> faculty_ID;

	while (!masterFaculty.contains(masterFaculty.find(faculty_ID)->key))
	{
		cout << "The database does not contain a faculty member under that ID #. Please try again:";
		cin >> ws;
		cin >> faculty_ID;
	}

	students_to_reassign = masterFaculty.find(faculty_ID)->key.get_advisees();
	masterFaculty.delete_node(masterFaculty.find(faculty_ID)->key);

	if (students_to_reassign.size() != 0)
	{
		cout << "With faculty member deleted, you must reassign " << students_to_reassign.size() << " students" << endl;
	}

	for (int i = 0; i < students_to_reassign.size(); ++i)
	{
		cout << "Enter existing Faculty ID # for student ID #" << students_to_reassign[i] << ": ";
		cin >> faculty_ID;
		masterStudent.find(students_to_reassign[i])->key.set_advisor(faculty_ID);
		masterFaculty.find(faculty_ID)->key.add_advisee(students_to_reassign[i]);
	}
}


void SimulateDatabase::case_11()
{

}

// TODO: file I/O, Rollback (stack of 2x BST), comments, READ_ME, Makefile, *polish*






