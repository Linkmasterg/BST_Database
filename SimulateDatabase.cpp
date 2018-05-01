
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "BST.h"
#include "BST.cpp"

#include "Person.h"
#include "Student.h"
#include "Faculty.h"




using namespace std;


int main(int argc, char** argv)
{


	// read in facultyTable and studentTable if they exist into their respective trees,
	// if they do not exist, create new empty trees


	BST<Student> masterStudent = BST<Student>();
	BST<Faculty> masterFaculty = BST<Faculty>();

	for (int i = 0; i < 5; ++i)
	{
		masterStudent.insert(Student());
		masterFaculty.insert(Faculty());
	}




	bool exit_now = false;
	int user_input_int = -1;
	string user_input_string = "";

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
			masterStudent.print_tree(masterStudent.get_root());
		}

		else if (user_input_int == 2)
		{
			masterFaculty.print_tree(masterFaculty.get_root());
		}

		else if (user_input_int == 3)
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




		else if (user_input_int == 14)
		{
			exit_now = true;
		}

	} // END OF Main while loop












	BST<Person> theBST = BST<Person>();

	for (int i = 0; i < 5; ++i)
	{
		theBST.insert(Person());
	}



	theBST.print_tree(theBST.get_root());

	




	cout << "ayo" << endl;

}