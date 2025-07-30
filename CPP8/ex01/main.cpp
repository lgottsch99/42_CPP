

#include "Span.hpp"


int main(void)
{
	Span a(3);
	Span b(a);

	a.addNumber(3);
	try
	{
		std::cout << "trying shortest span with 1 member: " <<  a.shortestSpan() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	a.addNumber(15);
	a.addNumber(12);
	try
	{
		a.addNumber(56);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "shortest span: " << a.shortestSpan() << "\n";
	std::cout << "longest span: " << a.longestSpan() << "\n";


	//from subject:
	std::cout << "\n\n------- Main from subject: -------" << "\n\n";

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "\n\n";


	//from subject:
	std::cout << "\n\n------- Trying with 15.000 elems: -------" << "\n\n";
	
	int range = 15000;
	Span  big(range);

	for (int o = 0; o < range; o++)
	{
		big.addNumber(o);
	}

	try
	{
		big.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "shortest span: " << big.shortestSpan() << "\n";
	std::cout << "longest span: " << big.longestSpan() << "\n";
	
	std::cout << "\n\n------- testing range insert: -------" << "\n\n";

	Span c(range);
	c.addRange(big._vec.begin(), big._vec.end());
	std::cout << "shortest span: " << c.shortestSpan() << "\n";
	std::cout << "longest span: " << c.longestSpan() << "\n";


	return 0;
}