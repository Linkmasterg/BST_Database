#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "tree_node.h"

using namespace std;


template <class T>
tree_node<T>::tree_node()
{

	left = NULL;
	right = NULL;
}

template <class T>
tree_node<T>::tree_node(T k)
{
	key = k;
	left = NULL;
	right = NULL;
}

template <class T>
tree_node<T>::~tree_node()
{
	// build some character - may or may not be in the book!
}
