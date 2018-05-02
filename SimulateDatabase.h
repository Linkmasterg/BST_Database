
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "BST.h"

#include "Person.h"
#include "Student.h"
#include "Faculty.h"



class SimulateDatabase
{

public:

	SimulateDatabase();
	~SimulateDatabase();

	void Run();

	void case_1();
	void case_2();
	void case_3();
	void case_3_with_student_ID(int student_ID);
	void case_4();
	void case_4_with_faculty_ID(int faculty_ID);
	void case_5();
	int case_5_with_student_ID(int student_ID);
	void case_6();
	void case_7();
	void case_8();
	void case_9();
	void case_10();
	void case_11();

	void case_14();




	BST<Student> masterStudent;
	BST<Faculty> masterFaculty;

	bool exit_now;
	int user_input_int;
	string user_input_string;

};


