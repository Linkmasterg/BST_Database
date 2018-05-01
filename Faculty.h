

#ifndef Faculty_H
#define Faculty_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include <vector>

#include "Person.h"

#include "BST.h"




using namespace std;

class Faculty : public Person
{

public:


	Faculty();
	Faculty(int new_ID);
	~Faculty();

	void add_advisee(int new_advisee);
	vector<int> get_advisees();


	friend ostream& operator<<(ostream& os, Faculty& f);


private:

	vector<int> advisees;

};






#endif //Faculty_H