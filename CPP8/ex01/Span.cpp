
#include "Span.hpp"

// ----- Exceptions -----------------------

char const *Span::MaxIntReached::what(void) const throw()
{
	return("(Span) EXCEPTION: Max no ints reached! Cannot add more.\n");
}

char const *Span::NotEnoughInt::what(void) const throw()
{
	return("(Span) EXCEPTION: Not enough elements yet!\n");
}

// ----- Constructors -----------------------

//default constr
Span::Span(unsigned int n)
{
	std::cout << "(Span) Default constructor\n";
	_max_int = n;

}

//copy construct
Span::Span(const Span& other)
{
	std::cout << "(Span) Copy constructor\n";
	_max_int = other.getMaxInt();
}

//copy assignment
Span &Span::operator=( const Span& other)
{
	if (this != &other)
	{
		std::cout << "(Span) Copy assignment\n";
		_max_int = other.getMaxInt();	
	}
	return (*this);
}

//destructor
Span::~Span()
{
	std::cout << "(Span) Destructor\n";
}

// ----- Methods -----------------------

unsigned int Span::getMaxInt(void) const
{
	return (_max_int);
}

void	Span::addNumber(int num)
{
	//check if vector already full
	if (_vec.size() == _max_int)
		throw MaxIntReached();
	//if not add number
	_vec.push_back(num);
}

unsigned int	Span::shortestSpan(void)
{
	int shortest_span;
	int span;
	int current;
	int next;
	int init = 0;

	//check if >1 elems tehre
	if (_vec.size() < 2)
		throw NotEnoughInt();
	
	//sort
	std::sort(_vec.begin(), _vec.end());

	//find shortest span
	for (std::vector<int>::iterator it = _vec.begin(); it!= _vec.end() - 1; it++)
	{	
		current = *it;
		next = *(it + 1);
		span = current - next;
		if (span < 0)
			span = span * (-1);
		if (init == 0)
		{	
			shortest_span = span;
			init = 1;
		}
		else if (span < shortest_span)
			shortest_span = span;
	}
	return (shortest_span);
}

unsigned int	Span::longestSpan(void)
{
	int min;
	int max;
	int init = 0;

	//check if >1 elems tehre
	if (_vec.size() < 2)
		throw NotEnoughInt();

	//find min and max
	for (std::vector<int>::iterator it = _vec.begin(); it!= _vec.end(); it++)
	{
		if (init == 0)
		{
			min = *it;
			max = *it;
			init = 1;
		}
		else
		{
			if (*it < min)
				min = *it;
			else if (*it > max)
				max = *it;
		}
	}
	return (max - min);
}


