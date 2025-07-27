#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>

template <typename T>
class Array
{
	private:
	public:
		T*	_array;
		int	_size;

		Array(void); //void constructor
		Array(unsigned int n); // Creates an array of n elements initialized by default.
		Array(const Array& other); //copy construct
		Array &operator=( const Array& other); //copy assignment
		~Array(); //destructor

		//....
		T& operator[](int); //[]operator overload (indexing into array)

		int	size(void) //returns length of current array

		class IndexOutOfBounds : public std::exception 
		{
			public:
				const char * what(void) const throw();
		};

};

 //void constructor
template <typename T>
Array<T>::Array(void)
{
	std::cout << "(Array) Default constructor\n";
	_array = NULL;
	_size = 0;
}


template <typename T>
Array<T>::Array(unsigned int n) // Creates an array of n elements initialized by default.
{
	std::cout << "(Array) uint constructor\n";
	_array = new T[n];
}

//copy construct
template <typename T>
Array<T>::Array(const Array& other)
{
	std::cout << "(Array) copy constructor\n";
	this->_size = other._size;
	_array = new T[size];
	for (int i = 0; i < _size; i++)
		this->_array[i] = other._array[i];
}

 //copy assignment
template <typename T>
Array<T> &Array<T>::operator=( const Array& other)
{
	std::cout << "(Array) copy assignment\n";
	if (this != *other)
	{
		this->_size = other._size;
		_array = new T[size];
		for (int i = 0; i < _size; i++)
			this->_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
int Array<T>::size(void) //returns length of current array
{
	return (this->_size);
}

template <typename T>
const char* Array<T>::IndexOutOfBounds::what(void) const throw()
{
	   return ("(Array<T>) Index out of bounds!\n");
}

template <typename T>
T& Array<T>::operator[](int index)
{
    if (index >= thos->_size) {
        throw IndexOutOfBounds();
    }
    return _array[index];
}

#endif