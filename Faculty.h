

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


	friend ostream& operator<<(ostream& os, Faculty& f);



private:


	BST<int> advisees;

};






#endif //Faculty_H