

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>



#include "SimulateDatabase.h"

int main(int argc, char** argv)
{

	// read in facultyTable and studentTable if they exist into their respective trees,
	// if they do not exist, create new empty trees

	SimulateDatabase theSimulation = SimulateDatabase();
	theSimulation.Run();

	cout << "ayo" << endl;
}