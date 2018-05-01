#ifndef Faculty_H
#define Faculty_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "Person.h"

using namespace std;

class Faculty : public Person
{


	Faculty();
	Faculty(int new_ID);
	~Faculty();



};






#endif //Faculty_H