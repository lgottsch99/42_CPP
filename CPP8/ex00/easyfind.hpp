
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <string>

//eg array of int: 1st param (container), 2nd param (number to search for)
template <typename T>
typename T::iterator easyfind(T &t, int i)
{
	typename T::iterator first = t.begin();
	typename T::iterator last = t.end();

	return (std::find(first, last, i)); //if not found returns iterator at t.end()
}

#endif