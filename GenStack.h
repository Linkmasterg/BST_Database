
#ifndef GENSTACK_H
#define GENSTACK_H


/*
Geoffrey Hughes
002306123
ghughes@chapman.edu
CPSC 350-02
Assignment 3: Syntax Checker
*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

template <class T>

class GenStack {
	
	public:

		GenStack(); 				// Default constructor
		GenStack(int max_size); 	// Overload constructor
		~GenStack(); 				// Destructor

		void push(T d);
		T pop();
		T peek();

		bool is_full();
		bool is_empty();

		int get_size();
		void set_size(int new_size);
		

	private:


		int size;
		int top;

		T* my_array;
};


#endif //GENSTACK_H
