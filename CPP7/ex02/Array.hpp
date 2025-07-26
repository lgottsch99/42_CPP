#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>

template <typename T>
class Array
{
	private:
		T* _elements;

	public:
		Array(void); //void constructor
		Array(unsigned int n); // Creates an array of n elements initialized by default.
		Array(const Array& other); //copy construct
		Array &operator=( const Array& other); //copy assignment
		~Array(); //destructor


		const size_t size(void); //returns length of current array

		class IndexOutOfBounds : public std::exception 
		{
			public:
				const char * what(void) const throw();
		};

}

#endif