
#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib> //size_t
#include <iostream>

/* 
The first parameter is the address of an array.
The second one is the length of the array.
The third one is a function that will be called on every element of the array.

No need to overload -> since T is typename, if const int is passed all T become const int!
*/
template <typename T> 
void iter(T *array, size_t len, void (*func)(T&))
{
	//iterate thru array and apply function z on each
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}


//example function to pass as 3. param
template <typename T>
void print_array(T& a)
{
	std::cout << a << "\n";
}

#endif