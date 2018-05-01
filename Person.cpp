
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "Person.h"


using namespace std;


Person::Person()
{
	int x = rand();

	ID = rand();
}

Person::~Person()
{


}



int Person::get_ID() const
{
	return (this->ID);
}
// make these virtual void = 0?
void Person::set_ID(int new_ID)
{
	this->ID = new_ID;
}

string Person::get_name()
{
	return name;
}

void Person::set_name(string new_name)
{
	name = new_name;
}


string Person::get_level()
{
	return this->level;
}


void Person::set_level(string new_level)
{
	this->level = new_level;
}


string Person::get_subject()
{
	return subject;
}

void Person::set_subject(string new_subject)
{
	subject = new_subject;
}



bool operator<(const Person& p1, const Person& p2)
{
	return (p1.get_ID() < p2.get_ID());
}

ostream& operator<<(ostream& os, const Person& p) 
{  
    os << p.get_ID() << " ... printing a person class (base class)" << endl;
    return os;  
}  

bool operator==(const Person& p1, const Person& p2)
{
	return (p1.get_ID() == p2.get_ID());
}

bool operator!=(const Person& p1, const Person& p2)
{
	return (p1.get_ID() != p2.get_ID());
}





