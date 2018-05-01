
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "Faculty.h"

#include "BST.cpp"



using namespace std;

	Faculty::Faculty()
	{
		set_name("DR. NULL");
		set_ID(5001 + (rand() % 5000));
		set_level("Professor");
		set_subject("Mathematics");
		add_advisee(1017);
		add_advisee(3609);
	}

	Faculty::Faculty(int new_ID)
	{
		set_ID(new_ID);
	}

	Faculty::~Faculty()
	{

	}


	void Faculty::add_advisee(int new_advisee)  
	{
		advisees.push_back(new_advisee);
	}

	vector<int> Faculty::get_advisees()  
	{
		return advisees;
	}






	ostream& operator<<(ostream& os, Faculty& f)
	{

   		os << "Faculty Name: " << f.get_name() << endl
		<< "ID #: " << f.get_ID() << endl
		<< "Level: " << f.get_level() << endl
		<< "Department: " << f.get_subject() << endl
		<< "Advisees: ";

		for (int i = 0; i < f.get_advisees().size(); ++i)
		{
			os << f.get_advisees()[i] << " ";
		}

		os << endl;
		return os;
	}