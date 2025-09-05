

#include "Span.hpp"

#include <list>

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
	try
	{
		std::cout << "trying longest span with 1 member: " <<  a.longestSpan() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	a.addNumber(15);
	a.addNumber(12);
	try
	{
		std::cout << "adding 4. elem to span(3): \n";

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
	sp.addNumber(3); //biggest 3-17 = 14
	sp.addNumber(17);//biggest
	sp.addNumber(9); //shortest 9-11 = 2
	sp.addNumber(11); //shortest
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
	c.addRange(big.getVec().begin(), big.getVec().end());
	std::cout << "shortest span: " << c.shortestSpan() << "\n";
	std::cout << "longest span: " << c.longestSpan() << "\n";

	Span d(3);
	try
	{
		d.addRange(big.getVec().begin(), big.getVec().end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	//trying add range with different type of iterator (list)
	std::list<int> li;
	for (int i = 0; i < 15000; i++)
		li.push_back(i);

	Span e(20000);
	try{
		e.addRange(li.begin(), li.end());
		std::cout << "shortest span: " << e.shortestSpan() << "\n";
		std::cout << "longest span: " << e.longestSpan() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}