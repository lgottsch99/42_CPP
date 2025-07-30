
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm> 


class Span
{
	private:
		unsigned int		_max_int;

	public:
		Span(unsigned int n); //default constr
		Span(const Span& other); //copy construct
		Span &operator=( const Span& other); //copy assignment
		~Span(); //destructor

		void			addNumber(int num);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);

		template <typename T> // only template. why?: we might create a span from different existing types of containers
		void			addRange(T start, T end);

		//getset
		unsigned int	getMaxInt(void) const;
		std::vector<int>	_vec; //to actually store ints


		//exceptions
		class MaxIntReached : public std::exception 
		{
			public:
				const char * what(void) const throw();
		};

		class NotEnoughInt : public std::exception 
		{
			public:
				const char * what(void) const throw();
		};
};


/*
implement a member function to add multiple numbers to your Span in a single call.
If you don’t have a clue, study the Containers.  Some member
functions take a range of iterators in order to add a sequence of
elements to the container.

-> a while loop not ok
-> iterators (to different existing Span) as params

*/
template <typename T>
void	Span::addRange(T start, T end) //pass iterators of existing container thta stores ints
{
	//check size of range (if bigger than max int ?)
	if (start == end)
		return ;

	//check size of desired range
	unsigned int rangeSize = std::distance(start, end);
	if (_vec.size() + rangeSize > this->_max_int)
		throw std::runtime_error("Not enough space for range.");

	//insert
	_vec.insert(_vec.end(), start, end);
}

#endif