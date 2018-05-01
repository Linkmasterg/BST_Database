
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
		set_ID(5001 + (rand() % 5001));
		set_level("Professor");
		set_subject("Mathematics");
		add_advisee(32546);
		add_advisee(123);
	}

	Faculty::Faculty(int new_ID)
	{
		set_ID(new_ID);
	}

	Faculty::~Faculty()
	{

	}


	void Faculty::make_advisee_string(tree_node<int> *node) // In-order traversal
	{
		if (node == NULL)
		{
			return;
		}		

		make_advisee_string(node->left);
		all_the_advisees += to_string(node->key);
		all_the_advisees += " ";
		make_advisee_string(node->right);
	}



	string Faculty::get_advisees()
	{
		make_advisee_string(get_advisees_tree().get_root());
		return all_the_advisees;
	}


	void Faculty::add_advisee(int new_advisee)
	{
		advisees.insert(new_advisee);
	}


	void Faculty::remove_advisee(int remove_this)
	{
		advisees.delete_node(remove_this);
	}


	BST<int> Faculty::get_advisees_tree()
	{
		return advisees;
	}


	ostream& operator<<(ostream& os, Faculty& f)
	{

   		os << "Faculty Name: " << f.get_name() << endl
		<< "ID #: " << f.get_ID() << endl
		<< "Level: " << f.get_level() << endl
		<< "Department: " << f.get_subject() << endl
		<< "Advisees: " << f.get_advisees() << endl;

		f.all_the_advisees = "";

		return os;
	}