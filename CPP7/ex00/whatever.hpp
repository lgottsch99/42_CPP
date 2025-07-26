
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

/* Swaps the values of two given parameters. Does not return anything.
*/
template <typename T> 
void swap(T &x, T &y) 
{
	T tmp = x;

	x = y;
	y = tmp;
}

/* Compares the two values passed as parameters and returns the smallest one. 
If they are equal, it returns the second one.
*/
template <typename T> 
T& min(T &x, T &y) 
{
	if (x == y)
		return y;
	else if (x < y)
		return x;
	return y;
}

/* Compares the two values passed as parameters and returns the greatest one. 
If they are equal, it returns the second one.
*/
template <typename T> 
T& max(T &x, T &y) 
{
	if (x == y)
		return y;
	else if (x < y)
		return y;
	return x;
}


#endif