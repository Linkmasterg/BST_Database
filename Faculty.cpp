
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "Faculty.h"
#include "BST.h"
#include "BST.cpp"


using namespace std;

	Faculty::Faculty()
	{

	}

	Faculty::Faculty(int new_ID)
	{
		set_ID(new_ID);
	}

	Faculty::~Faculty()
	{

	}


	ostream& operator<<(ostream& os, Faculty& f)
	{
   		os << "Faculty Name: " << f.get_name() << endl
		<< "ID #: " << f.get_ID() << endl
		<< "Level: " << f.get_level() << endl
		<< "Department: " << f.get_subject() << endl
		<< "Advisees: " << endl;

		return os;
	}