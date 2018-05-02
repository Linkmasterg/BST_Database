
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

	Faculty::Faculty(string new_name, int new_ID, string new_level, string new_department)
	{
		set_name(new_name);
		set_ID(new_ID);
		set_level(new_level);
		set_subject(new_department);
	}

	Faculty::Faculty(string new_name, int new_ID, string new_level, string new_department, vector<int> new_advisees)
	{
		set_name(new_name);
		set_ID(new_ID);
		set_level(new_level);
		set_subject(new_department);

		for (int i = 0; i < new_advisees.size(); ++i)
		{
			add_advisee(new_advisees[i]);
		}
	}

	Faculty::~Faculty()
	{

	}


	void Faculty::add_advisee(int new_advisee)  
	{
		advisees.push_back(new_advisee);
	}

	void Faculty::remove_advisee(int rm_advisee)
	{
		for (int i = 0; i < get_advisees().size(); ++i)
		{
			if (get_advisees()[i] == rm_advisee)
			{
				advisees.erase(advisees.begin() + i);
			}
		}
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




