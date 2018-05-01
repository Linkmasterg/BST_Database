

#ifndef Faculty_H
#define Faculty_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "Person.h"

#include "BST.h"




using namespace std;

class Faculty : public Person
{

public:


	Faculty();
	Faculty(int new_ID);
	~Faculty();

	void make_advisee_string(tree_node<int> *node);
	string get_advisees();
	void add_advisee(int new_advisee);
	void remove_advisee(int remove_this);

	BST<int> get_advisees_tree();


	friend ostream& operator<<(ostream& os, Faculty& f);

	string all_the_advisees;

private:


	BST<int> advisees;

};






#endif //Faculty_H